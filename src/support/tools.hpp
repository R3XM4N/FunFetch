#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>

//  STRUCTS DEFINITIONS

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
void cutLeadingChar(std::string &str, char c);
std::string afterCharString(std::string str, char c);

void trimChar(std::string &str, char c);

string2 splitStringAtChar(std::string str, char c);

//  DATA PROCESS FUNCTIONS

/// @brief Simple parser from a file that splits lines on a set character
/// @param file_path path to the file
/// @param split_on character to split on
std::unordered_map<std::string, std::string> fileToUMapGeneric(std::string file_path, char split_on);
/// @brief Simple parser from a command that splits lines on a set character
/// @param cmd command that outputs the data
/// @param split_on character to split on 
std::unordered_map<std::string, std::string> cmdToUMapGeneric(std::string cmd, char split_on); 

std::string executeCommand(std::string command);
std::string readFile(std::string file_path);

#endif