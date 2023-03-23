#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> btcVal;
public:
    BitcoinExchange(void);
    BitcoinExchange(const char *d);
    BitcoinExchange(const BitcoinExchange &target);
    BitcoinExchange &operator=(const BitcoinExchange &target);
    ~BitcoinExchange();
    void output(const char *input);
    void printMap(void);
    void displayResults(std::string date, std::string value);

};

int checkLine(std::string line);

int     checkDate(std::string date);
void    dateError(std::string date);

int     dataValue(std::string v);
void    dataValueError(int flag);

int     checkValue(std::string val);
void    valueError(int flag);

#endif