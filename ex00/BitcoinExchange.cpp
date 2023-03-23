#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ()
{
}

/*--------------------------------------------------------*/
BitcoinExchange::BitcoinExchange (const BitcoinExchange &a)
{
	this->operator=(a);
}

/*--------------------------------------------------------*/
BitcoinExchange::~BitcoinExchange ()
{
}

/*--------------------------------------------------------*/
BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &a)
{
	(void)a;
	return (*this);
}

