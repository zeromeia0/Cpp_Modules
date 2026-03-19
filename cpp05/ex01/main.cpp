/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:34 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/19 13:51:40 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Utility to print section headers
void printHeader(const std::string& title)
{
	std::cout << "\n--- " << title << " ---\n";
}

// Generic test runner with exception handling
void runTest(void (*testFunc)(), const std::string& name)
{
	printHeader(name);
	try
	{
		testFunc();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

// ---------------- TESTS ----------------

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
	Bureaucrat bureau;
	Form form;

	std::cout << bureau;
	std::cout << form;

	form.beSigned(bureau);
	bureau.signForm(form);

	std::cout << bureau;
	std::cout << form;

	for (int i = 0; i < 5; i++)
		bureau.decrementGrade(1);

	std::cout << bureau;
}

// ---------------- MAIN ----------------

int main()
{
	runTest(testBureaucrat, "Testing Bureaucrat");
	runTest(testForm, "Testing Form");
	runTest(testInteraction, "Testing Interaction");

	std::cout << "\nFinished testing\n";
	return 0;
}
