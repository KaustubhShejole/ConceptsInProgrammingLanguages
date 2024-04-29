#include "general.h"
#include "calls.h"

void to_binary(Itemtype &num,int arr[],int size)
{
    for(int i=size-1;i>=0;i--)
    {
        arr[i] = num%2;
        num = num/2;
    }
    
    if(num>0)
    {
        cout<<"error"<<endl;
    }
}
void PrintArray(int* array,int size)
{
    int i; //index for looping
    for(i=0;i<size;i++)
    {
        cout<<array[i];
    }
}
void InitializeArray(int* array,int size)
{
    int i; //index for looping
    for(i=0;i<size;i++)
    {
        array[i] = 0;
    }
}
void Initialize(Big_Int* b)
{
    InitializeArray(b->lower1,size);
    InitializeArray(b->lower2,size);
    InitializeArray(b->lower3,size);
    InitializeArray(b->lower4,size);
    InitializeArray(b->lower5,size);
    InitializeArray(b->lower6,size);
    InitializeArray(b->lower7,size);
    InitializeArray(b->lower8,size);
    InitializeArray(b->upper1,size);
    InitializeArray(b->upper2,size);
    InitializeArray(b->upper3,size);
    InitializeArray(b->upper4,size);
    InitializeArray(b->upper5,size);
    InitializeArray(b->upper6,size);
    InitializeArray(b->upper7,size);
    InitializeArray(b->upper8,size);
}
void WriteOutBig_Int(Big_Int* b)
{
    PrintArray(b->upper8,size);
    PrintArray(b->upper7,size);
    PrintArray(b->upper6,size);
    PrintArray(b->upper5,size);
    PrintArray(b->upper4,size);
    PrintArray(b->upper3,size);
    PrintArray(b->upper2,size);
    PrintArray(b->upper1,size);
    PrintArray(b->lower8,size);
    PrintArray(b->lower7,size);
    PrintArray(b->lower6,size);
    PrintArray(b->lower5,size);
    PrintArray(b->lower4,size);
    PrintArray(b->lower3,size);
    PrintArray(b->lower2,size);
    PrintArray(b->lower1,size);
}
Itemtype to_decimal(int arr[],int size)
{
    Itemtype result = 0;
    int k =1;
    for(int i=size-1;i>=0;i--)
    {
        result = result + k*arr[i];
        k = k*2;
    }
    return result;
}
int overflow(Itemtype num1,Itemtype num2,int carry=0)
{
    if((num1+num2+carry)<max(num1,num2))
    {
        return 1;
    }
    else{
        return 0;
    }
}
void InitializeNumber(Big_Int* b)
{
    Initialize(b);

    cout<<"Please enter the number in Binary Format:\n";
    char str[1025];
    cin>>str;

    WriteInBig_Int(str,b);

    cout<<"\nThe Data is as follows :\n";
    WriteOutBig_Int(b);
    cout<<endl;

}
int add(int arr1[],int arr2[],int result[],int carry)
{
    Itemtype num1 = to_decimal(arr1,size);
    
    
    
    Itemtype num2 = to_decimal(arr2,size);
    
    
    Itemtype num3 = num1 + num2 + carry;
    
    int ans = 0;
    if(!(num1==0 && num2==0 && carry == 0))
    {
        ans = overflow(num1,num2,carry);
    }
    if(ans==1)
    {
        carry = 1;
        
        
        to_binary(num3,result,size);
        
        cout<<endl<<"carry = "<<carry<<endl;
    }
    else if(ans == 0)
    {
        to_binary(num3,result,size);
        carry = 0;
    }
    else
    {
        cout<<"error"<<endl;
    }
    return carry;
}
void AddBig_Ints(Big_Int* b1,Big_Int* b2,Big_Int* b3)
{
    int carry;
    carry = 0;
    carry = add(b1->lower1,b2->lower1,b3->lower1,carry);
    carry = add(b1->lower2,b2->lower2,b3->lower2,carry);
    carry = add(b1->lower3,b2->lower3,b3->lower3,carry);
    carry = add(b1->lower4,b2->lower4,b3->lower4,carry);
    carry = add(b1->lower5,b2->lower5,b3->lower5,carry);
    carry = add(b1->lower6,b2->lower6,b3->lower6,carry);
    carry = add(b1->lower7,b2->lower7,b3->lower7,carry);
    carry = add(b1->lower8,b2->lower8,b3->lower8,carry);
    carry = add(b1->upper1,b2->upper1,b3->upper1,carry);
    carry = add(b1->upper2,b2->upper2,b3->upper2,carry);
    carry = add(b1->upper3,b2->upper3,b3->upper3,carry);
    carry = add(b1->upper4,b2->upper4,b3->upper4,carry);
    carry = add(b1->upper5,b2->upper5,b3->upper5,carry);
    carry = add(b1->upper6,b2->upper6,b3->upper6,carry);
    carry = add(b1->upper7,b2->upper7,b3->upper7,carry);
    carry = add(b1->upper8,b2->upper8,b3->upper8,carry);
    if(carry!=0)
    {
        cout<<"Overflow happened\n";
        exit(1);
    }
}
void WriteInBig_Int(char* str,Big_Int* b)
{
    int length;
    length = strlen(str);
    int i,j; //index for looping
    i = length - 1;
    j = 0;
    int temp;
    while(i>=0 && j<size)
    {
        temp = str[i] - '0';
        b->lower1[size-j-1] = temp;
        
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower2[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower3[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower4[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower5[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower6[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower7[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->lower8[size-j-1] = temp;
        i--;
        j++;
    }
    j = 0;
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper1[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper2[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper3[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper4[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper5[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper6[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper7[size-j-1] = temp;
        i--;
        j++;
    }
    while(i>=0)
    {
        temp = str[i] - '0';
        
        b->upper8[size-j-1] = temp;
        i--;
        j++;
    }
    //if the loop terminated because i == 0 then is fine because we have already initialized Big_Int datatype variable
}