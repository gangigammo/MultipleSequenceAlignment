//
// Created by 吉川純平 on 2020-06-07.
//

#include "PairDP.h"
#include "Blossum62.h"



PairDP::PairDP(){

}

PairDP::PairDP(int maxnum,vector<string> name,vector<string> str):MAXNUM(maxnum),name(name),str(str){
  name.resize(MAXNUM);
  str.resize(MAXNUM);
  sum.resize(MAXNUM);
  pairScore.resize(MAXNUM,vector<int>(MAXNUM));
  dp.resize(MAXSIZE,vector<int>(MAXSIZE));
  pairStr.resize(MAXNUM-1,vector<string>(2));
}

template<class T> bool PairDP::chmax(T &a, const T &b){
  if (a<b) { a=b; return 1; } return 0;
}

int PairDP::calcScore(char a,char b){
  return arr[pos[a-'A']][pos[b-'A']];
}

void PairDP::cleardp(){
  for(int i = 0;i < MAXSIZE;i++){
    for(int j = 0;j < MAXSIZE;j++){
      dp[i][j] = -1000000000;
    }
  }
  dp[0][0] = 0;
}

void PairDP::embdp(int x,int y){
  int val;
  cleardp();
  int len1 = str[x].size();
  int len2 = str[y].size();
  for(int p = 0;p < len1;p++){
    for(int q = 0;q < len2;q++){
      val = calcScore(str[x][p],str[y][q]);
      chmax(dp[p+1][q+1],dp[p+1][q] - GAP);
      chmax(dp[p+1][q+1],dp[p][q+1] - GAP);
      chmax(dp[p+1][q+1],dp[p][q] + val);
    }
  }
}

void PairDP::calcPairScore(){
  int score;
  for(int i = 0;i < MAXNUM;i++){
    for(int j = 0;j < MAXNUM;j++){
      if(i == j)continue;
      embdp(i,j);
      int len1 = str[i].size();
      int len2 = str[j].size();
      score = dp[len1][len2];
      pairScore[i][j] = score;
    }
  }
}