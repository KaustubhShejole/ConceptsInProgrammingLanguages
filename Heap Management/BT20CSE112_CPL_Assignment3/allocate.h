#ifndef ALLOCATE_H 
#define ALLOCATE_H
int allocate(int request);
int satisfy_demand(int,int);
int allocate_helper(int,int,bool);
int arrange(int,int);
int malloc(int);
#endif