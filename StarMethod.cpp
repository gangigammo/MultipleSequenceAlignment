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
  for(int i = 0;i < MAXNUM;i++){
    multipleAlignment[i] = "";
  }
}

int StarMethod::decideStar(){
  calcPairScore();
  for(int i = 0;i < MAXNUM;i++) {
    for (int j = 0; j < MAXNUM; j++) {
      sum[i]+=pairScore[i][j];
      cout << pairScore[i][j] << " ";
    }
    cout << endl;
  }
  int piv = -1;
  int pivscore = -1000000000;
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
    if(i != 0 && dp[i][j] - dp[i-1][j] == -GAP){
      pairStr[cnt][0] += str[x][i-1];
      pairStr[cnt][1] += "-";
      i--;
    }else if(j != 0 && dp[i][j] - dp[i][j-1] == -GAP){
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

bool StarMethod::finishable(vector<bool> vec){
  bool can = true;
  int len = vec.size();
  for(int i = 0;i < len;i++){
    if(vec[i] != true){
      can = false;
    }
  }
  return can;
}

string StarMethod::combineStar(string str1,string str2){
  string comstr = "";
  int len1 = str1.size();
  int len2 = str2.size();
  int pivx = 0;
  int pivy = 0;
  while(len1 != pivx || len2 != pivy){
    if(len1 == pivx){
      comstr += str2[pivy];
      pivy++;
    }else if(len2 == pivy){
      comstr += str1[pivx];
      pivx++;
    }else{
      if(str1[pivx] == '-' && str2[pivy] == '-'){
        comstr += str1[pivx];
        pivx++;
        pivy++;
      }else if(str1[pivx] == '-'){
        comstr += str1[pivx];
        pivx++;
      }else if(str2[pivy] == '-'){
        comstr += str2[pivy];
        pivy++;
      }else{
        comstr += str1[pivx];
        pivx++;
        pivy++;
      }
    }
  }
  return comstr;
}

void StarMethod::solveStarAlignment(int piv){
  string starstr = "";
  for(int i = 0;i < MAXNUM-1;i++){
    starstr = combineStar(starstr,pairStr[i][1]);
  }
  multipleAlignment[piv] = starstr;
  int len = starstr.size();
  int cnt = 0;
  for(int i = 0;i < MAXNUM;i++){
    if(i == piv)continue;
    int pos = 0;
    string substr = "";
    for(int j = 0;j < len;j++){
      if(pairStr[cnt][1][pos] == starstr[j]){
        substr += pairStr[cnt][0][pos];
        pos++;
      }else{
        substr += '-';
      }
    }
    multipleAlignment[i] = substr;
    cnt++;
  }
}

void StarMethod::showMultipleAlignment(int piv){
  for(int i = 0;i < MAXNUM;i++){
    if(i == piv){
      cout << "*";
    }else{
      cout << " ";
    }
    printf("%5s : ",name[i].c_str());
    cout << multipleAlignment[i] << endl;
  }
}

void StarMethod::run(){
  int piv = decideStar();
  cout << piv << endl;

  int cnt = 0;
  for(int i = 0;i < MAXNUM;i++){
    if(i == piv)continue;
    embdp(i,piv);
    searchPairStr(i,piv,cnt);
    cnt++;
  }
  showPairAlignment(piv);
  solveStarAlignment(piv);
  showMultipleAlignment(piv);
}
