/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *saveAction;
    QAction *openAction;
    QAction *actionEnglish;
    QAction *actionfrensh;
    QAction *actionDarkMode;
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *messageLayout;
    QLineEdit *messageInput;
    QPushButton *randomButton;
    QHBoxLayout *sectorsRow;
    QLabel *labelSectors;
    QSlider *sliderSectors;
    QSpinBox *spinSectors;
    QHBoxLayout *tracksRow;
    QLabel *labelTracks;
    QSlider *sliderTracks;
    QSpinBox *spinTracks;
    QPushButton *colorButton1;
    QPushButton *colorButton2;
    QPushButton *colorRandomButton;
    QHBoxLayout *offsetLayout;
    QLabel *labelOffsetChar;
    QComboBox *comboOffsetChar;
    QVBoxLayout *rightLayout;
    QWidget *parachuteViewTab;
    QWidget *binaryViewTab;
    QVBoxLayout *binaryLayout;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *languageMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 700);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionfrensh = new QAction(MainWindow);
        actionfrensh->setObjectName(QString::fromUtf8("actionfrensh"));
        actionDarkMode = new QAction(MainWindow);
        actionDarkMode->setObjectName(QString::fromUtf8("actionDarkMode"));
        actionDarkMode->setCheckable(true);
        actionDarkMode->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(0);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        messageLayout = new QHBoxLayout();
        messageLayout->setSpacing(8);
        messageLayout->setObjectName(QString::fromUtf8("messageLayout"));
        messageInput = new QLineEdit(centralwidget);
        messageInput->setObjectName(QString::fromUtf8("messageInput"));

        messageLayout->addWidget(messageInput);

        randomButton = new QPushButton(centralwidget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));

        messageLayout->addWidget(randomButton);


        leftLayout->addLayout(messageLayout);

        sectorsRow = new QHBoxLayout();
        sectorsRow->setSpacing(4);
        sectorsRow->setObjectName(QString::fromUtf8("sectorsRow"));
        labelSectors = new QLabel(centralwidget);
        labelSectors->setObjectName(QString::fromUtf8("labelSectors"));
        labelSectors->setStyleSheet(QString::fromUtf8("margin: 0px; padding: 0px;"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSectors->sizePolicy().hasHeightForWidth());
        labelSectors->setSizePolicy(sizePolicy);

        sectorsRow->addWidget(labelSectors);

        sliderSectors = new QSlider(centralwidget);
        sliderSectors->setObjectName(QString::fromUtf8("sliderSectors"));
        sliderSectors->setOrientation(Qt::Horizontal);

        sectorsRow->addWidget(sliderSectors);

        spinSectors = new QSpinBox(centralwidget);
        spinSectors->setObjectName(QString::fromUtf8("spinSectors"));
        spinSectors->setMinimumSize(QSize(60, 0));

        sectorsRow->addWidget(spinSectors);


        leftLayout->addLayout(sectorsRow);

        tracksRow = new QHBoxLayout();
        tracksRow->setSpacing(4);
        tracksRow->setObjectName(QString::fromUtf8("tracksRow"));
        labelTracks = new QLabel(centralwidget);
        labelTracks->setObjectName(QString::fromUtf8("labelTracks"));
        labelTracks->setStyleSheet(QString::fromUtf8("margin: 0px; padding: 0px;"));
        sizePolicy.setHeightForWidth(labelTracks->sizePolicy().hasHeightForWidth());
        labelTracks->setSizePolicy(sizePolicy);

        tracksRow->addWidget(labelTracks);

        sliderTracks = new QSlider(centralwidget);
        sliderTracks->setObjectName(QString::fromUtf8("sliderTracks"));
        sliderTracks->setOrientation(Qt::Horizontal);

        tracksRow->addWidget(sliderTracks);

        spinTracks = new QSpinBox(centralwidget);
        spinTracks->setObjectName(QString::fromUtf8("spinTracks"));
        spinTracks->setMinimumSize(QSize(60, 0));

        tracksRow->addWidget(spinTracks);


        leftLayout->addLayout(tracksRow);

        colorButton1 = new QPushButton(centralwidget);
        colorButton1->setObjectName(QString::fromUtf8("colorButton1"));

        leftLayout->addWidget(colorButton1);

        colorButton2 = new QPushButton(centralwidget);
        colorButton2->setObjectName(QString::fromUtf8("colorButton2"));

        leftLayout->addWidget(colorButton2);

        colorRandomButton = new QPushButton(centralwidget);
        colorRandomButton->setObjectName(QString::fromUtf8("colorRandomButton"));

        leftLayout->addWidget(colorRandomButton);

        offsetLayout = new QHBoxLayout();
        offsetLayout->setObjectName(QString::fromUtf8("offsetLayout"));
        labelOffsetChar = new QLabel(centralwidget);
        labelOffsetChar->setObjectName(QString::fromUtf8("labelOffsetChar"));

        offsetLayout->addWidget(labelOffsetChar);

        comboOffsetChar = new QComboBox(centralwidget);
        comboOffsetChar->setObjectName(QString::fromUtf8("comboOffsetChar"));

        offsetLayout->addWidget(comboOffsetChar);


        leftLayout->addLayout(offsetLayout);


        mainLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        parachuteViewTab = new QWidget(centralwidget);
        parachuteViewTab->setObjectName(QString::fromUtf8("parachuteViewTab"));
        parachuteViewTab->setMinimumSize(QSize(0, 0));

        rightLayout->addWidget(parachuteViewTab);

        binaryViewTab = new QWidget(centralwidget);
        binaryViewTab->setObjectName(QString::fromUtf8("binaryViewTab"));
        binaryViewTab->setMinimumSize(QSize(0, 0));
        binaryLayout = new QVBoxLayout(binaryViewTab);
        binaryLayout->setObjectName(QString::fromUtf8("binaryLayout"));
        binaryLayout->setContentsMargins(0, 0, 0, 0);

        rightLayout->addWidget(binaryViewTab);


        mainLayout->addLayout(rightLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        viewMenu = new QMenu(menubar);
        viewMenu->setObjectName(QString::fromUtf8("viewMenu"));
        languageMenu = new QMenu(menubar);
        languageMenu->setObjectName(QString::fromUtf8("languageMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(languageMenu->menuAction());
        menubar->addAction(viewMenu->menuAction());
        fileMenu->addAction(openAction);
        fileMenu->addAction(saveAction);
        viewMenu->addAction(actionDarkMode);
        languageMenu->addAction(actionEnglish);
        languageMenu->addAction(actionfrensh);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Parachute Encoder", nullptr));
        saveAction->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        openAction->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionfrensh->setText(QCoreApplication::translate("MainWindow", "French", nullptr));
        actionDarkMode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        randomButton->setText(QCoreApplication::translate("MainWindow", "RANDOM", nullptr));
        labelSectors->setText(QCoreApplication::translate("MainWindow", "Sectors:", nullptr));
        labelTracks->setText(QCoreApplication::translate("MainWindow", "Rings :", nullptr));
        colorButton1->setText(QCoreApplication::translate("MainWindow", "Choose Color (The 1 bits)", nullptr));
        colorButton2->setText(QCoreApplication::translate("MainWindow", "Choose Color (The 0 bits)", nullptr));
        colorRandomButton->setText(QCoreApplication::translate("MainWindow", "Random Colors", nullptr));
        labelOffsetChar->setText(QCoreApplication::translate("MainWindow", "Offset Char:", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        viewMenu->setTitle(QCoreApplication::translate("MainWindow", "&View", nullptr));
        languageMenu->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
