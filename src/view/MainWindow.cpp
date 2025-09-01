/*
 * Copyright (C) 2025 Kalash Abdulaziz 
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Kalash Abdulaziz
 * @version 1.0
 * @date 2025
 */


#include "view/MainWindow.h"
#include "view/ui_MainWindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
#include <QDateTime>
#include <QRandomGenerator>
#include <QByteArray>
#include <QString>
#include <QShortcut>
#include <QColorDialog>
#include <QComboBox>


#include "model/MessageEncoder.h"
#include "view/ParachuteView.h"
#include "view/BinaryWidget.h"
#include "model/LanguageManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), languageManager(new LanguageManager(this)) {
    
    ui->setupUi(this);

    random_flag = false;
    encodeChar = '@';

    qApp->setStyleSheet(R"(
    QMainWindow, QWidget {
        background-color: #1e1e1e;
        color: #f0f0f0;
        font-family: "Segoe UI", "Arial", sans-serif;
        font-size: 11pt;
    }

    QLineEdit, QSpinBox {
        background-color: #2c2c2c;
        color: #f0f0f0;
        border: 1px solid #444;
        padding: 4px;
        border-radius: 3px;
    }

    QSlider::groove:horizontal {
        height: 6px;
        background: #444;
        border-radius: 3px;
    }

    QSlider::handle:horizontal {
        background: #5e9bff;
        width: 14px;
        margin: -4px 0;
        border-radius: 7px;
    }

    QLabel {
        color: #f0f0f0;
        padding: 0px;
        margin: 0px;
    }

    QMenuBar, QMenu {
        background-color: #2c2c2c;
        color: #f0f0f0;
    }

    QMenu::item:selected {
        background-color: #3a3a3a;
    }

    QStatusBar {
        background-color: #2c2c2c;
        color: #999;
    }

    QTabWidget::pane {
        border: 1px solid #444;
    }

    QTabBar::tab {
        background: #2c2c2c;
        color: #ccc;
        padding: 6px;
    }

    QTabBar::tab:selected {
        background: #3a3a3a;
        color: #fff;
    }
)");

    bit1_color = QColor("#5e9bff");
    bit0_color = QColor("#1e1e1e");

    ui->mainLayout->setStretch(0, 2);  
    ui->mainLayout->setStretch(1, 8);  

    ui->rightLayout->setStretch(0, 6); 
    ui->rightLayout->setStretch(1, 3); 

    parachuteView = new ParachuteView(this);
    auto *parachuteLayout = new QVBoxLayout(ui->parachuteViewTab);
    parachuteLayout->addWidget(parachuteView);

    binaryWidget = new BinaryWidget(this);
    if (auto *layout = qobject_cast<QVBoxLayout *>(ui->binaryViewTab->layout())) {
        layout->addWidget(binaryWidget);
    }

    connect(ui->messageInput, &QLineEdit::textChanged, this, &MainWindow::onMessageChanged);

    ui->saveAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    ui->openAction->setShortcut(QKeySequence(Qt::ALT + Qt::Key_O));

    ui->sliderSectors->setRange(0, 13);
    ui->sliderSectors->setSingleStep(1); 

    ui->spinSectors->setRange(7, 98);
    ui->spinSectors->setSingleStep(7);

    connect(ui->sliderSectors, &QSlider::valueChanged, this, [=](int step)
            {
    int value = (step + 1) * 7;
    if (ui->spinSectors->value() != value)
        ui->spinSectors->setValue(value); });

    connect(ui->spinSectors, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value)
            {
    int clamped = qBound(7, value, 98);
    int rounded = (clamped / 7) * 7;
    if (clamped % 7 != 0)
        rounded += 7; 

    int step = (rounded / 7) - 1;
    if (ui->sliderSectors->value() != step)
        ui->sliderSectors->setValue(step);

    if (ui->spinSectors->value() != rounded)
        ui->spinSectors->setValue(rounded); });

    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::onSaveFile);
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::onOpenFile);

    connect(ui->sliderSectors, &QSlider::valueChanged, this, &MainWindow::onSectorsOrTracksChanged);

    connect(ui->sliderTracks, &QSlider::valueChanged, ui->spinTracks, &QSpinBox::setValue);
    connect(ui->spinTracks, QOverload<int>::of(&QSpinBox::valueChanged), ui->sliderTracks, &QSlider::setValue);
    connect(ui->sliderTracks, &QSlider::valueChanged, this, &MainWindow::onSectorsOrTracksChanged);

    connect(ui->randomButton, &QPushButton::clicked, this, &MainWindow::onGenerateRandom);

    ui->sliderTracks->setRange(1, 100);
    ui->spinTracks->setRange(1, 100);

    ui->sliderSectors->setValue(0);
    ui->sliderTracks->setValue(1);

    connect(ui->actionEnglish, &QAction::triggered, this, &MainWindow::onLanguageEnglish);
    connect(ui->actionfrensh, &QAction::triggered, this, &MainWindow::onLanguageFrench);
    connect(languageManager, &LanguageManager::languageChanged, this, &MainWindow::retranslateUi);

    const QString possibleCharacters = "@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";

    for (const QChar &ch : possibleCharacters) {
        ui->comboOffsetChar->addItem(QString(ch));
    }   
    QChar selectedChar = ui->comboOffsetChar->currentText().at(0);
    encodeChar = selectedChar;

    connect(ui->comboOffsetChar, &QComboBox::currentTextChanged, this, &MainWindow::onOffsetCharChanged);
    connect(ui->actionDarkMode, &QAction::toggled, this, &MainWindow::onDarkModeToggled);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onOffsetCharChanged(const QString &text) {
    encodeChar = text.at(0);
    onMessageChanged();
}

