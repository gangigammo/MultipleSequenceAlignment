//
// Created by 吉川純平 on 2020-06-07.
//

#ifndef MULTIPLEALLIGNMENT_STARMETHOD_H
#define MULTIPLEALLIGNMENT_STARMETHOD_H


#include "PairDP.h"

class StarMethod : public PairDP{
public:
    vector<string> multipleAlignment;
    StarMethod();
    StarMethod(int maxnum,vector<string> name,vector<string> str);
    int decideStar();
    void searchPairStr(int x,int y,int cnt);
    void showPairAlignment(int piv);
    string combineStar(string str1,string str2);
    bool finishable(vector<bool> vec);
    void solveStarAlignment(int piv);
    void showMultipleAlignment();
    void run();
};


#endif //MULTIPLEALLIGNMENT_STARMETHOD_H
