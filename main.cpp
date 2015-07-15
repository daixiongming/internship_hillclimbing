#include <iostream>
#include <random>
#include <ctime>

#include "state.h"
#include "bid.h"
#include "hillclimber.h"

int main() {
  std::srand(time(0));

  HillClimber hc;

  hc.run();

  std::cout << hc.bestState.toString() << std::endl;
}
