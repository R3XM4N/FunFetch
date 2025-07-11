#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

//  STRUCTS FUNCTIONS

struct string2
{
    std::string x;
    std::string y;
};

//  STRING FUNCTIONS

void convertToLower(std::string &str);
std::string toLowerString(std::string str);

void cutAfterChar(std::string &str, char c);
void cutBeforeChar(std::string &str, char c);
std::string afterCharString(std::string str, char c);

void trimChar(std::string &str, char c);

string2 splitStringAtChar(std::string str, char c);

//  DATA PROCESS FUNCTIONS

std::unordered_map<std::string, std::string> fileToUMapGeneric(std::string file_path, char split_on); 

#endif