#ifndef STATE_H
#define STATE_H

#include "bid.h"
#include <vector>
#include <string>

class State {
public:
  State findNewState(std::vector<Bid> bids);
  std::string toString();
  bool isValidWithBid(Bid bid);
  bool isValidWithSwap(int toRemove, Bid bid);
  void addBid(Bid b);
  void swapBids(int toRemove, Bid toAdd);

  std::vector<Bid> getBids() {
  	return usedBids;
  }

  double totalValue();

  void clear();

private:
  std::vector<Bid> usedBids;
};

#endif
