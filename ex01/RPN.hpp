/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm> 
#include <stack>

class	RPN{

	private:
		std::stack<int>	_pile;

	public:
		/* CONSTRUCTOR */
		RPN(std::string &listNumer);
		/* COPY CONSTRUCTOR */
		RPN(RPN const &cpy);
		/* DESTRUCTOR */
		~RPN();
		/* SURCHARGED OPERATOR */
		RPN	&operator=(RPN const &rhs);
		/* MEMBER FUNCTIONS */
		void	createStack(std::string &listNumer);
		int		calculate(char const &sign);
};

#endif
