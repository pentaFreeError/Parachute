#ifndef PARACHUTEPRESENTER_H
#define PARACHUTEPRESENTER_H

#include "model/ParachuteModel.h"

class MainWindow;

/**
 * @class ParachutePresenter
 * @brief Classe intermédiaire entre la vue (MainWindow) et le modèle (ParachuteModel).
 *
 * Le rôle de ce presenter est de gérer la logique métier de l'application
 * en mettant à jour le modèle en fonction des interactions dans la vue.
 */
class ParachutePresenter {
private:
    ParachuteModel model;  /**< Modèle de données représentant le parachute */
    MainWindow *view;      /**< Pointeur vers la vue associée */

public:
    /**
     * @brief Constructeur explicite du presenter.
     * @param view Pointeur vers l'instance de la vue (MainWindow)
     */
    explicit ParachutePresenter(MainWindow *view);

    /**
     * @brief Met à jour le nombre de secteurs dans le modèle.
     * @param sectors Nouveau nombre de secteurs
     */
    void updateSectors(int sectors);

    /**
     * @brief Met à jour le nombre de pistes dans le modèle.
     * @param tracks Nouveau nombre de pistes
     */
    void updateTracks(int tracks);
};

#endif // PARACHUTEPRESENTER_H
