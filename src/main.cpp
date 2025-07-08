#include <iostream>
#include <fstream>
#include "support/tools.hpp"
#include "support/report.hpp"

int main(int argc, char** argv){
    
    report info = report();
    info.steal();
    info.printConsole();
    
    return 0;
}

