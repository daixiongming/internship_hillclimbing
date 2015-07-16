#include <iostream>
#include <random>
#include <ctime>

#include "state.h"
#include "bid.h"
#include "hillclimber.h"

int main(int argc, char** argv) {
  std::srand(time(0));

  if (argc < 2) {
  	std::cout << "This program takes one argument: the filename of the input file." << std::endl;
  	return 1;
  }

  HillClimber hc;

  hc.run(argv[1]);

  std::cout << hc.bestState.toString() << std::endl;
}
