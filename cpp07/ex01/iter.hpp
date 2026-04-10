#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T const * array, const unsigned int length, void (*f)(T const &))
{
	if (!array || !f)
		return;
	for (unsigned int i = 0; i < length; ++i)
		f(array[i]);
};

template <typename T>
void iter(T* array, const unsigned int length, void (*f)(T &))
{
	if (!array || !f)
		return;
	for (unsigned int i = 0; i < length; ++i)
		f(array[i]);
};

#endif