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
#include 

class BitcoinExchange
{
    private:
        float   value;

    public:
        /* CONSTRUCTOR */
        BitcoinExchange(/* args */);
        /* COPY CONSTRUCTOR */
        BitcoinExchange(BitcoinExchange const &cpy);
        /* DESTRUCTOR */
        ~BitcoinExchange();
        /* SURCHARGED OPERATOR */
        BitcoinExchange operator=(BitcoinExchange &const rhs);
        /* MEMBER FUNCTIONS */
        float   getValue(void);
        void    setValue(float v);
};

#endif 

