/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float>    data;
        void    loadDataFile(const std::string &datafile);

    public:
        /* CONSTRUCTOR */
        BitcoinExchange(const std::string &datafile);
        /* COPY CONSTRUCTOR */
        BitcoinExchange(BitcoinExchange const &cpy);
        /* DESTRUCTOR */
        ~BitcoinExchange();
        /* SURCHARGED OPERATOR */
        BitcoinExchange &operator=(BitcoinExchange const &rhs);
        /* MEMBER FUNCTIONS */
        float   findExchangeRates(const std::string date);
        void    doExchange(const std::string &inFile);
};

bool    validDate(const std::string &date);
bool    isLeapYear(int year);
bool    validValue(const std::string &value);

#endif
