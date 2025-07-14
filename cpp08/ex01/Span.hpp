#ifndef SPAN_HPP
# define SPAN_HPP

class Span{
private:
	int manyAdded;
	int max;
public:

	Span();
	Span(unsigned int N);
	~Span();

	Span &operator=(Span const &other);
};

#endif
