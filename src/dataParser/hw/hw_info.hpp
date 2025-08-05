#ifndef MEM_INFO_HPP
#define MEM_INFO_HPP

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "support/tools.hpp"

std::unordered_map<std::string, std::string> get_lscpu(); //                        lscpu
std::vector<std::unordered_map<std::string, std::string>> get_cpu_info(); //        /proc/cpuinfo

std::unordered_map<std::string, std::string> get_memory(); //   /proc/meminfo 

#endif