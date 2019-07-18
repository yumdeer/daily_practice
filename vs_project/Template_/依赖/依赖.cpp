#include <iostream>  
#include <list>  
template <typename T>
class CCustomerList
{
public:
	void push(T item)
	{
		m_customer.push_back(item);
	}
	void show_item()
	{
		CCIterator it = m_customer.begin();
		while (it != m_customer.end())
		{
			std::cout << (*it) << std::endl;
			++it;
		}
	}
private:
	typedef std::list<T> CustomerContainer;
	//typedef typename CustomerContainer::iterator CCIterator;
	typedef typename CustomerContainer::iterator CCIterator;
	CustomerContainer m_customer;
};
int main(int argc, char *argv[])
{
	CCustomerList<int> c;
	for (int i = 0; i < 10; ++i) c.push(i);
	c.show_item();
	return 0;
}