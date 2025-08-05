
#ifndef SYS_INFO_HPP
#define SYS_INFO_HPP

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>

#include "support/tools.hpp"

std::unordered_map<std::string, std::string> get_os_release(); //   /etc/os-release

#endif