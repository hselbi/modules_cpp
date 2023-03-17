#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "Contructor has been called!!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *d)
{
    std::string line;
    std::string date;
    std::string value;
    std::ifstream csv_data;
    csv_data.open(d, std::ios::in);
	if (!csv_data) {
		std::cout << "No such file" << std::endl;
        std::exit(0);
	}
    std::getline(csv_data, line);
    while(std::getline(csv_data, line))
    {
        // std::getline(csv_data, line);
        // std::cout << "date ==> " << date;
        // std::cout << "\t\tvalue = " << value << std::endl;

        date = line.substr(0, 10);
        if (checkDate(date))
            dateError(date);
        
        value = line.substr(11);
        // int f = checkValue(value);
        // if (f)
        //     valueError(f);
        this->btcVal[date] = std::stof(value);
        // 2022-01-30
        // std::cout << "date ==> " << date;
        // std::cout << "\t\tvalue = " << this->btcVal[date] << std::endl;

    }
    // std::cout << "Size of map: " << btcVal.size() << std::endl;
    
    csv_data.close();
}

void BitcoinExchange::printMap(void)
{
    std::map<std::string, float>::iterator it = btcVal.begin();

    while (it != btcVal.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }

}

void BitcoinExchange::output(const char *input)
{

    std::string tmp[2];
    std::string line;
    // std::string date;
    std::string value;
    std::ifstream inp;
    inp.open(input, std::ios::in);
    // std::cout << "date ==> 2011-01-03";
    std::cout << "value = " << btcVal["2013-08-04"] << std::endl;
    // printMap();
    if (!inp)
    {
        std::cerr << "No Input file" << std::endl;
        std::exit(1);
    }
    std::getline(inp, line);
    while(std::getline(inp, line))
    {
        std::istringstream iss(line);
        std::string token;
        int i = 0;
        while (std::getline(iss, token, '|'))
        {
            tmp[i] = token;
            i++;
        }
        // std::cout << "date ==> 2011-01-03";
        // std::cout << "\t\tvalue = " << this->btcVal["2011-01-03"] << std::endl;
    
        if (checkDate(tmp[0]))
            dateError(tmp[0]);

        int f = checkValue(tmp[1]);
        if (f)
            valueError(f);
        // const char *date = tmp[0].c_str();
        std::cout << "date ==> " << tmp[0] << std::endl;
        std::cout << this->btcVal[tmp[1]] << std::endl;
        // 2022-01-30

    }

}

int checkValue(std::string val)
{
    float nbr_float = std::stof(val);
    // std::cout << nbr_float << std::endl;
    if (nbr_float < 0.0)
        return 1;
    if (nbr_float > 1000.0)
        return 2;
    
    return 0;
}

void valueError(int flag)
{
    if (flag == 1)
        std::cerr << "Error: not a positive number." << std::endl;
    else if (flag == 2)
        std::cerr << "Error: too large a number." << std::endl;
    // std::exit(flag);
}


int    checkDate(std::string date)
{
    // std::cout << date << std::endl;
    std::string tmp[3];
    int year;
    int month;
    int day;
    std::istringstream iss(date);
    std::string token;
    int i = 0;
    while (std::getline(iss, token, '-'))
    {
        tmp[i] = token;
        i++;
    }
    char *end;
    int base = 10;
    year = std::strtol(tmp[0].c_str(), &end, base);
    if (year < 2009 && year > 2022)
        return 1;
    // {
    //     std::cout << "ERROR IN YEARS" << std::endl;
    //     std::exit(1);
    // }
    month = std::strtol(tmp[1].c_str(), &end, base);
    day = std::strtol(tmp[2].c_str(), &end, base);
    if (month == 2 && day > 29)
        return 1;
    // {
    //     std::cout << "ERROR IN MONTH 2!!!" << std::endl;
    //     std::exit(1);
    // }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 1;
    else
    {
        if (day > 31)
            return 1;
    }
    // {
    //     std::cout << "ERROR IN MORE THEN 30 DAY!!!" << std::endl;
    //     std::exit(1);
    // }
    return 0;
}

void dateError(std::string date)
{
    std::cerr << "Error: bad input => " << date << std::endl;
    // std::exit(1);
}



BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &target)
{
    if (&target != this)
    {
        btcVal = target.btcVal;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &target)
{
    btcVal = target.btcVal;
}



BitcoinExchange::~BitcoinExchange()
{
    std::cout << "end of constructor!!" << std::endl;
}

