#ifndef HILLCLIMBER_H
#define HILLCLIMBER_H

#include "state.h"

class HillClimber {
public:
	HillClimber();
	void run();
	State bestState;
	State currentState;
private:
	std::vector<Bid> bids {
		Bid({1, 5, 10, -1}, 8, 3),
		Bid({3, 5, 8, -1}, 8, 3),
		Bid({ 8, 4, 7 , -3}, 3, 2),
		Bid({ 1, 3, 6 , -2}, 5, 0)
	};
	State next;
};

#endif