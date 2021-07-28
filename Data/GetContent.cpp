//
// Created by Benjamin on 27/07/2021.
//

#include "GetContent.hpp"

GetContent::GetContent(std::string  Name):FileName(std::move(Name)) {
}

void GetContent::Read() {
    bool data = false;
    while(std::getline(Data,ReadLine,'\n')){
        auto len = ReadLine.length();
        if(ReadLine.find(':')<len && ReadLine.find('{')<len) data=true;
        else if(ReadLine.find('}')<len) data=false;
        else if(data ) File<<ReadLine<<std::endl;
    }
}

std::vector<std::string> GetContent::explode(const std::string &stringtosplit, const char &c) {
    std::string buff;
    std::vector<std::string> Res;

    for (auto stringitem:stringtosplit) {
        if (stringitem != c) buff += stringitem;
        else if (stringitem == c && !buff.empty()) {
            Res.push_back(buff);
            buff = "";
        }
    }
    if (!buff.empty()) Res.push_back(buff);
    return Res;
}

GetContent::~GetContent() = default;



void GetContent::MakeTable() {
    std::string Fields = DeleteSpaces(File.str());
    auto FieldVector = explode(Fields,',');
    for(auto&item : FieldVector){
        auto Keys = explode(item,':');
        Table.emplace_back(std::make_pair(Keys[0],Keys[1]));
    }
}

std::string GetContent::DeleteSpaces(const std::string &String) {
    std::string Res;
    for(auto& ch : String){
        if(ch!='\t' && ch!=' '&& ch!='\"'&&ch!='\n') Res+=ch;
    }
    return Res;
}

table GetContent::Get() {
    Table.clear();
    File.str("");
    Data.open(FileName);
    this->Read();
    this->MakeTable();
    Data.close();
    return Table;
}


