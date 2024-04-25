/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av){
	std::deque<int> numD;
	std::vector<int> numV;
	insertNum(numD, av, ac);
	insertNum(numV, av, ac);
	std::cout << "Before: ";
	display(numD);
	_firstCont = mergeSortV(numV);
	_secCont = mergeSortD(numD);
	std::cout << "After :";
	display(_firstCont);
}

PmergeMe::PmergeMe(PmergeMe const &cpy){
	*this = cpy;
}

PmergeMe::~PmergeMe(){}

PmergeMe    &PmergeMe::operator=(PmergeMe const &rhs){
	this->_firstCont = rhs._firstCont;
	this->_secCont = rhs._secCont;

	return (*this);
}
template <typename T>
void    PmergeMe::insertNum(T &containers, char **av, int ac){
	for (int i = 1; i < ac; i++){
		if (atoi(av[i]) < 0){
			std::cerr << "Error: Negativ numbers. " << std::endl;
			return ;
		}
		containers.push_back(atoi(av[i]));
	}
	return ;
}

template <typename T>
void	PmergeMe::display(T &container){
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::mergeSortV(std::vector<int> numV){
	int	middle = numV.size() / 2;
	std::vector<int> left(numV.begin(), numV.begin() + middle);
	std::vector<int> right(numV.begin(), middle + numV.end());

	left = mergeSortV(left);
	right = mergeSortV(right);

	return (mergeV(left, right));
}

std::deque<int>		PmergeMe::mergeSortD(std::deque<int> numD){

}

std::vector<int>	PmergeMe::mergeV(std::vector<int> left, std::vector<int> right){
	std::vector<int> sortedLst; 
}