//StringAdapter.h

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class StringAdapter
{
public:
	StringAdapter(T* data);
	void doAdapterStuff();
private:
	T* m_data;
};

#include "StringAdapter.tpp"
