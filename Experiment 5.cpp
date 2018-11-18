#include<bits/stdc++.h>
using namespace std;
#define MAX 6
int Stack[MAX];
int top = -1;
void push(int x);
void pop();
void show();
int main ()
{
int a, val;
a = -1;
while(a !=4)
    {
cin>> a;
switch(a)
{
case 1:
cin>>val;
push(val);
break;
case 2:
pop();
break;
case 3:
show();
break;
default:
break;
}
cout<<"a please"<<endl;
}
return 0;
}
void push(int x)
{   if(top==MAX)
    cout<<"overflow "<<endl;
    else
   {
    Stack[top+1]=x;
    top++;
   }
}
void pop()
{ if(top==-1)
cout<<"underflow!"<<endl;
else
{
    cout<<"deleted element is"<<" "<<Stack[top--]<<endl;
}
}
void show()
{for(int i=top;i>-1;i--)
cout<<Stack[i]<<" ";
cout<<endl;
}

