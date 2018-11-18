#include<iostream>
#include<string>
using namespace std;
char stack1[20];
int top=-1;
int precision(char c)
{
    if(c== '^'|| c== '$')
    return 3;
    else if(c == '*' || c == '/'|| c=='%')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
void push(char val)
{
    top=top+1;
    stack1[top]=val;
}
int pop()
{
top=top-1;
}
void intoposfix(string s)
{
    int l;
    l = s.length();
    push('N');
    string n;
    for(int i=0;i<l;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        {
            n=n+s[i];
        }
        else if(s[i]=='(')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while(stack1[top]!='N' && stack1[top]!='(' )
            {
                char c = stack1[top];
                pop();
                n=n+c;
            }
            if(stack1[top]=='(')
            {
                pop();

            }
        }
        else
        {
            while(stack1[top]!='N' && precision(s[i])<=precision(stack1[top]))
            {
                char c = stack1[top];
                pop();
                n=n+c;
            }
            push(s[i]);
        }
    }
    while(stack1[top]!='N')
    {
        char c = stack1[top];
        pop();
        n=n+c;
    }
    cout<<"the answer is "<<n;
}
int main()
{
string exp;
cout<<"enter the string";
cin>>exp;
intoposfix(exp);
}
