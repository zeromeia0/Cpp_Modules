/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:53:25 by vvazzs            #+#    #+#             */
/*   Updated: 2026/04/13 16:51:18 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool _isSigned;
		int _signGrade;
		int _execGrade;
	public:
		Form();
		Form(std::string newName, bool newIsSigned, int newSignGrade, int newExecGrade);
		Form(const Form& newObj);
		Form& operator=(const Form& newObj);
		~Form();
		
		int getSignGrade() const;
		int  getExecGrade() const;
		int getSignedBool() const;
		std::string getName() const;
		void beSigned(const Bureaucrat& bureau);
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
		class alreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, const Form& value);

#endif
