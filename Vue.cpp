//
// Created by Benjamin on 28/07/2021.
//

#include "Vue.hpp"



void Vue::Show(const std::string& Name,const table& Table) {
    std::cout<<std::endl<<"Nationality predicition of "<<Name<<" :"<<std::endl;
    for(auto&pair:Table){
       std::cout<<pair.first<<" with a probability of "<<pair.second<<std::endl;
    }
    std::cout<<std::endl;
}
