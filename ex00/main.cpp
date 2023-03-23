#include "BitcoinExchange.hpp"

void    BitcoinExchange::PrintMap(std::map<std::string, double> mymap)
{
    std::map<std::string, double>::iterator itb = mymap.begin();
    std::map<std::string, double>::iterator ite = mymap.end();
    for (; itb != ite; itb++)
    {
        std::cout << itb->first << " | " <<  itb->second << "\n";
    }
    
}

void    BitcoinExchange::ParseInput(int year, int month, int day, double rate)
{
    int month_limits[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (year < 2009 || month < 1 || month > 12)
    {  
        throw std::invalid_argument("Invalid Date Format");
                // std::cout << "Error : Invalid Date Format\n";
    }

    if (day > month_limits[month - 1])
    {
        throw std::out_of_range("Out of month range");
    }

    if (rate < 0.00 || rate > 1000.00 )
    {
        throw std::invalid_argument("Invalid Rate");
            // std::cout << "Error : Invalid Bitcoins\n";
    }
}

void    BitcoinExchange::PrintOuput(std::string inputdate, double bitcoins)
{
    std::map<std::string, double>::iterator itb = this->_database.begin();
    std::map<std::string, double>::iterator ite = this->_database.end();
    bool    flag = false;

    for (; itb != ite; itb++)
    {
        if (itb->first == inputdate)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        double rslt = bitcoins * itb->second;
        std::string date = itb->first;
        date.insert(4,"-").insert(7,"-");
        std::cout << date << " => " << bitcoins << " = " << std::fixed << std::setprecision(0) << rslt << "\n";
        flag = false;
    }
    else
    {
        ite = this->_database.lower_bound(inputdate);
        double rslt = bitcoins * ite->second;
        std::string date = ite->first;
        date.insert(4,"-").insert(7,"-");
        std::cout << date << " => " << bitcoins << " = " << rslt << "\n";
    }
}

void    BitcoinExchange::ReadInput(void)
{
    std::ifstream   input;
    std::string     line;

    input.open("./input.csv");

    while (!input.eof())
    {
        std::string fulldate;
        std::getline(input, line);
        int year = std::stoi(line.substr(0,4));
        int month = std::stoi(line.substr(5,2));
        int day = std::stoi(line.substr(8,2));

        std::string raate = line.substr(13, line.find('\0'));

        int count = 0;
        for (size_t i = 0; i < raate.length(); i++)
        {
            if (raate[0] == ',')
                throw std::invalid_argument("Invalid Rate Format");
            if (raate[i] == ',')
                count++;
            if (!(isdigit(raate[i])) && raate[i] != ',' && (count == 1 || count == 0))
                throw std::invalid_argument("Invalid Rate Format");
        }

        double      bitcoins = std::stod(raate);

        if (month < 10 && day < 10)
            fulldate = std::to_string(year * 10) + std::to_string(month * 10) + std::to_string(day);
        else if (day < 10)
            fulldate = std::to_string(year) + std::to_string(month * 10) + std::to_string(day);
        else if (month < 10)
            fulldate = std::to_string(year * 10) + std::to_string(month) + std::to_string(day);
        else
            fulldate = std::to_string(year) + std::to_string(month) + std::to_string(day);


        ParseInput(year, month, day, bitcoins);
        PrintOuput(fulldate, bitcoins);

        if (line.substr(4,1) != "-" && line.substr(7,1) != "-")
        {
            throw std::invalid_argument("Invalid Date Format\n");
        }
    }
}
void    BitcoinExchange::ReadBase(void)
{
    std::ifstream   input;
    std::string     database;

    input.open("./data.csv");

    while (!input.eof())
    {
        input >> database;
        std::string fulldate = database.substr(0,10).erase(4,1).erase(6,1);
        double      rate = 0.0;
        std::stringstream convert;
        convert << database.substr(11);
        convert >> rate;
        _database.insert(std::make_pair(fulldate,rate));
    }
    // PrintMap(this->_database);
    input.close();    
}

int main(int ac, char *av[])
{
    BitcoinExchange A;
    if (ac == 2)
    {
        try
        {
            A.ReadBase();
            A.ReadInput();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr << "Error: could not open file";
}

