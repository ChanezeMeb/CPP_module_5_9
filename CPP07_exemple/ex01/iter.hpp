#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>
#include <cstddef>

template <typename T, typename F>
void	iter(T *array, const size_t len, F f)
{
	if (!array || len == 0)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif