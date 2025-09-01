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


#ifndef BINARYWIDGET_H
#define BINARYWIDGET_H

#include <QWidget>
#include <vector>
#include <QColor>

/**
 * @class BinaryWidget
 * @brief Widget personnalisé pour afficher un message binaire sous forme de grille de cercles.
 *
 * Chaque bit est représenté par un cercle coloré ou vide selon sa valeur (1 ou 0).
 * Le widget permet de définir une couleur de fond et d'afficher dynamiquement une séquence binaire.
 */
class BinaryWidget : public QWidget {
    Q_OBJECT

private:
    std::vector<bool> bitSet;      /**< Ensemble de bits à afficher */
    QColor painterColor;           /**< Couleur des cercles actifs (bits à 1) */
    QColor nullColor;              /**< Couleur des cercles inactifs (bits à 0) */
    QColor background;             /**< Couleur de fond */

public:
    /**
     * @brief Constructeur du widget BinaryWidget.
     * @param parent Le widget parent (par défaut nullptr)
     */
    explicit BinaryWidget(QWidget *parent = nullptr);

    /**
     * @brief Met à jour la séquence de bits affichée.
     * @param b Vecteur de booléens représentant les bits (true = 1, false = 0)
     */
    void updateBitSet(const std::vector<bool> &b);


    void setColor(const QColor &color);

    void setNullColor(const QColor &color);

    void setBackGround(const QColor &color);

protected:
    /**
     * @brief Redéfinit l'événement de peinture pour afficher les bits.
     * @param event Pointeur vers l'événement de peinture
     */
    void paintEvent(QPaintEvent *event) override;
};

#endif // BINARYWIDGET_H
