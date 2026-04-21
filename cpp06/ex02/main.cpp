#include "A.hpp"
#include "Base.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

static void printSection(const std::string& title)
{
	int width = 50;
	int padding = (width - title.size()) / 2;
	std::cout << '\n' << std::string(width, '=')
		<< '\n' << std::string(padding, ' ') << title
		<< std::string(padding, ' ') << '\n'
		<< std::string(width, '=') << '\n';
}

void identify(Base& p)
{
	std::cout << "Actual type based on reference: ";
	try
	{
		(void)dynamic_cast<A&>(p); //void doesn't care about result, only if failed or not
		std::cout << "A\n";
		return;
	}
	catch (const std::exception&) {} //dynamic_cast + reference throws exception if it fails
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch (const std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch (const std::exception&)
	{
		std::cerr << "unknown\n";
	}
}

void identify(Base* p)
{
	std::cout << "Actual type based on pointer: ";
	if (!p)
	{
		std::cerr << "Error: null pointer\n";
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cerr << "unknown\n";
}

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new (std::nothrow) A());
		case 1:
			return (new (std::nothrow) B());
		case 2:
			return (new (std::nothrow) C());
		default:
			return (NULL);
	}
}

Base* invalid(void)
{
	return (NULL);
}

int main()
{
	std::srand(std::time(NULL));
	printSection("Generating Four Objects");
	Base *ptr1 = generate();
	std::cout << "Finished generating test 0..." << std::endl;
	Base *ptr2 = generate();
	std::cout << "Finished generating test 1..." << std::endl;
	Base *ptr3 = generate();
	std::cout << "Finished generating test 2..." << std::endl;
	Base *ptr4 = generate();
	std::cout << "Finished generating test 3..." << std::endl;
	if (!ptr1 || !ptr2 || !ptr3 || !ptr4)
	{
		std::cerr << "Error generating new object\n";
		return (1);
	}
	printSection("Identifying Object 1");
	identify(ptr1);
	identify(*ptr1);
	printSection("Identifying Object 2");
	identify(ptr2);
	identify(*ptr2);
	printSection("Identifying Object 3");
	identify(ptr3);
	identify(*ptr3);
	printSection("Identifying Object 4");
	identify(ptr4);
	identify(*ptr4);
	printSection("Identifying Invalid Object");
	Base* final_ptr = invalid();
	identify(*final_ptr);
	identify(final_ptr);
	delete (ptr1);
	delete (ptr2);
	delete (ptr3);
	delete (ptr4);
	delete (final_ptr);
	return (0);
}