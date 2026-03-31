/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/03/31 13:26:28 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
# include <iostream>
# include <iomanip>
# include <cmath>
#define HIGHEST_POSSIBLE 1
#define LOWEST_POSSIBLE 150

class Bureaucrat
{
	private :
		const std::string	_name;
		int 		_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& newObj);
		Bureaucrat& operator=(const Bureaucrat& newObj);
		~Bureaucrat();
		
		int getGrade() const;
		std::string getName() const;
		void incrementGrade(int n);
		void decrementGrade(int n);

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
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);


#endif
