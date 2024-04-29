#include"list.h"
void DeleteList(Node** lpptr)
{
    Node* lptr = *lpptr;
    Node* nptr;
    nptr = lptr;
    while(nptr!=NULL)
    {
        lptr = lptr->next;
        delete nptr;
        nptr = lptr;
    }
    *lpptr = lptr;
}
Node* InsertAtEnd(const Itemtype& j, Node* lptr)
{
    Node* eptr;
    eptr = new Node;
    eptr->data = j;
    eptr->next = NULL;
    Node* nptr;
    nptr = lptr;
    if(lptr==NULL)
    {
        lptr=eptr;
    }
    else
    {
        while(nptr->next != NULL)
        {
            nptr = nptr->next;
        }
        nptr->next=eptr;
    }
    return lptr;
}
Node* DeleteValue(const Itemtype& i,Node* lptr)
{
    Node* nptr;
    nptr=lptr;
    if(nptr->data == i)
    {
        lptr = lptr->next;
        delete nptr;
    }
    else
    {
        Node* ptr;
        ptr = nptr;
        nptr = nptr->next;
        int status;
        status = 0;
        while(nptr!= NULL && status==0)
        {
            if(nptr->data == i)
            {
                ptr->next = nptr->next;
                delete nptr;
                status = 1;
                break;
            }
            else
            {
                ptr = nptr;
                nptr = nptr->next;
            }
        }
    }
    return lptr;
}
void DisplayList(Node* lptr)
{
    cout<<"[ ";
    if(lptr !=NULL)
    {
        while(lptr->next != NULL)
        {
            cout<<lptr->data<<" , ";
            lptr =lptr->next;
        }
        cout<<lptr->data;
    }
    cout<<" ]";
}
Itemtype& k_value(Node* lptr,int j)
{
    int k=0;
    while(j!=k && lptr->next != NULL)
    {
        lptr = lptr->next;
        k++;
    }
    if(j==k)
    {
        return lptr->data;
    }
}
list::list():lptr(NULL) {}
list::~list()
{
    DeleteList(&lptr);
    lptr = NULL;
}
void list::append(const Itemtype& j)
{
    lptr = InsertAtEnd(j,lptr);
}
void list::remove(const Itemtype& j)
{
    lptr = DeleteValue(j,lptr);
}
ostream& operator<<(ostream& out,const list& l)
{
    DisplayList(l.lptr);
    return out;
}
list& list::operator=(const list& l)
{
    if(*this == l)
    {
        return *this;
    }
    DeleteList(&lptr);
    lptr = NULL;
    Node* nptr;
    nptr = l.lptr;
    while(nptr!=NULL)
    {
        (*this).append(nptr->data);
    }
    return *this;
}
bool list::operator==(const list& l) const
{
    if((*this).size() != l.size() )
    {
        return false;
    }
    Node *nptr1,*nptr2;
    nptr1 = lptr;
    nptr2 = l.lptr;
    int status;
    status = 0;
    while(nptr1 != NULL && status==0)
    {
        if(nptr1->data != nptr2->data)
        {
            status = 1;
        }
        else{
            nptr1 = nptr1->next;
            nptr2 = nptr2->next;
        }
    }
    switch(status)
    {
        case 0: return true;
        break;
        case 1: return false;
        break;
    }
}
int list::size() const
{
    Node* nptr;
    nptr = lptr;
    int i;
    i = 0;
    while(nptr!=NULL)
    {
        i++;
        nptr = nptr->next;
    }
    return i;
}
int list::index(const Itemtype& j) const
{
    int ret_val;
    ret_val = -1;

    Node* nptr;
    nptr = lptr;
    int i;
    i = 0;
    if(nptr!=NULL)
    {
        while(nptr->data!= j && nptr->next != NULL)
        {
            i++;
            nptr = nptr->next;
        }
        if(nptr->data == j)
        {
            ret_val = i;
        }
    }
    return ret_val;
}
Itemtype& list::operator[](int k)
{
    return (k_value(lptr,k));
}
/*int main()
{
    cout << "Hello World!\n";
    list l;
    l.append(1);
    cout<<l;
    l.append(2);
    cout<<l;
    l.append(3);
    cout<<l;
    l.remove(3);
    cout<<l;
    list l2;
    l2.append(1);
    l2.append(2);
    if(l==l2)
    {
        cout<<'k';
    }
    l2[1] = 67;
    cout<<l2;
    cout<<l.index(1);
    return 0;
}*/