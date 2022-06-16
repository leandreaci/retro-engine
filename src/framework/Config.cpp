//
// Created by leandro on 24/08/2021.
//

#include <fstream>
#include <iostream>
#include <string>
#include "Config.h"

void Config::load() {

    std::ifstream file;

    file.open(this->filename);

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
//            line.erase(std::remove_if(line.begin(), line.end(), isspace),
//                       line.end());
//            if (line.empty() || line[0] == '#') {
//                continue;
//            }
//            auto delimiterPos = line.find('=');
//            auto name = line.substr(0, delimiterPos);
//            auto value = line.substr(delimiterPos + 1);
//            this->options.insert({name, value});
        }

        file.close();
    }

}

int Config::getScreenWidth() {
    return 1280;
//    return stoi(this->options.find(this->SCREEN_WIDTH_KEY)->second);
}

int Config::getScreenHeight() {
    return 720;
//    return stoi(this->options.find(this->SCREEN_HEIGHT_KEY)->second);
}

int Config::getFps() {
    return 20;
//    return stoi(this->options.find(this->FPS)->second);
}

const char* Config::getName() {
    return "action_game";
//    return (this->options.find(this->NAME)->second).c_str();
}

int Config::getSprintWidth() {
    return 50;
//    return stoi(this->options.find(this->SPRINT_WIDTH)->second);
}

int Config::getSprintHeight() {
    return 50;
//    return stoi(this->options.find(this->SPRINT_HEIGHT)->second);
}




