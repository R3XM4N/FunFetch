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

void cutLeadingChar(std::string &str, char c){
    unsigned short int position = 0;
    while (position < str.length())
    {
        if (str[position] != c) break;
        position++;
    }
    str = str.substr(position);  
}

void cutTrailingChar(std::string &str, char c){
    unsigned int position = str.length() - 1;
    while (position > 0)
    {
        if (str[position] != c) break;
        position--;
    }
    if (str.length() - 1 == position) return;
    
    str = str.substr(0, position + 1);  
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

string2 splitStringAtChar(std::string str, char c){
    std::string front;
    std::string back;
    unsigned short int i = 0;
    while (str[i] != c && !(str.size() - 1 < i))
    {
        front += str[i];
        i++;
    }
    i++;
    while (!(str.size() - 1 < i))
    {
        back += str[i];
        i++;
    }   
    cutLeadingChar(back, ' ');
    return {front, back};
}

std::unordered_map<std::string, std::string> fileToUMapGeneric(std::string file_path, char split_on){
    std::unordered_map<std::string, std::string> u_map;

    //std::ifstream input("/etc/os-release");
    std::ifstream input(file_path);
    if (!input) {std::cerr << "File at path \"" << file_path << "\" could not be opened." << "\n";}
        
    std::string line;
    line.reserve(1024);

    while (std::getline(input, line)){
        string2 split;
        split = splitStringAtChar(line, split_on);

        u_map[split.x] = split.y;
    }
    
    return u_map;
}
std::unordered_map<std::string, std::string> cmdToUMapGeneric(std::string cmd, char split_on){
    std::unordered_map<std::string, std::string> u_map;
    std::string data = executeCommand(cmd);
    
    std::istringstream iss(data);
    std::string line;
    line.reserve(1024);

    while (std::getline(iss, line)){
        string2 split;
        split = splitStringAtChar(line, split_on);

        u_map[split.x] = split.y;
    }
    
    return u_map;
}

std::string executeCommand(std::string command){
    char* buffer = new char[4096];
    std::string ret_value;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) { delete[] buffer; return "COMMAND NONE (!pipe)";}
    
    while (fgets(buffer, 4096, pipe))
    {
        ret_value += buffer;
    }
    
    pclose(pipe);
    delete[] buffer;
    return ret_value;
}
