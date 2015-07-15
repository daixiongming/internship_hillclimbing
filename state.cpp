#include "state.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <random>

State State::findNewState(std::vector<Bid> bids){
	/*
	*	copy this into newState
	*	choose random bid in bids where bid is not in usedBids
	*		if bid can be added
	*			add bid to newState.usedBids
	*		else
	*			add bid to newState
	*			find conflicts in newState
	*			if there exists confbid in newState.usedBids where confbid contains conflicts and confbid != bid
	*				remove confbid from newState.usedBids
	*			else 
	*				remove bid from newState.usedBids
	*				continue
	*/

	while(true){
		int bidIndex = std::rand() % bids.size();
		bool unused = true;
		for (Bid b : usedBids) {
			if (b.id == bids[bidIndex].id)
				unused = false;
		}
		if(unused) {
			State newState = *this;
			Bid bid = bids[bidIndex];
			if (newState.isValidWithBid(bid)) {
				newState.addBid(bid);
				return newState;
			}
			else {
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
			if (std::find(bid.regions.begin(), bid.regions.end(), i) != bid.regions.end()) {
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
				if (std::find(bid.regions.begin(), bid.regions.end(), j) != bid.regions.end()) {
					return false;
				}
			}
		}
	}
	return true;
}

void State::addBid(Bid b) {
	usedBids.push_back(b);
}

void State::swapBids(int toRemove, Bid toAdd) {
	usedBids[toRemove] = toAdd;
}

float State::totalValue() {
	float val;
	for (Bid b : usedBids) {
		val += b.payment;
	}
	return val;
}

void State::clear() {
	usedBids.clear();
}