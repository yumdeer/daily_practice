#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main()
{
	// seed the RNG
	std::random_device rd;
	std::mt19937 mt(rd());

	std::vector<int> elements{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "Before: ";
	std::copy(elements.cbegin(), elements.cend(),
		std::ostream_iterator<int>(std::cout, " "));

	//std::vector<int>::size_type currentIndexCounter = elements.size();
	auto currentIndexCounter = elements.size();

	//for (std::vector<int>::reverse_iterator iter = elements.rbegin(); iter != elements.rend();
	for (auto iter = elements.rbegin(); iter != elements.rend();
		++iter, --currentIndexCounter)
	{
		// get int distribution with new range
		std::uniform_int_distribution<> dis(0, currentIndexCounter);
		const int randomIndex = dis(mt);

		if (*iter != elements.at(randomIndex))
		{
			std::swap(elements.at(randomIndex), *iter);
		}
	}

	std::cout << "\nAfter: ";
	std::copy(elements.cbegin(), elements.cend(),
		std::ostream_iterator<int>(std::cout, " "));

	return 0;
}