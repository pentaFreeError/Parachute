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


#ifndef MESSAGEENCODER_H
#define MESSAGEENCODER_H

#include <vector>
#include <QString>
#include <QChar>

/**
 * @class MessageEncoder
 * @brief Classe utilitaire pour l'encodage de messages texte en binaire.
 *
 * Cette classe fournit une méthode statique permettant de convertir
 * une chaîne de caractères en une représentation binaire.
 */
class MessageEncoder {
public:
    /**
     * @brief Encode un message texte en une séquence binaire.
     *
     * Chaque caractère du message est converti en sa valeur ASCII,
     * ajustée (caractère - 64), puis traduite en 7 bits binaires.
     *
     * @param message Le message à encoder (QString)
     * @return Vecteur d'entiers contenant les bits (0 ou 1)
     */
    static std::vector<int> encodeMessage(const QString &message, QChar offsetChar);
};

#endif // MESSAGEENCODER_H
