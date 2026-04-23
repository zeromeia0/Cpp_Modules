#include "iter.hpp"

class Awesome
{
  private:
    int _number; 
  public:
    Awesome(void) : _number(42) {return;}
    int get( void ) const {return (this->_number);}
};

std::ostream & operator<<( std::ostream & out, Awesome const & rhs )
{
  out << rhs.get();
  return (out);
}

int main()
{
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];
  const int len = 5;
  std::cout << "===== Testing iter with const int =====" << std::endl;
  iter( tab, len, print<const int> );
  std::cout << "===== Testing iter with Awesome class =====" << std::endl;

  iter( tab2, len, print<Awesome> );
  iter(tab, 0, print<const int>);

  return (0);
}
