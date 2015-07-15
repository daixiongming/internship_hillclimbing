#include "hillclimber.h"
#include <ctime>
#include <iostream>

HillClimber::HillClimber() {
	currentState.addBid(Bid({ 1, 3, 6 , -2}, 5, 0));
	currentState.addBid(Bid({ 8, 4, 7 , -3}, 3, 2));

	bestState = currentState;
}

void HillClimber::run() {
	int start = std::clock();
	while ((std::clock() - start) / (float)CLOCKS_PER_SEC < .5) {
		State newState = currentState.findNewState(bids);
		if (newState.totalValue() > currentState.totalValue()) {
			currentState = newState;
		}
		if (currentState.totalValue() > bestState.totalValue()) {
			bestState = currentState;
		}
		if (std::rand() % 1000 == 1) {
			currentState.clear();
		}
	}
}