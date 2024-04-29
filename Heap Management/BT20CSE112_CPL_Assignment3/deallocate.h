#ifndef DEALLOCATE_H
#define DEALLOCATE_H
#include"listarray.h"
#include "general.h"

void free(int address);
void deallocate(int address);
void merge_blocks(int index,int address);
#endif