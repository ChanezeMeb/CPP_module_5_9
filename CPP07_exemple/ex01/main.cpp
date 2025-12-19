#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}


// template <typename T>
// void	doubleValue(T &value)
// {
// 	value *= 2;
// }

// template <typename T>
// void	printValue(const T &value)
// {
// 	std::cout << value << " ";
// }

// void	increment(int &n)
// {
// 	n++;
// }

// int	main()
// {
// 	int	intArray[5] = {1, 2, 3, 4, 5};

// 	std::cout << "Before: ";
// 	::iter(intArray, 5, printValue<int>);

// 	::iter(intArray, 5, doubleValue<int>);

// 	std::cout << "\nAfter: ";
// 	::iter(intArray, 5, printValue<int>);
// 	std::cout << std::endl;

// 	std::string strArray[3] = {"Test", "String", "Array"};
// 	::iter(strArray, 3, printValue<std::string>);
// 	std::cout << std::endl;

// 	int nums[4] = {10, 20, 30, 40};
// 	std::cout << "Before: ";
// 	::iter(nums, 4, printValue<int>);
	
// 	::iter(nums, 4, increment);

// 	std::cout << "\nAfter:  ";
// 	::iter(nums, 4, printValue<int>);
// 	std::cout << std::endl;

// 	const double constArray[3] = {1.1, 2.2, 3.3};
// 	::iter(constArray, 3, printValue<double>);
// 	std::cout << std::endl;

// 	return (0);
// }