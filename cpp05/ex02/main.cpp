#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "===== TEST 1: Grade Too Low for Constructor =====" << std::endl;
    try
    {
        ShrubberyCreationForm badForm("Nowhere");
        AForm *tooLow = new ShrubberyCreationForm("Garden");
        (void)tooLow;
    }
    catch (std::exception &e)
    {
        std::cout << "Caught expected Constructor Error: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 2: Unsigned Form Execution =====" << std::endl;
    try
    {
        Bureaucrat boss;
        ShrubberyCreationForm shrub("Backyard");

        std::cout << "Bureaucrat " << boss.getName() << " attempting to execute..." << std::endl;
        boss.executeForm(shrub); 
    }
    catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 3: Robotomy drilling (Failure/Success) =====" << std::endl;
    try
    {
        Bureaucrat worker;
        RobotomyRequestForm rob("Bender");
        worker.executeForm(rob);
    } catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== TEST 4: Copying and Assignment =====" << std::endl;
    try
    {
        PresidentialPardonForm original("Ford Prefect");
        PresidentialPardonForm copy(original);
        
        Bureaucrat president;
        president.executeForm(copy);
    } catch (std::exception &e)
    {
        std::cout << "Main caught: " << e.what() << std::endl;
    }
    std::cout << "\n===== ALL TESTS COMPLETE =====" << std::endl;
    return (0);
}