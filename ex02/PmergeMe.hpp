/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malleman <malleman@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:37:09 by malleman          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:18 by malleman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe{

    private:
        std::vector<int>    _firstCont;
        std::deque<int>      _secCont;

    public:
        /* CONSTRUCTOR */
        PmergeMe(int ac, char **av);
        /* COPY CONSTRUCTOR */
        PmergeMe(PmergeMe const &cpy);
        /* DESUTRCTOR */
        ~PmergeMe();
        /* SURCHARGED OPERATOR */
        PmergeMe &operator=(PmergeMe const &rhs);
        /* MEMBER FUNCTIONS */
        template <typename T>
        void    insertNum(T &container, char **av, int ac);
        template <typename T>
        void    display(T &container);
        std::vector<int> mergeSortV(std::vector<int> &numV);
        std::deque<int> mergeSortD(std::deque<int> &numD);
        std::vector<int> mergeV(std::vector<int> &left, std::vector<int> &right);
        std::deque<int> mergeD(std::deque<int> &left, std::deque<int> &right);

};

#endif
