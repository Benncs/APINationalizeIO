//
// Created by Benjamin on 27/07/2021.
//

#ifndef APINATIONALIZEIO_GETCONTENT_HPP
#define APINATIONALIZEIO_GETCONTENT_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>


using table =  std::vector<std::pair<std::string,std::string>>;

class GetContent {
public:
    explicit GetContent(std::string  Name);
    ~GetContent();
    table Get();

private:
    std::string ReadLine;
    std::ifstream Data;
    std::stringstream File;
    table Table ;
    std::string FileName;
    void Read();
    static std::vector<std::string> explode(const std::string& stringtosplit, const char& c);
    void MakeTable();
    static std::string DeleteSpaces(const std::string& String);

};


#endif //APINATIONALIZEIO_GETCONTENT_HPP
