/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaz-ca <vivaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:31 by vivaz-ca          #+#    #+#             */
/*   Updated: 2026/02/12 22:30:11 by vivaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Bureaucrat
{
	protected:
		int 		_grade;
		std::string	_name;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& newObj);
		Bureaucrat& operator=(const Bureaucrat& newObj);
		~Bureaucrat();
		
		int getGrade();
		std::string getName();
		void incrementGrade(int n);
		void decrementGrade(int n);

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);


#endif
