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
#ifndef SRC_ENVIRONMENT_STANDALONE_STANDALONEENVIRONMENT_H_
#define SRC_ENVIRONMENT_STANDALONE_STANDALONEENVIRONMENT_H_

#include <memory>
#include "src/environment/Environment.h"
#include "SDLGUIDriver.h"

namespace avitab {

class StandAloneEnvironment: public Environment {
public:
    StandAloneEnvironment();
    void eventLoop();

    std::shared_ptr<GUILibrary> createWindow(const std::string &title) override;
    void createMenu(const std::string &name) override;
    void addMenuEntry(const std::string &label, std::function<void()> cb) override;
private:
    std::shared_ptr<SDLGUIDriver> driver;
};

} /* namespace avitab */

#endif /* SRC_ENVIRONMENT_STANDALONE_STANDALONEENVIRONMENT_H_ */
