#include <iostream>
#include <vector>

class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{ value }
	{
	}

	virtual const char* getName() const { return "Base"; }
	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const { return "Derived"; }
};

//void printName(const Base base) // note: base passed by value, not reference
void printName(const Base& base) 
{
	std::cout << "I am a " << base.getName() << '\n';
}

int main()
{
	Derived derived{ 5 };
	std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

	Base &ref{ derived };
	std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

	Base *ptr{ &derived };
	std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

	Base base{ derived }; // what happens here?
	std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

	Derived d{ 5 };
	printName(d); // oops, didn't realize this was pass by value on the calling end

	//std::vector<Base> v{};
	//v.push_back(Base{ 5 }); // add a Base object to our vector
	//v.push_back(Derived{ 6 }); // add a Derived object to our vector

		// Print out all of the elements in our vector
	//for (const auto& element : v)
		//std::cout << "I am a " << element.getName() << " with value " << element.getValue() << '\n';

	//std::vector<Base*> v;
	//v.push_back(new Base(5)); // add a Base object to our vector
	//v.push_back(new Derived(6)); // add a Derived object to our vector

	//for (int count = 0; count < v.size(); ++count)
	//	std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";

	//for (int count = 0; count < v.size(); ++count)
	//	delete v[count];

	std::vector<Base*> v{};

	Base b{ 5 }; // b and d can't be anonymous objects
	//Derived d{ 6 };

	v.push_back(&b); // add a Base object to our vector
	v.push_back(&d); // add a Derived object to our vector

	// Print out all of the elements in our vector
	for (const auto* element : v)
		std::cout << "I am a " << element->getName() << " with value " << element->getValue() << '\n';


	return 0;
}