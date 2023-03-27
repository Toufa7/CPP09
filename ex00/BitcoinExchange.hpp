#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string , float> _database;
    public:
        BitcoinExchange ();
        BitcoinExchange (const BitcoinExchange &a);
        ~BitcoinExchange ();
        BitcoinExchange & operator = (const BitcoinExchange &a);

        void    ReadBase(void);
        void    PrintMap(std::map<std::string, float> mymap);
        void    ReadInput(std::string file);
        int     Parsing(int year, int month, int day, std::string raate, float rate, std::string     line);
        void    PrintOuput(std::string inputdate, float bitcoins);
};

#endif

