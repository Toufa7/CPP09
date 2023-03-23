#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string , double> _database;
    public:
        BitcoinExchange ();
        BitcoinExchange (const BitcoinExchange &a);
        ~BitcoinExchange ();
        BitcoinExchange & operator = (const BitcoinExchange &a);

        void    ReadBase(void);
        void    PrintMap(std::map<std::string, double> mymap);
        void    ReadInput(void);
        void    ParseInput(int year, int month, int day, double rate);
        void    PrintOuput(std::string inputdate, double bitcoins);
};

#endif

