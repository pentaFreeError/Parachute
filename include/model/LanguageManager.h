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




#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QObject>
#include <QTranslator>
#include <QApplication>

/**
 * @class LanguageManager
 * @brief Classe responsable de la gestion de la langue de l'application.
 *
 * Elle permet de changer dynamiquement la langue de l'interface en utilisant
 * un fichier de traduction (`.qm`) et de notifier les composants de l'application
 * du changement de langue via un signal.
 */
class LanguageManager : public QObject {
    Q_OBJECT

private:
    QTranslator translator;      /**< Objet responsable du chargement des traductions */
    QString currentLanguage;     /**< Code de la langue actuellement utilisée (ex: "en", "fr") */

signals:
    /**
     * @brief Signal émis lorsque la langue de l'application est changée.
     */
    void languageChanged();

public:
    /**
     * @brief Constructeur de LanguageManager.
     * @param parent Objet parent optionnel (par défaut nullptr)
     */
    explicit LanguageManager(QObject *parent = nullptr);

    /**
     * @brief Change la langue de l'application.
     * 
     * Cette méthode charge le fichier de traduction correspondant au code langue
     * et l'applique à l'application.
     *
     * @param languageCode Code de la langue à appliquer (ex: "en", "fr", "ar")
     */
    void switchLanguage(const QString &languageCode);

    /**
     * @brief Retourne le code de la langue actuellement active.
     * @return Code langue sous forme de QString
     */
    QString getCurrentLanguage() const;
};

#endif // LANGUAGEMANAGER_H
