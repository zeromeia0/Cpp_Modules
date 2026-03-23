
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		enum e_type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};
		ScalarConverter();
		ScalarConverter(const ScalarConverter& newObj);
		ScalarConverter& operator=(const ScalarConverter& newObj);
		~ScalarConverter();
	public:
};

#endif
