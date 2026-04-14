/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/04/14 16:49:47 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

void printHeader(const std::string& title)
{
	std::cout << "\n--- " << title << " ---\n";
}

void runTest(void (*testf)(), const std::string& name)
{
	printHeader(name);
	try
	{
		testf();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testBureaucrat()
{
	Bureaucrat walter("Walter1", 12);
	Bureaucrat silva;

	std::cout << walter;
	std::cout << silva;
}

void testForm()
{
	Form sigma("Salve", true, 70, 90);
	Form default1;

	std::cout << sigma;
	std::cout << default1;
}

void testInteraction()
{
	Bureaucrat bureau("Lucas", 34);
	Form form("Xavier", false, 60, 60);

	std::cout << bureau;
	std::cout << form;

	bureau.signForm(form);
	std::cout << "Trying to sign [" << form.getName() << "] again" << std::endl;
	bureau.signForm(form);

	std::cout << bureau;
	std::cout << form;

	std::cout << "Decrementing [" << bureau.getName() << "] grade...\n";
	for (int i = 0; i < 5; i++)
		bureau.decrementGrade(1);

	std::cout << bureau;
}

int main()
{
	// runTest(testBureaucrat, "Testing Bureaucrat");
	// runTest(testForm, "Testing Form");
	runTest(testInteraction, "Testing Interaction");

	std::cout << "\nFinished testing\n";
	return 0;
}
