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





#include "presenter/ParachutePresenter.h"
#include "view/MainWindow.h"  


ParachutePresenter::ParachutePresenter(MainWindow *view) 
    : view(view) {}

void ParachutePresenter::updateSectors(int sectors) {
    model.setSectors(sectors);
}

void ParachutePresenter::updateTracks(int tracks) {
    model.setTracks(tracks);
}
