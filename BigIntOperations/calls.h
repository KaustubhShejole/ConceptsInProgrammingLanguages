#ifndef CALLS_H
#define CALLS_H

#include "general.h"
void to_binary(Itemtype &num,int arr[],int size);
void PrintArray(int* array,int size);
void InitializeArray(int* array,int size);
void Initialize(Big_Int* b);
void WriteOutBig_Int(Big_Int* b);

int overflow(Itemtype,Itemtype,int);
void InitializeNumber(Big_Int* b);
int add(int arr1[],int arr2[],int result[],int carry);
void AddBig_Ints(Big_Int* b1,Big_Int* b2,Big_Int* b3);
void WriteInBig_Int(char* str,Big_Int* b);
Itemtype to_decimal(int arr[],int size);

#endif