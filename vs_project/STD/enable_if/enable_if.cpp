#include <iostream>
#include <type_traits>
using namespace std;

template<typename T, typename = typename enable_if<is_integral<T>::value, void>::type>
bool isodd(T x)
{
	return x % 2;
}

template <typename OutputIt, typename = typename enable_if<is_same<output_iterator_tag, typename iterator_traits<OutputIt>::iterator_category>::value || (is_base_of<forward_iterator_tag, typename iterator_traits<OutputIt>::iterator_category>::value && !is_const<OutputIt>::value)>::type>
void read(OutputIt __first, OutputIt __last) 
{ 
	for (; __first != __last; ++__first) read(*__first); 
}


int main()
{
	cout << isodd(4) << endl << isodd('a');
	//cout << isodd("qwq"); -- compile error
	return 0;
}