/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string &listNumer){
	createStack(listNumer);
}

RPN::RPN(RPN const &cpy){
	*this = cpy;
}

RPN::~RPN(){}

RPN		&RPN::operator=(RPN const &rhs){
	this->_pile = rhs._pile;
	return (*this);
}

void	RPN::createStack(std::string &listNumer){
	for (unsigned int i = 0; i != listNumer.length(); i++){
		if (listNumer[i] != ' '){
			if (listNumer[i] > '0' && listNumer[i] <= '9'){
				if (listNumer[i + 1] != ' '){
					std::cerr << "Error: Syntax wrong or invalid number" << std::endl;
					return ;
				}
				else{
					int nb = atoi(&listNumer[i]);
					_pile.push(nb);
				}
			}
			else{
				int tempResult = calculate(listNumer[i]);
				if (tempResult != -1)
					_pile.push(tempResult);
				else{
					std::cerr << "Error: Incorect sign." << std::endl;
					return ;
				}
			}
		}
	}
	if (_pile.size() == 1)
		std::cout << _pile.top() << std::endl;
	else
		std::cerr << "Error: bad input." << std::endl;
	return ;
}

int		RPN::calculate(char const &sign){
	if (!_pile.empty()){
		int nb1 = _pile.top();
		_pile.pop();
		int	nb2 = _pile.top();
		_pile.pop();

		switch (sign){
			case '+':
				nb2 += nb1;
				break;
			case '-':
				nb2 -= nb1;
				break;
			case '*':
				nb2 *= nb1;
				break;
			case '/':
				nb2 /= nb1;
				break;
			default :
				nb2 = -1;
		}
		return (nb2);
	}
	else 
		return (-1);
}