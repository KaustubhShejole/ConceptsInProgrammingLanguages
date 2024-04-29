#ifndef GENERAL_H
#define GENERAL_H
#include"listarray.h"
#include"list.h"
extern list empty_list;
extern array_of_list free_list_array;
extern list fibo_list; 
extern array_of_list filled_list_array;
int near_bigfib(const int& size);
int near_fib(int request,string);
void populate_free_list();
void populate_filled_list();
void print(const list* arr);

#endif