//
// Created by Benjamin on 28/07/2021.
//

#include "Controller.hpp"

Controller::Controller() {
    Model = new GetContent("data.json");
}

Controller::~Controller() {
    delete Model;
}

void Controller::Run() {
    auto Table = Model->Get();
    Vue::Show(name,Table);

}

void Controller::NewName(const std::string &Name, const std::string& Path = R"(D:\CPP\APINationalizeio\cmake-build-debug)") {
    name = Name;
    CallScript(Name,Path);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Controller::CallScript(const std::string& Name, const std::string& Path ){

    const std::string Script = ".\\Request.ps1";
    const std::string Args = " -Name "+Name;
    const std::string command = "start powershell.exe cd "+Path +";"+Script+Args;
    system(command.c_str());
}

void Controller::Run(const std::string &Name) {
    NewName(Name);
    auto Table = Model->Get();
    Vue::Show(name,Table);
}
