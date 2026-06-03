/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 05:47:18 by vvazzs            #+#    #+#             */
/*   Updated: 2026/06/02 05:47:22 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {} //inherits from std::stack<T>

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const MutantStack<T>& mstack)
{
	for (typename MutantStack<T>::const_iterator i = mstack.begin(); i != mstack.end(); ++i)
		out << *i << " ";
	return (out);
}