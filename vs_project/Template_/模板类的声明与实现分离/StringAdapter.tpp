// StringAdapter.tpp
#include "StringAdapter.h"

template<typename T>
StringAdapter<T>::StringAdapter(T* data) : m_data(data)
{
	cout << m_data << endl;
}

template<typename T>
void StringAdapter<T>::doAdapterStuff()
{
    /* Manipulate a string */
	cout << "hello" << endl;
}
