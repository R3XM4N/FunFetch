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

#include "tools.hpp"

struct os
{
    std::string id;
    std::string name;
    std::string type;
};

struct cpu
{
    std::string vendor_id;
    std::string model_name; 
    short int threads;
    short int cores;
};


class report
{
private:
    os system;
    cpu cpu_info;
    int os_package_count = -1;
    int flatpak_package_count = -1;
    int snap_package_count = -1;

    void findOs();
    void getPackages();
    void getCpu();
public:
    void steal();
    void printConsole();
    report(/* args */);
    ~report();
};

#endif