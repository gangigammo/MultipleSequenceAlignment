#include <iostream>
#include <fstream>
#include "Blossum62.h"
#include "PairDP.h"
#include "StarMethod.h"
int N = 6;
vector<string> name(N);
vector<string> align(N);

void input(){
  ifstream ifs("./alignment.txt");
  std::string str;

  if (ifs.fail()) {
    std::cerr << "Failed to open file." << std::endl;
    return;
  }
  for(int i = 0;i < N;i++){
    getline(ifs, str);
    name[i] = str;
    getline(ifs, str);
    align[i] = str;
  }
}

void run(){
  StarMethod sm = StarMethod(N,name,align);
  sm.run();
}


int main() {
  input();
  run();
  return 0;
}
