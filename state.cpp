#include "state.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <random>

State State::findNewState(std::vector<Bid> bids) {
  if (usedBids.size() == bids.size()) {
    return *this;
  }

  State newState = *this;

  while (true) {
    int bidIndex = std::rand() % bids.size();

    bool unused = true;
    for (Bid b : usedBids) {
      if (b.id == bids[bidIndex].id)
        unused = false;
    }

    if (unused) {
      Bid bid = bids[bidIndex];
      if (newState.isValidWithBid(bid)) {
        newState.addBid(bid);
        return newState;
      } else {
        int bidToRemoveIndex = std::rand() % usedBids.size();
        if (newState.isValidWithSwap(bidToRemoveIndex, bid)) {
          newState.swapBids(bidToRemoveIndex, bid);
          return newState;
        }
      }
    }
  }
}

std::string State::toString() {
  std::stringstream ss;
  for (Bid b : usedBids) {
    ss << b.payment << ": ";
    for (int i : b.regions) {
      ss << i << " ";
    }
    ss << std::endl;
  }
  return ss.str();
}

bool State::isValidWithBid(Bid bid) {
  for (Bid b : usedBids) {
    for (int i : b.regions) {
      if (std::find(bid.regions.begin(), bid.regions.end(), i) !=
          bid.regions.end()) {
        return false;
      }
    }
  }
  return true;
}

bool State::isValidWithSwap(int toRemove, Bid bid) {
  for (int i = 0; i < usedBids.size(); i++) {
    if (i != toRemove) {
      for (int j : usedBids[i].regions) {
        if (std::find(bid.regions.begin(), bid.regions.end(), j) !=
            bid.regions.end()) {
          return false;
        }
      }
    }
  }
  return true;
}

void State::addBid(Bid b) { usedBids.push_back(b); }

void State::swapBids(int toRemove, Bid toAdd) { usedBids[toRemove] = toAdd; }

float State::totalValue() {
  float val = 0;
  for (Bid b : usedBids) {
    val += b.payment;
  }
  return val;
}

void State::clear() { usedBids.clear(); }
