#include "hillclimber.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

HillClimber::HillClimber() {
  bestState = currentState;
}

void HillClimber::run(std::string filename) {
  int start = std::clock();

  std::string progressBar = "[";
  for (int i = 0; i < 80; i++) {
    progressBar += "-";
  }
  progressBar += "]";

  populateBidsFromFile(filename);

  runtime = 15;

  int jumpval = 51*bids.size();

  int counter = jumpval;

  int i = 0;
  while ((std::clock() - start) / (double)CLOCKS_PER_SEC < runtime) {
    i++;

    counter--;

    if (i % 50 == 0) {
      float progress = 80*((std::clock() - start) / (double)CLOCKS_PER_SEC) / runtime;
      progressBar[(int)progress+1] = '#';
      std::cout << progressBar << " Best value: " << bestState.totalValue() << '\r';
    }

    if (std::rand() % counter == 0) {
      currentState.clear();
      counter = jumpval;
    }

    State newState = currentState.findNewState(bids);

    if (newState.totalValue() > currentState.totalValue()) {
      currentState = newState;
      counter = jumpval;
    }

    if (currentState.totalValue() > bestState.totalValue()) {
      bestState = currentState;
    }
  }
  std::cout << std::endl;

  writeBidsToFile("answer-" + filename + ".dat");
}

void HillClimber::populateBidsFromFile(std::string filename) { 
  std::ifstream file(filename);
  bids.clear();
  std::string line, dum1, dum2, dum3;
  int bidid = 0;
  std::getline(file, line);
  runtime = std::atoi(line.c_str())*60;
  std::getline(file, line);
  std::getline(file, line);
  std::getline(file, line);
  std::getline(file, line);
  std::getline(file, line);
  std::getline(file, line);
  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string token;

    int companyid;
    std::vector<int> regions;
    double payment;
    ss >> companyid;
    ss >> payment;
    while (ss >> token) {
      if (token[0] != '#') {
        regions.push_back(std::atoi(token.c_str()));
      }
    }
    regions.push_back(-1 - companyid);
    bids.push_back(Bid(regions, payment, bidid));
    bidid++;
    std::getline(file, line);
  }
}

void HillClimber::writeBidsToFile(std::string filename) {
  std::ofstream file(filename);
  for (Bid b : bestState.getBids()) {
    file << b.id << " ";
  }
  file << "#\n";
}