#ifndef BID_H
#define BID_H

#include <vector>

struct Bid {
  int id;
  std::vector<int> regions;
  double payment;
  Bid(std::vector<int> regions, double payment, int id)
      : regions(regions), payment(payment), id(id) {}
};

#endif
