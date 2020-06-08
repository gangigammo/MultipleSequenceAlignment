//
// Created by 吉川純平 on 2020-06-07.
//

#ifndef MULTIPLEALLIGNMENT_DP_H
#define MULTIPLEALLIGNMENT_DP_H
#include <iostream>
#include "Blossum62.h"
#include <vector>

using namespace std;

class PairDP : public Blossum62{
public:
    int MAXNUM;
    const int MAXSIZE= 100;
    const int GAP = 0;
    vector<string> name;
    vector<string> str;
    vector<int> sum;
    vector<vector<int>> pairScore;
    vector<vector<int>> dp;
    vector<vector<string>> pairStr;
    PairDP();
    PairDP(int maxnum,vector<string> name,vector<string> str);
    template<class T> bool chmax(T &a, const T &b);
    int calcScore(char a,char b);
    void cleardp();
    void embdp(int x,int y);
    void calcPairScore();
};


#endif //MULTIPLEALLIGNMENT_DP_H
