#ifndef BID_H
#define BID_H

#include <vector>

struct Bid{
	int id;
	std::vector<int> regions;
	float payment;
	Bid(std::vector<int> regions, float payment, int id) : regions(regions), payment(payment), id(id) {}
};

#endif