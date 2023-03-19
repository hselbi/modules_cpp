#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) 
{
    // std::cout << "Default Constructor!!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *d)
{
    std::string line, date, value, token, tmp[3];
    std::ifstream csv_data;


    csv_data.open(d, std::ios::in);
	if (!csv_data) {
		std::cout << "No such file" << std::endl;
        std::exit(1);
	}
    
    std::getline(csv_data, line);
    while(std::getline(csv_data, line))
    {
        // ? split the line into two 
        std::istringstream iss(line);
        int i = 0;
        while (std::getline(iss, token, ','))
        {
            tmp[i] = token;
            i++;
        }

        // * check for the date
        if (checkDate(tmp[0]))
            dateError(tmp[0]);
        date = tmp[0].substr(0, 10);

        // & check for the value is correct
        int f = dataValue(tmp[1]);
        if (f)
            dataValueError(f);

        // ^ adding to map
        this->btcVal[date] = std::stof(tmp[1]);

    }    
    
    csv_data.close();
}

int dataValue(std::string v)
{
    std::stringstream ss(v);
    std::string w;
    ss >> w;
    const char *value = w.c_str();
    int i = 0, com = 0, sign = 0;
    while (value[i])
    {
        if (value[i] == '+')
            sign++;
        else if (value[i] == '.')
            com++;
        else if (value[i] < '0' || value[i] > '9')
            return 3;
        i++;
    }
    if (com > 1 || sign > 1)
        return 4;
    float nbr_float = std::stof(v);
    if (nbr_float < 0.0)
        return 1;

    // std::cout << nbr_float << std::endl;
    if (nbr_float > 70000)
        return 2;
    return 0;
}

void dataValueError(int flag)
{
    std::cerr << "Error: CSV file." << flag << std::endl;
    std::exit(flag);
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
    std::ifstream inp;
    inp.open(input, std::ios::in);

    // ! print the map
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
        // std::cout << tmp[0] << std::endl;
        // std::cout << tmp[1] << std::endl;
        if (checkDate(tmp[0]))
        {
            dateError(tmp[0]);
            continue;
        }

        int f = checkValue(tmp[1]);
        if (f)
        {
            valueError(f);
            continue;
        }

        displayResults(tmp[0], tmp[1]);
    }
}

void BitcoinExchange::displayResults(std::string date, std::string value)
{
    std::string d;
    float fval;

    fval = std::atof(value.c_str());
    d = date.substr(0, 10);
    std::map<std::string, float>::iterator it;
    it = btcVal.find(d);
    if (it != btcVal.end())
        std::cout << d << " => " << fval << " = " << fval * (it->second) << std::endl;
    else
    {
        it = btcVal.begin();
        while (d > it->first && it != btcVal.end())
            it++;
        it--;
        std::cout << d << " => " << fval << " = " << fval * (it->second) << std::endl;
    }
}

int checkValue(std::string val)
{
    float nbr_float = std::stof(val);
    if (nbr_float < 0.0)
        return 1;
    if (nbr_float > 1000.0)
        return 2;
    std::stringstream ss(val);
    std::string w;
    ss >> w;
    int com = 0, i = 0, sign = 0;
    const char *value = w.c_str();
    while (value[i])
    {
        if (value[i] == '.')
            com++;
        else if (value[i] < '0' || value[i] > '9')
            return 5;
        else if (value[i] == '+')
            sign++;
        i++;
    }
    if (com > 1 || sign > 1)
        return 4;
    return 0;
}

void valueError(int flag)
{
    if (flag == 1)
        std::cerr << "Error: not a positive number." << std::endl;
    else if (flag == 2)
        std::cerr << "Error: too large a number." << std::endl;
    else
        std::cerr << "Error: not a real number." << std::endl;
}

int    checkDate(std::string date)
{
    std::string token, tmp[3];
    int year, month, day, i = 0;
    std::istringstream iss(date);

    // ^ split the date with '-' and put them in token
    while (std::getline(iss, token, '-'))
    {
        tmp[i] = token;
        i++;
    }
    
    char *end;
    int base = 10;
    year = std::strtol(tmp[0].c_str(), &end, base);
    
    // ^ check years [2009-2022]
    if (year < 2009 && year > 2022)
        return 1;
    
    month = std::strtol(tmp[1].c_str(), &end, base);
    
    // ^ check months [1-12]
    if (month < 1 || month > 12)
        return 1;
    
    day = std::strtol(tmp[2].c_str(), &end, base);
    
    // ^ check days [1-31]
    if (day < 1 || day > 31)
        return 1;
    
    // ^ check febrary
    if (month == 2 && day > 29)
        return 1;
    
    // ^ check month who has 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 1;
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
        btcVal = target.btcVal;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &target)
{
    btcVal = target.btcVal;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "end of constructor!!" << std::endl;
}