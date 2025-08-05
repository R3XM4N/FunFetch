#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "support/tools.hpp"
#include "dataParser/hw/hw_info.hpp"
#include "dataParser/sys/sys_info.hpp"

int main(int argc, char** argv){
    {std::unordered_map<std::string, std::string> os_map = get_os_release();
    std::cout << "OS:\n"; 
    std::cout << "  Name:               " << os_map["PRETTY_NAME"] << "\n";
    std::cout << "  Type:               " << os_map["BUILD_ID"] << "\n";}

    {std::unordered_map<std::string, std::string> lscpu = get_lscpu();
    std::cout << "CPU:\n"; 
    std::cout << "  Model name:         " << lscpu["Model name"] << "\n";
    std::cout << "  Architecture:       " << lscpu["Architecture"] << "\n";
    std::cout << "  \"CPU's\":            " << lscpu["CPU(s)"] << "\n";}
    
    {std::unordered_map<std::string, std::string> memory = get_memory();
    std::cout << "MEMORY:\n"; 
    std::cout << "  Total memory:       " << memory["MemTotal"] << "\n";}


    //testy stuff
    {
    std::string ballz = readFile("/proc/uptime");
    cutAfterChar(ballz, ' ');
    std::cout << ballz << "\n";
    }
    std::cout << ":3\n";
    return 0;
}

