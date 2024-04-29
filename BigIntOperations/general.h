#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

typedef unsigned long long int Itemtype;
const int size = 64;


typedef struct Big1024_Int_type
{
    int lower1[size];
    int lower2[size];
    int lower3[size];
    int lower4[size];
    int lower5[size];
    int lower6[size];
    int lower7[size];
    int lower8[size];
    int upper1[size];
    int upper2[size];
    int upper3[size];
    int upper4[size];
    int upper5[size];
    int upper6[size];
    int upper7[size];
    int upper8[size];
}Big_Int;

#endif