#ifndef REPORT_HPP
#define REPORT_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <cstdio> 
#include <array>

#include <sys/sysinfo.h>
#include <unistd.h>

#include "stringa.hpp"

struct os
{
    std::string id;
    std::string name;
    std::string type;
};


class report
{
private:
    os system;
    int os_package_count = -1;
    int flatpak_package_count = -1;
    int snap_package_count = -1;

    void findOs();
    void getPackages();
public:
    void steal();
    void printConsole();
    report(/* args */);
    ~report();
};

#endif