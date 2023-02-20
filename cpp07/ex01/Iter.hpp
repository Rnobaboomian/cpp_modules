#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename I>

void iter(I *add,size_t len, void( *func)(I &))
{
	for (size_t i = 0; i < len; i++)
		func(add[i]);
};

template <typename I>

void print( I &tmp)
{
	std::cout << tmp << std::endl;
}

#endif