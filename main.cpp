#include <iostream>
#include "Controller.hpp"

void NameInput(Controller * controller,bool Same = false){

    if(!Same) {
        std::string Name;
        std::cout << "Name : ?" << std::endl;
        std::cin >> Name;
        controller->Run(Name);
    }
    else controller->Run();

}


int main(){
    auto controller = new Controller();
    bool Same = false;
    bool Run = true;
    while(Run) {
        NameInput(controller,Same);
        int Choice;

        std::cout << "Stop ? : 0" << std::endl;
        std::cout << "New Name ? : 1" << std::endl;
        std::cout<< "Same Name ? : 2" <<std::endl;
        std::cin >> Choice;
        if(Choice==0) Run = false;
        else if(Choice==2) {std::cout<<std::endl<<std::endl;Same = true;}
        else Same=false;
    }
    delete controller;
    return EXIT_SUCCESS;
}
