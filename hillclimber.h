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
  std::vector<Bid> bids{Bid({1, 5, -1}, 8, 0), Bid({1, 4, -1}, 9, 1),
                        Bid({2, 3, -2}, 3, 2),
                        Bid({0, 1, 2, 3, 4, 5, -2}, 13, 3)};
  State next;
};

#endif
