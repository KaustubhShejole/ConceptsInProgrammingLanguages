#include "general.h"
#include "listarray.h"
#include "allocate.h"
#include "deallocate.h"
list empty_list;
array_of_list free_list_array;
list fibo_list; 
array_of_list filled_list_array;
int main()
{
    cout<<"Welcome to simulation Heap Management: "<<endl;
    cout<<"Please enter the actual size : ";
    int size;
    cin>>size;
    int heap_size;
    heap_size = near_bigfib(size);

    cout<<"Our program has a heap size of "<<heap_size<<endl;
    cout<<"initial free and filled lists:"<<endl;
    populate_free_list();
    populate_filled_list();
    cout<<(free_list_array);
    cout<<(filled_list_array);

    /*int var = malloc(1);
    cout<<"After Doing int var = malloc(1);"<<endl;
    cout<<"var = "<<var<<endl;
    cout<<(free_list_array);
    cout<<(filled_list_array)<<endl;

    int var1 = malloc(1);
    cout<<"After Doing int var1 = malloc(1);"<<endl;
    cout<<"var1 = "<<var1<<endl;
    cout<<(free_list_array);
    cout<<(filled_list_array)<<endl;

    int var2 = malloc(22);
    cout<<"After Doing int var2 = malloc(22);"<<endl;
    cout<<"var2 = "<<var2<<endl;
    cout<<(free_list_array);
    cout<<(filled_list_array)<<endl;

    cout<<"free(var)"<<endl;
    free(var);
    cout<<(free_list_array);
    cout<<(filled_list_array)<<endl;

    cout<<"free(var1)"<<endl;
    free(var1);
    cout<<(free_list_array);
    cout<<(filled_list_array)<<endl;

    cout<<"free(var2)"<<endl;
    free(var2);
    cout<<free_list_array;
    cout<<filled_list_array;
    */
    
    int var = malloc(9);
    int var2 = malloc(10);
    int var3 = malloc(43);
    int var4 = malloc(3);

    free(var3);
    free(var2);
    free(var4);
    free(var);

    cout<<free_list_array<<endl;
    return 0;
}