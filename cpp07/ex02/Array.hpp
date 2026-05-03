/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:29:16 by vvazzs            #+#    #+#             */
/*   Updated: 2026/05/03 16:51:57 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array() : _array(0), _size(0) {} //default constructor incomplete
		Array(unsigned int n) : _array(new T[n]()), _size(n) {} //default empty constructor
		Array(const Array& other) : _array(new T[other._size]()), _size(other._size) //default copy constructor
		{
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
		Array& operator=(const Array& other) //copy assingment
		{
			if (this == &other)
				return (*this);

			T* new_array = new T[other._size]();

			for (unsigned int i = 0; i < other._size; ++i)
				new_array[i] = other._array[i];

			delete[] _array;

			_array = new_array;
			_size = other._size;

			return (*this);
		}
		~Array() { delete[] _array; }
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("Index out of bounds"); }
		};
		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return (_array[index]);
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return (_array[index]);
		}
		unsigned int size() const { return (_size); }
};

#endif