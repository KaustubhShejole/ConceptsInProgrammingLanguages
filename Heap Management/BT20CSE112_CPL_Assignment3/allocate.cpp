#include "general.h"
#include "allocate.h"
int satisfy_demand(int demand,int index)
{
    int ret_val;
    ret_val = free_list_array[index][0];
    filled_list_array[index].append(free_list_array[index][0]);
    free_list_array[index].remove(free_list_array[index][0]);
    cout<<"Successfully allocated given request"<<endl;
    return ret_val;
}
int arrange(int demand,int index)
{
    int ret_val,fib1,fib2;
    ret_val = -1;
    fib1 = fibo_list[index-1];
    if(index - 1==0)
    {   if (demand == 1)
        {  
            free_list_array[index-1].append((free_list_array[index][0]));
            free_list_array[index-1].append(free_list_array[index][0]+1);
        }
    }
    else
    {
        fib2 = fibo_list[index-2];
        free_list_array[index-2].append(free_list_array[index][0]);
        free_list_array[index-1].append(free_list_array[index][0]+fib2);
    }
    free_list_array[index].remove(free_list_array[index][0]);
    
    if( fib1 == demand)
        ret_val = satisfy_demand(demand,index-1);
    else if (fib2 == demand)
        ret_val = satisfy_demand(demand,index-2);
    else
        ret_val = arrange(demand,index-2);
    return ret_val;
}
int allocate_helper(int demand,int index,bool repeated=false)
{
    int ret_val;
    ret_val = -1;
    if( free_list_array[index] == empty_list) //we don't have block of this demand size in free_list_array
       ret_val = allocate_helper(demand,index+1,true);
    else
    {
        if(repeated==false) //it means that we get exactly same size in 1st step:
            ret_val = satisfy_demand(demand,index);
        else
            ret_val = arrange(demand,index);
    }
    return ret_val;
}
int allocate(int r)
{
    int ret_val,demand,index;
    ret_val = -1;
    if(r<=0)
    {
        cout<<"Invalid Request"<<endl;
        return -1;
    }
    if(r>fibo_list[(fibo_list).size()-1])
    {
        cout<<"Insufficient Memory"<<endl;
        return -1;
    }
    demand = near_fib(r,">=");
    index = fibo_list.index(demand);
    ret_val = allocate_helper(demand,index);
    return ret_val;
}
int malloc(int request)
{
    /*allocates space for given request on heap and return the address of
    allocated block otherwise returns NULL here with value -1*/
    int var = allocate(request);
    if(var==-1)
        cout<<"Returned NULL";
    return var;
}
