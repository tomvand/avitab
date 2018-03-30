/*
 *   AviTab - Aviator's Virtual Tablet
 *   Copyright (C) 2018 Folke Will <folko@solhost.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Affero General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Affero General Public License for more details.
 *
 *   You should have received a copy of the GNU Affero General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <memory>
#include <thread>
#include <chrono>
#include "src/environment/standalone/StandAloneEnvironment.h"
#include "src/avitab/AviTab.h"
#include "src/Logger.h"

int main() {
    logger::init();

    std::shared_ptr<avitab::StandAloneEnvironment> env = std::make_shared<avitab::StandAloneEnvironment>();
    avitab::AviTab aviTab(env);

    aviTab.enable();
    aviTab.showTablet();
    env->eventLoop();

    return 0;
}

#ifdef _WIN32
#include <windows.h>

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}
#endif
