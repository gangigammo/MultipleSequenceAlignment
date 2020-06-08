//
// Created by 吉川純平 on 2020-06-07.
//

#include <algorithm>
#include "StarMethod.h"
#define all(x) (x).begin(),(x).end()

StarMethod::StarMethod(){

}

StarMethod::StarMethod(int maxnum, vector<string> name, vector<string> str) : PairDP(maxnum, name, str) {
  multipleAlignment.resize(MAXNUM);
}

int StarMethod::decideStar(){
  calcPairScore();
  for(int i = 0;i < MAXNUM;i++) {
    for (int j = 0; j < MAXNUM; j++) {
      sum[i]+=pairScore[i][j];
      //cout << pairScore[i][j] << " ";
    }
    //cout << endl;
  }
  int piv = -1;
  int pivscore = -1;
  for(int i = 0;i < MAXNUM;i++){
    //cout << sum[i] << endl;
    if(sum[i] > pivscore){
      piv = i;
      pivscore = sum[i];
    }
  }
  return piv;
}

void StarMethod::searchPairStr(int x,int y,int cnt){
  int i = str[x].size();
  int j = str[y].size();
  while(i != 0 || j != 0){
    if(i != 0 && dp[i][j] - dp[i-1][j] == GAP){
      pairStr[cnt][0] += str[x][i-1];
      pairStr[cnt][1] += "-";
      i--;
    }else if(j != 0 && dp[i][j] - dp[i][j-1] == GAP){
      pairStr[cnt][0] += "-";
      pairStr[cnt][1] += str[y][j-1];
      j--;
    }else{
      pairStr[cnt][0] += str[x][i-1];
      pairStr[cnt][1] += str[y][j-1];
      i--;
      j--;
    }
  }
  reverse(all(pairStr[cnt][0]));
  reverse(all(pairStr[cnt][1]));
}

void StarMethod::showPairAlignment(int piv){
  int cnt = 0;
  for(int i = 0;i < MAXNUM;i++){
    if(i == piv) continue;
    printf("%5s",name[i].c_str());
    cout << ":  " << pairStr[cnt][0] << endl;
    printf("%5s",name[piv].c_str());
    cout << ":  " << pairStr[cnt][1] << endl;
    cnt++;
    cout << endl;
  }
}

void StarMethod::solveAlignment(int piv){
  int cnt = 0;
  for(int i = 0;i < MAXNUM;i++){

  }
}

void StarMethod::run(){
  int piv = decideStar();

  int cnt = 0;
  for(int i = 0;i < MAXNUM;i++){
    if(i == piv)continue;
    embdp(i,piv);
    searchPairStr(i,piv,cnt);
    cnt++;
  }

  showPairAlignment(piv);

  solveAlignment(piv);
}
