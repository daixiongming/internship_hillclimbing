#include "hillclimber.h"
#include <ctime>
#include <iostream>

HillClimber::HillClimber() {
  currentState.addBid(bids[1]);
  currentState.addBid(bids[2]);

  bestState = currentState;
}

void HillClimber::run() {
  int start = std::clock();
  int i = 0;
  while ((std::clock() - start) / (float)CLOCKS_PER_SEC < .5) {
    i++;
    if (std::rand() % 10000 == 1) {
      currentState.clear();
    }

    State newState = currentState.findNewState(bids);

    if (newState.totalValue() > currentState.totalValue()) {
      currentState = newState;
    }

    if (currentState.totalValue() > bestState.totalValue()) {
      bestState = currentState;
    }
  }
  std::cout << i << std::endl;
}
