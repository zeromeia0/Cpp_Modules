/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:47 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/04/13 16:53:43 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <fstream>
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	private:
		std::string _name;
    	bool _isSigned;
    	int _signGrade;
    	int _execGrade;
	protected:
		void checkExecution(Bureaucrat const & executor) const;
	public:
		AForm(std::string name = "Default name",
			std::string target = "Default target", 
			int signGrade = 150, int execGrade = 150);
		AForm();
		AForm(const AForm& newObj);
		AForm& operator=(const AForm& newObj);
		virtual ~AForm();
		std::string getName() const;
		void beSigned(const Bureaucrat& bureau);
		virtual void execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class alreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
