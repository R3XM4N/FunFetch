#include "tools.hpp"

void convertToLower(std::string &str){
    if (str.empty()) return;

    std::string temporary;
    for (size_t i = 0; i < str.size(); i++)
    {
        str[i] = static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
    }
}

std::string toLowerString(std::string str){
    convertToLower(str);
    return str;
}

void cutBeforeChar(std::string &str, char c){
    auto position = str.find(c);
    if (position != std::string::npos && position + 1 < str.size())
    {
        str = str.substr(position + 1);
    }
}

void cutAfterChar(std::string &str, char c){
    auto position = str.find(c);
    if (position != std::string::npos && position + 1 < str.size())
    {
        str = str.substr(0, position + 1);
    }
}

std::string afterCharString(std::string str, char c){
    cutBeforeChar(str, c);
    return str;
}

std::string beforeCharString(std::string str, char c){
    cutAfterChar(str, c);
    return str;
}

void trimChar(std::string &str, char c){
    if (str.front() == c)
    {
        str.erase(str.begin(), str.begin() + 1);
    }
    if (str.back() == c)
    {
        str.pop_back();
    }
}