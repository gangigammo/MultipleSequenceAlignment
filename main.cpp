#include <iostream>
#include "Blossum62.h"
#include "PairDP.h"
#include "StarMethod.h"
int N = 6;
vector<string> name(N);
vector<string> align(N);

void input(){
  for(int i = 0;i < N;i++){
    cin >> name[i];
    cin >> align[i];
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
