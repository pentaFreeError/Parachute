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


#ifndef PARACHUTEMODEL_H
#define PARACHUTEMODEL_H

#include <vector>

/**
 * @class ParachuteModel
 * @brief Modèle de données représentant un parachute encodé.
 *
 * Cette classe gère les paramètres d'un parachute (secteurs, pistes)
 * ainsi que le message encodé sous forme binaire.
 */
class ParachuteModel {
private:
    int sectors;                      /**< Nombre de secteurs dans le parachute */
    int tracks;                       /**< Nombre de pistes (tracks) */
    std::vector<int> encodedMessage;  /**< Message encodé sous forme de bits */

public:
    /**
     * @brief Constructeur de ParachuteModel.
     * @param sectors Nombre de secteurs (valeur par défaut : 7)
     * @param tracks Nombre de pistes (valeur par défaut : 5)
     */
    ParachuteModel(int sectors = 7, int tracks = 5);

    /**
     * @brief Définit le message à encoder.
     * @param message Vecteur d'entiers représentant le message binaire
     */
    void setMessage(const std::vector<int> &message);

    /**
     * @brief Modifie le nombre de secteurs.
     * @param s Nouveau nombre de secteurs
     */
    void setSectors(int s);

    /**
     * @brief Modifie le nombre de pistes.
     * @param t Nouveau nombre de pistes
     */
    void setTracks(int t);

    /**
     * @brief Retourne le nombre actuel de secteurs.
     * @return Nombre de secteurs
     */
    int getSectors() const;

    /**
     * @brief Retourne le nombre actuel de pistes.
     * @return Nombre de pistes
     */
    int getTracks() const;

    /**
     * @brief Retourne le message encodé.
     * @return Vecteur d'entiers représentant le message encodé
     */
    std::vector<int> getEncodedMessage() const;
};

#endif // PARACHUTEMODEL_H
