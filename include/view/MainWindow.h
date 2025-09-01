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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QChar>
#include "view/ParachuteView.h"
#include "view/BinaryWidget.h"
#include "model/LanguageManager.h" 


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui; 
    ParachuteView *parachuteView; 
    BinaryWidget *binaryWidget;   
    QColor bit1_color;
    QColor bit0_color;
    LanguageManager *languageManager; 
    bool random_flag;
    QChar encodeChar; 
    
private slots:
    void onMessageChanged();
    void onSaveFile();
    void onOpenFile();
    void onGenerateRandom();
    void onSectorsOrTracksChanged();
    void onLanguageEnglish();
    void onLanguageFrench();
    void retranslateUi();
    void on_colorButton2_clicked();
    void on_colorButton1_clicked();
    void on_colorRandomButton_clicked();
    void onDarkModeToggled(bool enabled);
    void onOffsetCharChanged(const QString &text);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QByteArray xorEncryptDecrypt(const QByteArray& data, const QByteArray& key);
};

#endif // MAINWINDOW_H