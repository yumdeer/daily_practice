#include <iostream>

class Timer {
public:
	Timer();
};

class TimeKeeper {
public:
	TimeKeeper(const Timer& t);

	int get_time();
};

int main() {
	//TimeKeeper time_keeper(Timer());
	TimeKeeper time_keeper{ Timer{} };
	return time_keeper.get_time();
}