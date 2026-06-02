/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:14:32 by vvazzs            #+#    #+#             */
/*   Updated: 2026/06/02 05:31:48 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


void printSection(const std::string& title)
{
	int width = 50;
	int padding = (width - title.size()) / 2;
	std::cout << '\n' << std::string(width, '=')
		<< '\n' << std::string(padding, ' ') << title
		<< std::string(padding, ' ') << '\n'
		<< std::string(width, '=') << '\n';
}

template <typename T>
void print_container(const T& container)
{
	for (typename T::const_iterator n = container.begin(); n != container.end(); ++n)
		std::cout << *n << ' ';
	std::cout << '\n';
}

template <typename T>
void find_it(const T& container, int value)
{
    try 
    {
		if (container.empty())
			throw (std::runtime_error("Empty container"));
        if (easyfind(container, value) != container.end())
            std::cout << "Value " << value << " found.\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Value " << value << " not found (Exception: " << e.what() << ")\n";
    }
}

int main()
{
	int arr_v[] = { 42, 3, -7, 21, 78 };
	std::vector<int> v(arr_v, arr_v + 5);
	printSection("TESTING WITH VECTOR");
	print_container(v);
	find_it(v, -7);
	find_it(v, 78);
	find_it(v, 2);

	int arr_l[] = { 18, -34, 13, 89, 61 };
	std::list<int> l(arr_l, arr_l + 5);
	printSection("TESTING WITH LIST");
	print_container(l);
	find_it(l, 13);
	find_it(l, -34);
	find_it(l, 81);

	int arr_d[] = { 76, 53, -4, 0, 33 };
	std::deque<int> d(arr_d, arr_d + 5); //study later
	printSection("TESTING WITH DEQUE");
	print_container(d);
	find_it(d, 0);
	find_it(d, 76);
	find_it(d, 30);
	
	int arr_con[] = {0, 5, 9, 12};
	const std::vector<int> c(arr_con, arr_con + 4);
	printSection("Testing with const T");
	print_container(c);
	find_it(c, 2);
	find_it(c, 9);
	find_it(c, 7);

	const std::list<int> nu;
	printSection("Testing with NULL");
	print_container(nu);
	find_it(nu, 7);
}