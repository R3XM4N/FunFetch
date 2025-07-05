#ifndef STRINGA_HPP
#define STRINGA_HPP
#include <string>

void convertToLower(std::string &str);
std::string toLowerString(std::string str);

void cutAfterChar(std::string &str, char c);
void cutBeforeChar(std::string &str, char c);
std::string afterCharString(std::string str, char c);

void trimChar(std::string &str, char c);

#endif