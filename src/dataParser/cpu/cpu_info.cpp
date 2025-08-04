#include "cpu_info.hpp"

std::unordered_map<std::string, std::string> get_lscpu(){
    return cmdToUMapGeneric("lscpu", ':');
}