#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>


class BitcoinExchange
{
private:
    std::map<std::string,float> btcValue;
public:
    BitcoinExchange(void);
    BitcoinExchange(const char *d);
    ~BitcoinExchange();
    BitcoinExchange &operator=(BitcoinExchange const &target);
};


#endif