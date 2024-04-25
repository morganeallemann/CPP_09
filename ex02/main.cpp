/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
	if (ac < 2){
		std::cerr << "Error: Invalids args." << std::endl;
	}
	else if (ac == 2){
		std::cout << "Before: " << av[1] << std::endl;
		std::cout << "After: " << av[1] << std::endl;
		std::cout << "The list is already sorted" << std::endl;
		return (0);
	}
	else
		PmergeMe sort(ac, av);
	return (0);
}