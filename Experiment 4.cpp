#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct linklist
{
    node *head,*tail;
    linklist()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_beg();
    void show();
    void insert();
    void deletion();
    void searching();
};
node* createnode(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void linklist::insert_beg()
{
    int n;
    cout<<"Enter the no. of elements you want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        node *p,*ptr;
        p=createnode(b);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            p->next=head;
            head->prev=p;
            head=p;
        }
    }
    tail->next=head;
    head->prev=tail;
}
void linklist::insert()
{
    int ch,b,x;
    cout<<"\nEnter choice:\n1 for insertion in beginning\n2 for insertion at end\n3 for insertion in between\n";
    cin>>ch;
    node *p=NULL,*temp,*ptr;
    while(ch!=0)
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter the element to add: ";
            cin>>b;
            p=createnode(b);
            p->next=head;
            head->prev=p;
            head=p;
            tail->next=head;
            head->prev=tail;
            break;
        case 2:
            cout<<"Enter the element to add: ";
            cin>>b;
            p=createnode(b);
            tail->next=p;
            p->prev=tail;
            tail=p;
            tail->next=head;
            head->prev=tail;
            break;
        case 3:
            cout<<"\nEnter an element you want to add: ";
            cin>>b;
            cout<<"Enter the element after you want to add: ";
            cin>>x;
            p=createnode(b);
            ptr=head;
            while(ptr->data!=x)
            {
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=p;
            p->prev=ptr;
            temp->prev=p;
            p->next=temp;
            break;
        default:
            cout<<"Wrong choice\nPlease enter 1-3 else 0 to exit.";
            break;
        }
        cout<<"\nEnter choice to insert: ";
        cin>>ch;
    }
    cout<<"\nElement Inserted";
}
void linklist::deletion()
{
    int b;
    cout<<"\nEnter an element you want to delete: ";
    cin>>b;
    node *temp,*p;
    p=head;
    if(head->data==b)
    {
        head=head->next;
        tail->next=head;
        head->prev=tail;
    }
    else if(tail->data==b)
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
    }
    else
    {
        while(p->data!=b)
        {
            p=p->next;
        }
        temp=p->prev;
        temp->next=p->next;
        p->next->prev=temp;
    }
    cout<<"\nElement deleted";
}
void linklist::searching()
{
    int b;
    cout<<"Enter element you want to search: ";
    cin>>b;
    node *p;
    p=head;
    while(p->data!=b && p->next!=head)
    {
        p=p->next;
    }
    if(p->data==b)
        cout<<"\nNode exists";
    else
        cout<<"\nNode does not exist";
}
void linklist::show()
{
    node *ptr=head;
    if(head==NULL)
        cout<<"Linked List is empty";
    else
        while(ptr->next!=head)
        {
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<ptr->data;
}
int main()
{
    int ch;
    linklist q;
    q.insert_beg();
    cout<<"\nEnter choice:\n1 for insertion\n2 for deletion\n3 for searching\n4 for display\n";
    cin>>ch;
    while(ch!=0)
    {
        switch(ch)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deletion();
            break;
        case 3:
            q.searching();
            break;
        case 4:
            q.show();
            break;
        default:
            cout<<"\nWrong choice\n";
            break;
        }
        cout<<"\nEnter choice again:\n1 for insertion\n2 for deletion\n3 for searching\n4 for display\n";
        cin>>ch;
    }
}
