/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvazzs <vvazzs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:58:47 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/20 10:38:53 by vvazzs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <fstream>

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
		~AForm();
		std::string getName() const;
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
};

#endif
