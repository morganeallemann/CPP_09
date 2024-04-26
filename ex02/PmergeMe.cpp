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
	display(numV);
	clock_t	startV = clock();
	_firstCont = mergeSortV(numV);
	clock_t endV = clock();
	double timeV = double(endV - startV) / CLOCKS_PER_SEC;
	clock_t	startD = clock();
	_secCont = mergeSortD(numD);
	clock_t	endD = clock();
	double timeD = double(endD - startD) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	display(_firstCont);
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _firstCont.size() << " elements with std::vector : " << timeV << " sec." << std::endl;
	std::cout << "Time to process a range of " << _firstCont.size() << " elements with std::deque : " << timeD << " sec." << std::endl;
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

std::vector<int>	PmergeMe::mergeSortV(std::vector<int> &numV){
	if (numV.size() <= 1)
		return (numV);
	
	int	middle = numV.size() / 2;
	std::vector<int> left(numV.begin(), numV.begin() + middle);
	std::vector<int> right(numV.begin() + middle, numV.end());

	left = mergeSortV(left);
	right = mergeSortV(right);
	
	return (mergeV(left, right));
}

std::deque<int>		PmergeMe::mergeSortD(std::deque<int> &numD){
	if (numD.size() <= 1)
		return (numD);
	int	middle = numD.size() / 2;
	std::deque<int> left(numD.begin(), numD.begin() + middle);
	std::deque<int> right(numD.begin() + middle, numD.end());

	left = mergeSortD(left);
	right = mergeSortD(right);

	return (mergeD(left, right));
}

std::deque<int>		PmergeMe::mergeD(std::deque<int> &left, std::deque<int> &right){
	std::deque<int> sortedLst;
	int i = 0;
	int j = 0;

	while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())){
		if (left[i] <= right[j]){
			sortedLst.push_back(left[i]);
			i++;
		}
		else{
			sortedLst.push_back(right[j]);
			j++;
		}

	}
	while (i < static_cast<int>(left.size())){
		sortedLst.push_back(left[i]);
		i++;
	}
	while (j < static_cast<int>(right.size())){
		sortedLst.push_back(right[j]);
		j++;
	}
	return (sortedLst);
}

std::vector<int>	PmergeMe::mergeV(std::vector<int> &left, std::vector<int> &right){
	std::vector<int> sortedLst;
	int i = 0;
	int j = 0;

	while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())){
		if (left[i] <= right[j]){
			sortedLst.push_back(left[i]);
			i++;
		}
		else{
			sortedLst.push_back(right[j]);
			j++;
		}

	}
	while (i < static_cast<int>(left.size())){
		sortedLst.push_back(left[i]);
		i++;
	}
	while (j < static_cast<int>(right.size())){
		sortedLst.push_back(right[j]);
		j++;
	}
	return (sortedLst);
}