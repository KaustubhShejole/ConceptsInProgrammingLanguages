#include "general.h"

int near_bigfib(const int& n)
{
    int ret_val;
    int prev = 1;  //denotes previous fibonacci number
    int pprev = 0;  //denotes previous to previous fibonacci number
    if( n==0){
        ret_val = 0;
    }
    else if(n < 0)
    {
        cout<<"heap size cannot be negative";
        ret_val = -1;
    }
    else
    {
        int k = prev + pprev;
        while(k<=n){
            //k denotes the term less than equal to n to be added in fibo_list
            fibo_list.append(k);
            pprev = prev;
            prev = k;
            k = prev + pprev;
        }
        ret_val = prev;
    }
    return ret_val;
}
int near_fib(int n,string sign=">=")
{
    int prev = 1;   //denotes previous fibonacci number
    int pprev = 0;  //denotes previous to previous fibonacci number
    if (n==0){
        return 0;
    }
    else
    {
        int k = prev + pprev;
        while(k<=n)
        {
            //k denotes the term less than equal to n to be added in fibo_list
            pprev = prev;
            prev = k;
            k = prev + pprev;
        }
        if(sign==">=")
        {
            if(prev==n)
                return prev;
            else
                return k;
        }
        else if(sign==">"){
            return k;
        }
        else if(sign=="<"){
            return pprev;
        }
    }
}
void populate_free_list()
{
    int len = fibo_list.size();
    free_list_array.make_space(len);
    int i;
    for(i =0;i<len;i++)
    {
        free_list_array[i] = empty_list;
    }
    free_list_array[len-1].append(0);
}
void populate_filled_list()
{
    int len = fibo_list.size();
    filled_list_array.make_space(len);
    int i;
    for(i =0;i<len;i++)
    {
        filled_list_array[i] = empty_list;
    }
}