void MainWindow::onDarkModeToggled(bool enabled)
{
    if (enabled) {
    qApp->setStyleSheet(R"(
    QMainWindow, QWidget {
        background-color: #1e1e1e;
        color: #f0f0f0;
        font-family: "Segoe UI", "Arial", sans-serif;
        font-size: 11pt;
    }

    QLineEdit, QSpinBox {
        background-color: #2c2c2c;
        color: #f0f0f0;
        border: 1px solid #444;
        padding: 4px;
        border-radius: 3px;
    }

    QSlider::groove:horizontal {
        height: 6px;
        background: #444;
        border-radius: 3px;
    }

    QSlider::handle:horizontal {
        background: #5e9bff;
        width: 14px;
        margin: -4px 0;
        border-radius: 7px;
    }

    QLabel {
        color: #f0f0f0;
        padding: 0px;
        margin: 0px;
    }

    QMenuBar, QMenu {
        background-color: #2c2c2c;
        color: #f0f0f0;
    }

    QMenu::item:selected {
        background-color: #3a3a3a;
    }

    QStatusBar {
        background-color: #2c2c2c;
        color: #999;
    }

    QTabWidget::pane {
        border: 1px solid #444;
    }

    QTabBar::tab {
        background: #2c2c2c;
        color: #ccc;
        padding: 6px;
    }

    QTabBar::tab:selected {
        background: #3a3a3a;
        color: #fff;
    }
)");
        binaryWidget->setBackGround(QColor("#1e1e1e"));
        parachuteView->setBackGround(QColor("#1e1e1e"));
    } else {
        qApp->setStyleSheet(""); 
        binaryWidget->setBackGround(QColor("#ffffff"));
        parachuteView->setBackGround(QColor("#ffffff"));
    }
}


QColor getRandomColor() {
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);
    return QColor(r, g, b);
}


void MainWindow::on_colorRandomButton_clicked() {
    QColor color1 = getRandomColor();
    QColor color2;

    do {
        color2 = getRandomColor();
    } while (color1 == color2); 


    bit1_color = color1;
    bit0_color = color2;

    parachuteView->setNullColor(bit0_color);
    binaryWidget->setNullColor(bit0_color);
    parachuteView->setParachuteColor(bit1_color);
    binaryWidget->setColor(bit1_color);
}

void MainWindow::on_colorButton1_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select a Color");
    if (color.isValid()) {
        bit1_color = color;
        parachuteView->setParachuteColor(color);
        binaryWidget->setColor(color);
    }
}

void MainWindow::on_colorButton2_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select a Color");
    if (color.isValid()) {
        bit0_color = color;
        parachuteView->setNullColor(color);
        binaryWidget->setNullColor(color);
    }
}

void MainWindow::onMessageChanged() {
    const QString inputText = ui->messageInput->text();
    if((inputText.size() > ui->spinSectors->value() * ui->spinTracks->value() / 7) && !random_flag) {
        QMessageBox::warning(this, "Message Length", "The message is too long for the current parachute size.");
        return;
    }
    auto binaryVector = MessageEncoder::encodeMessage(inputText, encodeChar);
    std::vector<bool> binaryBits(binaryVector.begin(), binaryVector.end());

    binaryWidget->updateBitSet(binaryBits);
    parachuteView->setParachuteData(ui->spinSectors->value(), ui->spinTracks->value(), binaryVector);
}

QByteArray MainWindow::xorEncryptDecrypt(const QByteArray& data, const QByteArray& key) {
    QByteArray result = data;
    for (int i = 0; i < result.size(); ++i) {
        result[i] = result[i] ^ key[i % key.size()];
    }
    return result;
}

