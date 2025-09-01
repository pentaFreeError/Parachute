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


#include "view/BinaryWidget.h"
#include <QPainter>
#include <algorithm>

BinaryWidget::BinaryWidget(QWidget *parent)
    : QWidget(parent), painterColor(QColor("#5e9bff")), nullColor(QColor("#1e1e1e")), background(QColor("#1e1e1e")) { // bleu clair
    bitSet = std::vector<bool>();
}

void BinaryWidget::updateBitSet(const std::vector<bool> &b) {
    bitSet = b;
    update();
}

void BinaryWidget::setColor(const QColor &color) {
    painterColor = color;
    update();
}

void BinaryWidget::setNullColor(const QColor &color) {
    nullColor = color;
    update();
}

void BinaryWidget::setBackGround(const QColor &color) {
    background = color;
    update();
}

void BinaryWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), background);

    QBrush activeBrush(painterColor);
    QBrush inactiveBrush(nullColor);

    int bitCount = static_cast<int>(bitSet.size());
    int symbols = std::max(1, bitCount / 7 + (bitCount % 7 ? 1 : 0));
    int bitsPerSymbol = 7;

    int w = std::max(1, width() / symbols);
    int h = std::max(1, height() / bitsPerSymbol);
    int box = std::min(w, h);
    int dot = static_cast<int>(box * 0.8);

    int fullWidth = symbols * box;
    int fullHeight = bitsPerSymbol * box;
    int originX = (width() - fullWidth) / 2;
    int originY = (height() - fullHeight) / 2;

    for (int col = 0; col < symbols; ++col) {
        for (int row = 0; row < bitsPerSymbol; ++row) {
            int idx = col * bitsPerSymbol + row;
            if (idx < bitCount) {
                painter.setBrush(bitSet.at(idx) ? activeBrush : inactiveBrush);
                int cx = originX + col * box + (box - dot) / 2;
                int cy = originY + row * box + (box - dot) / 2;
                painter.drawEllipse(cx, cy, dot, dot);
            }
        }
    }
}
