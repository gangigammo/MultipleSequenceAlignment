//
// Created by 吉川純平 on 2020-06-06.
//

#include "Blossum62.h"
using namespace std;

Blossum62::Blossum62() {
  pos.resize(MAXCHAR);
  for(int i = 0;i < MAXCHAR;i++){
    pos[i] = -1;
  }
  for(int i = 0;i < ord.size();i++){
    for(int j = 0;j < ord.size();j++){
      if(arr[i][j] != arr[j][i]){
        cout << i << " " << j << endl;
      }
    }
  }
  unsigned int len = ord.size();
  for(int i = 0;i < len;i++){
    pos[ord[i] - 'A'] = i;
  }
}
