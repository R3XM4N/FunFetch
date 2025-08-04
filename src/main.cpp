#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "support/tools.hpp"
#include "dataParser/os/os_info.hpp"
#include "dataParser/cpu/cpu_info.hpp"

// deprecated
// #include "support-d/tools.hpp"
// #include "support-d/report.hpp"

int main(int argc, char** argv){
    
    std::unordered_map<std::string, std::string> os_map = get_os_release();
    std::unordered_map<std::string, std::string> lscpu = get_lscpu();

    std::cout << "OS:\n"; 
    std::cout << "  Name:               " << os_map["PRETTY_NAME"] << "\n";
    std::cout << "  Type:               " << os_map["BUILD_ID"] << "\n";
    //std::cout << "OS Name: " << os_map["NAME"] << "\n";

    std::cout << "CPU:\n"; 
    std::cout << "  Model name:         " << lscpu["Model name"] << "\n";
    std::cout << "  Architecture:       " << lscpu["Architecture"] << "\n";
    std::cout << "  \"CPU's\":            " << lscpu["CPU(s)"] << "\n";

    
    return 0;
}

