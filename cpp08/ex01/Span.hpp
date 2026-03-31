
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Span
{
	public:
		Span();
		Span(const Span& newObj);
		Span& operator=(const Span& newObj);
		~Span();
};

#endif
