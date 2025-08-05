#include "hw_info.hpp"


std::unordered_map<std::string, std::string> get_memory(){
    return fileToUMapGeneric("/proc/meminfo", ':');
}

std::unordered_map<std::string, std::string> get_lscpu(){
    return cmdToUMapGeneric("lscpu", ':');
}