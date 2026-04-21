/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:48:29 by vvazzs            #+#    #+#             */
/*   Updated: 2026/04/21 12:51:51 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data = {0, 1.5, "test"};

	Data* original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Original pointer:     " << original << std::endl;
	std::cout << "Serialized uintptr_t: " << raw << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	if (original == deserialized)
		std::cout << "OK: pointers are equal\n";
	else
		std::cout << "Error: pointers are different\n";

	return (0);
}