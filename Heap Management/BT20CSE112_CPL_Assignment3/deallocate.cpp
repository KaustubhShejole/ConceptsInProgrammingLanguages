#include "deallocate.h"
#include "listarray.h"
#include "general.h"
bool search_in_list(const Itemtype& i,list& l)
{
    if(l.index(i) != -1)
    {
        return true;
    }
    else{
        return false;
    }
}
void free(int address)
{
    deallocate(address);
}
void deallocate(int address)
{
    int index;
    index = filled_list_array.index(address);
    filled_list_array[index].remove(address); //removed address from filled_list
    if(index == -1)
    {
        cout<<"not allocated or is out of range";
    }
    else
    {
        if((index != 0) && (search_in_list((address-fibo_list[index-1]),(free_list_array[index-1]))))
        {   
            free_list_array[index].append(address);
            address = address - fibo_list[index-1];
            free_list_array[index-1].remove(address); //removing previous address from free_list
            merge_blocks(index-1,address);
        }
        else if((index==0) && (search_in_list(address-1,free_list_array[0])))
        {
            address = address-1;
            free_list_array[0].remove(address);
            merge_blocks(1,address);
        }
        else if((index==0)&& (search_in_list(address+1,free_list_array[0])))
        {
            free_list_array[0].remove(address+1);
            merge_blocks(1,address);
        }
        else
        {
            merge_blocks(index,address);
        }
    }
}
void merge_blocks(int index,int address)
{
    /*merges block in index with next index block and check if next exists if
    exists then called merge_blocks(index+1,addresss) else just puts this address at index+1*/
    int j,addr,naddr;
    j = address;
    if(index!= 0 && search_in_list(j-fibo_list[index-1],free_list_array[index-1]))
    {    if(! search_in_list(j,free_list_array[index]))
        {
            free_list_array[index].append(j);
            j = j - fibo_list[index-1];
            free_list_array[index-1].remove(j); //removing previous address from free_list
            index = index - 1;
        }
    }

    address = j;
    addr = address;
    naddr = address + fibo_list[index]; //address of next block
    
    if (index+1 < free_list_array.len()-1 && search_in_list(naddr,free_list_array[index+1]))
    { 
        //found so remove that address from index+1 and check now for index+1
        free_list_array[index+1].remove(naddr);
        if(index+2< free_list_array.len()) //not going to give error otherwise also
        {
            merge_blocks(index+2,addr);
        }
    }
    else
    {
        free_list_array[index].append(addr);
    }
}