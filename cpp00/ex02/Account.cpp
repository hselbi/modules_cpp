#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

void    Account::_displayTimestamp()
{
    time_t t;
    time(&t);
    std::tm *tt = std::localtime(&t);
    std::cout << std::put_time(tt, "[%Y%m%d_%H%M%S]");
}

int Account::getNbAccounts(void){ return _nbAccounts;}
int Account::getTotalAmount (void){ return _totalAmount;}
int Account::getNbDeposits (void){ return _totalNbDeposits;}
int Account::getNbWithdrawals (void){ return _totalNbWithdrawals;}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_disposit)
{

    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _amount = initial_disposit;
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_disposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << (7 - _accountIndex);
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _totalAmount += deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << ++_nbDeposits << std::endl;
    _totalNbDeposits += _nbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    if (_totalAmount >= withdrawal)
    {
        std::cout << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        std::cout << ";amount:" << _totalAmount;
        std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals = _nbWithdrawals;
        return (true);
    }
    else
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
}

int		Account::checkAmount( void ) const
{
    return(_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposit:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}





