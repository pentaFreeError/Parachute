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


#ifndef PARACHUTEVIEW_H
#define PARACHUTEVIEW_H

#include <QWidget>
#include <vector>
#include <QColor>

/**
 * @class ParachuteView
 * @brief Widget personnalisé pour afficher un message binaire sous forme de secteurs et de pistes.
 *
 * Ce widget représente les données binaires encodées visuellement sous forme de "tranches de parachute".
 * Chaque bit est affiché sous forme de secteur dans une structure circulaire composée de pistes (anneaux)
 * et de secteurs (divisions angulaires).
 */
class ParachuteView : public QWidget {
    Q_OBJECT

private:
    int sectors;                           /**< Nombre de secteurs angulaires dans la vue */
    int tracks;                            /**< Nombre d'anneaux (pistes circulaires) */
    std::vector<int> encodedMessage;       /**< Message encodé à afficher (vecteur de bits) */
    QColor parachuteColor;                 /**< Couleur utilisée pour représenter les bits à 1 */
    QColor parachuteNullColor;             /**< Couleur utilisée pour représenter les bits à 0 */
    QColor background;                     /**< Couleur de fond */

public:
    /**
     * @brief Constructeur de ParachuteView.
     * @param parent Widget parent (par défaut nullptr)
     */
    explicit ParachuteView(QWidget *parent = nullptr);

    /**
     * @brief Définit les données à afficher dans la vue.
     * @param sectors Nombre de secteurs
     * @param tracks Nombre de pistes
     * @param encodedMessage Vecteur contenant les bits encodés
     */
    void setParachuteData(int sectors, int tracks, const std::vector<int>& encodedMessage);

    /**
     * @brief Change la couleur d'affichage des bits actifs.
     * @param color Nouvelle couleur du parachute
     */
    void setParachuteColor(QColor color);

    void setNullColor(QColor color);

    void setBackGround(const QColor &color);

protected:
    /**
     * @brief Surcharge de l'événement de peinture pour dessiner la structure du parachute.
     * @param event Pointeur vers l'événement de peinture
     */
    void paintEvent(QPaintEvent *event) override;
};

#endif // PARACHUTEVIEW_H
