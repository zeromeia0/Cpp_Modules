#include "iter.hpp"
#include <exception>

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
	std::cout << "========== TEST 0: NULL ==========" << std::endl;
	{
		int tab1[] = {};
		const int len = 5;

		iter(tab1, len, print<int>);
		std::cout << std::endl;
	}
	std::cout << "========== TEST 1: int array ==========" << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4};
		const int len = 5;

		iter(tab, len, print<int>);
		std::cout << std::endl;
	}

	std::cout << "========== TEST 2: const int array ==========" << std::endl;
	{
		const int tab[] = {10, 20, 30, 40, 50};
		const int len = 5;

		iter(tab, len, print<const int>);
		std::cout << std::endl;
	}

	std::cout << "========== TEST 3: Awesome array ==========" << std::endl;
	{
		Awesome tab[5];
		const int len = 5;

		iter(tab, len, print<Awesome>);
		std::cout << std::endl;
	}

	std::cout << "========== TEST 4: single element ==========" << std::endl;
	{
		int tab[] = {42};
		const int len = 1;

		iter(tab, len, print<int>);
		std::cout << std::endl;
	}

	std::cout << "========== TEST 5: empty length ==========" << std::endl;
	{
		int tab[] = {1, 2, 3};
		const int len = 0;

		iter(tab, len, print<int>);
		std::cout << "[OK] length = 0 handled" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "========== TEST 6: negative numbers ==========" << std::endl;
	{
		int tab[] = {-5, -1, 0, 1, 5};
		const int len = 5;

		iter(tab, len, print<int>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 7: Smaller Len ==========" << std::endl;
	{
		int tab[] = {6, 7, 6, 9, 0};
		const int len = 5;

		iter(tab, len, print<int>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 8: Bigger Len ==========" << std::endl;
	{
		int tab[] = {6, 7, 6, 0};
		const int len = 5;

		iter(tab, len, print<int>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 9: Char type ==========" << std::endl;
	{
		char tab[] = {'a', 'b', 'c', 'd', 'e'};
		const int len = 5;

		iter(tab, len, print<char>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 10: Unsidned Char type ==========" << std::endl;
	{
		char tab[] = {-32, -5, -128, -75};
		const int len = 5;

		iter(tab, len, print<char>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 11: Const Unsidned Char type ==========" << std::endl;
	{
		const char tab[] = {-32, -5, -128, -75};
		const int len = 5;

		iter(tab, len, print<const char>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 11: Bool Type ==========" << std::endl;
	{
		// bool tab[] = {};
		bool tab[] = {true, false, false, true, true};
		const int len = 5;

		iter(tab, len, print<bool>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 12: String ==========" << std::endl;
	{
		std::string tab[] = {"Please", "Gimme", "a", "Red", "Pen", "Siinamota"};
		const int len = 6;

		iter(tab, len, print<std::string>);
		std::cout << std::endl;
	}
  std::cout << "========== TEST 13: Null String ==========" << std::endl;
  try
  {
    {
      std::string tab[] = {NULL};
      const int len = 6;

      iter(tab, len, print<std::string>);
      std::cout << std::endl;
    }
  }
  catch (std::exception &)
  {
      std::cout << "Error" << std::endl;
  }

	return (0);
}
