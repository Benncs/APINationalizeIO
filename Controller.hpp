//
// Created by Benjamin on 28/07/2021.
//

#ifndef APINATIONALIZEIO_CONTROLLER_HPP
#define APINATIONALIZEIO_CONTROLLER_HPP

#include "Data/GetContent.hpp"
#include "Vue.hpp"
#include <chrono>
#include <thread>

using table =  std::vector<std::pair<std::string,std::string>>;

class Controller {
public:
    Controller();
    void Run();
    void Run(const std::string& Name);
    ~Controller();
    void NewName(const std::string& Name,const std::string& Path);
private:
    std::string name;
    GetContent *Model ;
    static void CallScript(const std::string& Name, const std::string& Path );
};


#endif //APINATIONALIZEIO_CONTROLLER_HPP
