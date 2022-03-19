#include<iostream>
using namespace std;

class stack
{
    int top,cap;
    int * arr;
    public: void push(int x);
            int pop();
            int peek();
            bool isempty();
            bool isfull();
            stack(int c)
            {
                this->cap=c;
                top=0;
                arr = new int[c];
            }
            ~stack()
            {
                delete [] arr;
            }

};

void stack::push(int x)
{
    if(isfull())
    {
        cout<<"Overflow occured"<<endl;
        return;
    }
    arr[top++]=x;
    cout<<x<<" pushed into the stack"<<endl;
}

int stack::pop()
{
    if(isempty())
    {
        cout<<"Underflow occurred ";
        return -1;
    }
    int ele=arr[--top];
    //top--;
    return ele;
}

int stack::peek()
{
    if(isempty())
    {
        cout<<"Underflow occurred ";
        return -1;
    }
    else
    return arr[top-1];
}

bool stack::isempty()
{
    if(top==0)
    return true;
    else
    return false;
}

bool stack::isfull()
{
    if(top==cap)
    return true;
    else 
    return false;
}

int main()
{
    cout<<"enter capacity of stack: ";
    int capacity;
    cin>>capacity;
    stack s(capacity);

    cout<<s.pop()<<" ";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.peek()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.peek()<<" ";
    s.push(60);
    s.push(70);
    return 0;
}