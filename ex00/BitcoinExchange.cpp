/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &datafile){
	loadDataFile(datafile);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy){
	*this = cpy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs){
	this->data = rhs.data;
	return (*this);
}

void    BitcoinExchange::loadDataFile(const std::string &datafile){
	std::ifstream file(datafile.c_str());
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << datafile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token, date;
        float rates = 0.0;

        if (std::getline(iss, token, ',')) {
            date = token;
        }
        if (std::getline(iss, token, ',')) {
            rates = std::atof(token.c_str());
        }
        this->data.insert(std::make_pair(date, rates));
    }
    file.close();
}

float   BitcoinExchange::findExchangeRates(const std::string date){
	std::map<std::string, float>::iterator it = data.find(date);

	if (it == data.end()){
		it = data.upper_bound(date);
		if (it != data.begin())
			it--;
	}
	return (it->second);
}

void	BitcoinExchange::doExchange(const std::string &file){
	std::ifstream	inFile(file.c_str());
	if (!inFile.is_open()){
		std::cout << "Error: input file cannot be open" << std::endl;
		return ;
	}
	std::string	line;
	std::getline(inFile, line);
	while (std::getline(inFile, line)){
		size_t pos = line.find(" ");
		std::string date, value;
		date = line.substr(0, pos);
		if (validDate(date)){
			if (line[pos + 1] == '|'){
				pos += 3;
				value = line.substr(pos, line.length());
				if (validValue(value)){
					float exValue = findExchangeRates(date);
					float inValue = std::atof(value.c_str());
					float result = exValue * inValue;
					std::cout << date << " => " << value << " = " << result << std::endl;
				}
			}
			else
				std::cout << "Error: separator is wrong." << std::endl;
		}
	}
}

bool	validValue(const std::string &value){
	float fval = std::atof(value.c_str());
	if (fval < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (fval > 1000){
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	validDate(const std::string &date){
    int year, month, day;
	int checkDay;

    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        std::cerr << "Error: Bad input =>" << date << std::endl;
		return (false);
    }
	if (year < 1900 || year > 9999 || month < 1 || month > 12 || day < 1) {
        std::cerr << "Error: Bad input => " << date << std::endl;
        return (false);
    }
	switch (month){
		case 2:
			checkDay = 28 + isLeapYear(year);
			break;
		case 4: case 6: case 9: case 11:
			checkDay = 30;
			break;
		default:
			checkDay = 31;
			break;
	}
	if (day > checkDay){
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
	else if (day < 10 && date[8] != '0'){
		std::cout << "Error: Bad input => " << date << std::endl;
		return (false);
	}
    return (true);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}