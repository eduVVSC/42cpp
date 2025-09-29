
#include "Whatever.hpp"
#include <iostream>

/* class Awesome
{
	public:
	Awesome(void) { n = 0;};
	Awesome(int n) { this->n = n; };
	~Awesome() {};

	Awesome &operator =(Awesome &a) { this->n = a.n; return *this; }

	bool operator==(Awesome const & rhs) const { return (this->n == rhs.n); };
	bool operator!=(Awesome const & rhs) const { return (this->n != rhs.n); };
	bool operator>(Awesome const & rhs) const { return (this->n > rhs.n); };
	bool operator<(Awesome const & rhs) const { return (this->n < rhs.n); };
	bool operator>=(Awesome const & rhs) const { return (this->n >= rhs.n); };
	bool operator<=(Awesome const & rhs) const { return (this->n <= rhs.n); };

	int getN() const { return n; };

	private:

		int n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) { o << a.getN(); return (o);}


	// Awesome test to main!
	//
	// 	Awesome e(2), f(4);
	//	std::cout << "Awsome test: " << e.getN() << " " << f.getN() << std::endl;
	//	std::cout << "Max: " << ::max( e , f) << std::endl;
	//	std::cout << "min: " << ::min( e , f) << std::endl;
	//
	//	::swap(e, f);
	//
	//	std::cout << "Swap test: " << e.getN() << " " << f.getN() << std::endl;
*/

int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return (0);
}
