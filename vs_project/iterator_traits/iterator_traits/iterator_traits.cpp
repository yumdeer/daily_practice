#include<iostream>
using namespace std;
struct input_iterator {};
struct output_iterator {};
struct forward_iterator :public input_iterator {};
struct bidirectional_iterator :forward_iterator {};
struct random_access_iterator :bidirectional_iterator {};

template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T * , typename Reference = T & >
struct iterator
{
	typedef Category iterator_category;
	typedef T        value_type;
	typedef Pointer  pointer;
	typedef Reference reference;
	typedef Distance difference_type;
};

template<typename Iterator>
struct Iterator_traitss
{
	typedef typename Iterator::iterator_catergory   iterator_category;
	typedef typename Iterator::value_type           value_type;
	typedef typename Iterator::pointer			    pointer;
	typedef typename Iterator::reference		    reference;
	typedef typename Iterator::difference_type      difference_type;
};

template<typename T>
struct Iterator_traitss<T*>
{
	typedef random_access_iterator          iterator_category; 
	typedef T                               value_type;
	typedef ptrdiff_t                       difference_type;
	typedef T*                              pointer;
	typedef T&                              reference;
};

template<typename T>
struct Iterator_traitss<const T*>
{
	typedef random_access_iterator          iterator_category;
	typedef T                               value_type;
	typedef ptrdiff_t                       difference_type;
	typedef const T*                        pointer;
	typedef const T&                        reference;
};

template<typename Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
	typedef typename iterator_traitss<Iterator>::iterator_category category;
	return category();
}

int main()
{
	;
}