#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T const * array, const unsigned int length, void (*func)(T const &))
{
	if (!array || !func)
		return;

	for (unsigned int i = 0; i < length; ++i)
		func(array[i]);
};

template <typename T>
void iter(T* array, const unsigned int length, void (*func)(T &))
{
	if (!array || !func)
		return;

	for (unsigned int i = 0; i < length; ++i)
		func(array[i]);
};

#endif