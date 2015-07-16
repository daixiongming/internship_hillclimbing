#ifndef HILLCLIMBER_H
#define HILLCLIMBER_H

#include "state.h"

class HillClimber {
public:
  HillClimber();
  void run(std::string file);
  void populateBidsFromFile(std::string filename);
  void writeBidsToFile(std::string filename);
  State bestState;
  State currentState;

private:
  std::vector<Bid> bids;
  double runtime;
  State next;
};

#endif
