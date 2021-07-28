//
// Created by Benjamin on 28/07/2021.
//

#ifndef APINATIONALIZEIO_VUE_HPP
#define APINATIONALIZEIO_VUE_HPP

#include <iostream>
#include <vector>

using table =  std::vector<std::pair<std::string,std::string>>;

class Vue {
public:
    Vue() = default;
    static void Show(const std::string& Name,const table& Table);

private:

};


#endif //APINATIONALIZEIO_VUE_HPP
