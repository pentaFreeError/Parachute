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



#include "view/ParachuteView.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFileDialog>
#include <cmath>

ParachuteView::ParachuteView(QWidget *parent)
    : QWidget(parent), sectors(7), tracks(5), parachuteColor(QColor("#5e9bff")), parachuteNullColor(QColor("#ffffff")), background(QColor("#1e1e1e")) {}

void ParachuteView::setParachuteData(int sectors, int tracks, const std::vector<int>& encodedMessage) {
    this->sectors = sectors;
    this->tracks = tracks;
    this->encodedMessage = encodedMessage;
    update();
}

void ParachuteView::setParachuteColor(QColor color) {
    parachuteColor = color;
    update();
}

void ParachuteView::setNullColor(QColor color) {
    parachuteNullColor = color;
    update();
}

void ParachuteView::setBackGround(const QColor &color) {
    background = color;
    update();
}


void ParachuteView::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), background);

    const int cx = width() / 2;
    const int cy = height() / 2;

    double outerCircle = std::min(width(), height()) / 2.2;
    double ringThickness = outerCircle / tracks;
    double angleIncrement = 2 * M_PI / sectors;

    QBrush emptyBrush(parachuteNullColor);
    QBrush activeBrush(parachuteColor);
    QPen edgePen(Qt::black);
    edgePen.setWidth(1);

    painter.setPen(edgePen);

    int bitIndex = 0;

    for (int ring = 0; ring < tracks; ++ring) {
        double rInner = ring * ringThickness;
        double rOuter = (ring + 1) * ringThickness;

        for (int slice = 0; slice < sectors; ++slice) {
            if (bitIndex >= static_cast<int>(encodedMessage.size()))
                break;

            double a1 = slice * angleIncrement;
            double a2 = (slice + 1) * angleIncrement;

            QPointF inner1(cx + rInner * std::cos(a1), cy + rInner * std::sin(a1));
            QPointF inner2(cx + rInner * std::cos(a2), cy + rInner * std::sin(a2));
            QPointF outer1(cx + rOuter * std::cos(a1), cy + rOuter * std::sin(a1));
            QPointF outer2(cx + rOuter * std::cos(a2), cy + rOuter * std::sin(a2));

            QPolygonF sliceShape;
            sliceShape << inner1 << inner2 << outer2 << outer1;

            painter.setBrush(encodedMessage[bitIndex] ? activeBrush : emptyBrush);
            painter.drawPolygon(sliceShape);

            ++bitIndex;
        }
    }
}