void MainWindow::onSaveFile() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "", "Parachute Files (*.pf)");
    if (filePath.isEmpty()) return;

    if (!filePath.endsWith(".pf")) {
        filePath += ".pf";
    }

    const QByteArray encryptionKey = "X8z!aP@9dL#kR2q$V1c*M7e&T^bW0nGh";

    QByteArray content;
    QTextStream out(&content, QIODevice::WriteOnly);

    out << "[Metadata]\n";
    out << "Date=" << QDateTime::currentDateTime().toString(Qt::ISODate) << "\n";
    out << "Author=" << qgetenv("USER") << "\n";
    out << "AppVersion=1.0\n\n";

    out << "[Message]\n" << ui->messageInput->text() << "\n";
    out << "[Parameters]\n";
    out << "Sectors=" << ui->spinSectors->value() << "\n";
    out << "Tracks=" << ui->spinTracks->value() << "\n";
    out << "Language=" << languageManager->getCurrentLanguage() << "\n";
    out << "bit1_color=" << bit1_color.name() << "\n";
    out << "bit0_color=" << bit0_color.name() << "\n";
    out << "offsetChar=" << encodeChar << "\n";
    out << "backGround=" << ui->centralwidget->palette().color(QPalette::Window).name() << "\n";

    out.flush();

    QByteArray encryptedData = xorEncryptDecrypt(content, encryptionKey);

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(encryptedData);
        file.close();
        QMessageBox::information(this, "Save File", "File saved successfully.");
    } else {
        QMessageBox::warning(this, "Save File", "Unable to open file for writing.");
    }
}

void MainWindow::onOpenFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "Parachute Files (*.pf)");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Open File", "Unable to open file for reading.");
        return;
    }

    const QByteArray encryptionKey = "X8z!aP@9dL#kR2q$V1c*M7e&T^bW0nGh";

    QByteArray encryptedData = file.readAll();
    QByteArray decryptedData = xorEncryptDecrypt(encryptedData, encryptionKey);
    QTextStream stream(&decryptedData, QIODevice::ReadOnly);

    QString messageContent;
    int loadedSectors = 0, loadedTracks = 0;
    QString line;

    while (!stream.atEnd()) {
        line = stream.readLine().trimmed();

        if (line == "[Message]") {
            messageContent = stream.readLine().trimmed();
        } else if (line == "[Parameters]") {
            while (!stream.atEnd()) {
                QString paramLine = stream.readLine().trimmed();
                if (paramLine.startsWith('[')) break;
                if (paramLine.startsWith("Sectors="))
                    loadedSectors = paramLine.section('=', 1).toInt();
                else if (paramLine.startsWith("Tracks="))
                    loadedTracks = paramLine.section('=', 1).toInt();
                else if(paramLine.startsWith("Language=")) {
                    if (paramLine.section('=', 1) == "en") {
                        languageManager->switchLanguage("en");
                    } else if (paramLine.section('=', 1) == "fr") {
                        languageManager->switchLanguage("fr");
                    }
                }else if(paramLine.startsWith("bit1_color=")) {
                    bit1_color = QColor(paramLine.section('=', 1));
                } else if(paramLine.startsWith("bit0_color=")) {
                    bit0_color = QColor(paramLine.section('=', 1));
                } else if(paramLine.startsWith("offsetChar=")) {
                    encodeChar = paramLine.section('=', 1).at(0);
                } else if(paramLine.startsWith("backGround=")) {
                    if (paramLine.section('=', 1) == "#1e1e1e") {
                        onDarkModeToggled(true);
                    } else {
                        onDarkModeToggled(false);
                    }
                }
            } 
        }
    }

    ui->messageInput->setText(messageContent);
    ui->spinSectors->setValue(loadedSectors);
    ui->spinTracks->setValue(loadedTracks);
    parachuteView->setParachuteColor(bit1_color);
    parachuteView->setNullColor(bit0_color);
    binaryWidget->setColor(bit1_color);
    binaryWidget->setNullColor(bit0_color);
    ui->comboOffsetChar->setCurrentText(encodeChar);

    onSectorsOrTracksChanged();

    file.close();
    QMessageBox::information(this, "Open File", "File loaded successfully.");
}


void MainWindow::onGenerateRandom() {
    random_flag = true;
    const QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
    const int minLength = 5;
    const int maxLength = 30;
    int messageLength = QRandomGenerator::global()->bounded(minLength, maxLength + 1);

    QString randomMessage;
    for (int i = 0; i < messageLength; ++i) {
        QChar c = possibleCharacters.at(QRandomGenerator::global()->bounded(possibleCharacters.length()));
        randomMessage.append(c);
    }

    int requiredBits = messageLength * 7; 
    int sectors, tracks;

    do {
        sectors = QRandomGenerator::global()->bounded(5, 21);  
        tracks = QRandomGenerator::global()->bounded(5, 21);   
    } while (sectors * tracks < requiredBits);

    ui->messageInput->setText(randomMessage);
    ui->spinSectors->setValue(sectors);
    ui->spinTracks->setValue(tracks);
    onSectorsOrTracksChanged();

    QMessageBox::information(this, "Random Generation", "Random message and parameters generated successfully.");
    random_flag = false;
}


void MainWindow::onSectorsOrTracksChanged() {
    QString currentMessage = ui->messageInput->text();
    std::vector<int> data = MessageEncoder::encodeMessage(currentMessage, encodeChar);
    parachuteView->setParachuteData(ui->spinSectors->value(), ui->spinTracks->value(), data);
}

void MainWindow::onLanguageEnglish() {
    languageManager->switchLanguage("en");
}

void MainWindow::onLanguageFrench() {
    languageManager->switchLanguage("fr");
}

void MainWindow::retranslateUi() {
    ui->retranslateUi(this);
}
