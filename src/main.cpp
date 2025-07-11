#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "support/tools.hpp"

#include "dataParser/os/os_info.hpp"

// deprecated
// #include "support-d/tools.hpp"
// #include "support-d/report.hpp"

int main(int argc, char** argv){
    
    std::unordered_map<std::string, std::string> os_map = get_os_release();
    std::cout << "OS Name: " << os_map["PRETTY_NAME"] << "\n";
    std::cout << "OS Type: " << os_map["BUILD_ID"] << "\n";
    //std::cout << "OS Name: " << os_map["NAME"] << "\n";

    return 0;
}

