#include "sys_info.hpp"

std::unordered_map<std::string, std::string> get_os_release(){
    return fileToUMapGeneric("/etc/os-release", '=');
}