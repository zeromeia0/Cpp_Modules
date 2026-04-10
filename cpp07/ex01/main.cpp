#include "iter.hpp"

class Awesome
{
  private:
    int _number; 
  public:
    Awesome(void) : _number(42)
    {
      return;
    }
    int get( void ) const
    {
      return (this->_number);
    }
};

std::ostream & operator<<( std::ostream & out, Awesome const & rhs )
{
  out << rhs.get();
  return (out);
}

template< typename T > 
void print( T& x ) 
{
  std::cout << x << std::endl;
  return;
}

int main()
{
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];
  const int len = 5;
  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );
  return (0);
}
