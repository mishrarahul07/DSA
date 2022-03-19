#include<iostream>
using namespace std;

class queue
{
    int front, rear, cap;
    int * arr;
    public: void qenqueue(int x);
            int qdequeue();
            int qfront();
            bool isfull();
            bool isempty();
            queue(int c)
            {
                this->cap=c;
                arr=new int[cap];
                front=rear=0;
            }
};
void queue::qenqueue(int x)
{
    if(isfull())
    {
        cout<<"Overflow occurred ";
        return;
    }
    arr[rear]=x;
    rear=(rear+1)%cap;
    cout<<x<<" added to queue"<<endl;
}

int queue::qdequeue()
{
    if(isempty())
    {
        cout<<"Underflow occurred ";
        return -1;
    }
    int ele=arr[front];
    front=(front+1)%cap;
    return ele;
}

int queue::qfront()
{
    if(isempty())
    {
        cout<<"Underflow occurred ";
        return -1;
    }
    else
    return arr[front];
}

bool queue::isempty()
{
    if(rear==front)
    return true;
    else
    return false;
}

bool queue::isfull()
{
    if((front==0&&rear==cap-1)||(front-rear==1))
    return true;
    else
    return false;
}

int main()
{
    cout<<"Enter the capacity of the queue :";
    int capacity;
    cin>>capacity;
    queue q(capacity);

    cout<<q.isempty()<<" ";
    cout<<q.qdequeue()<<" ";
    q.qenqueue(20);
    q.qenqueue(30);
    q.qenqueue(40);
    cout<<q.isfull()<<" ";
    q.qenqueue(50);
    cout<<q.qfront()<<" ";
    cout<<q.qdequeue()<<" ";
    cout<<q.qfront()<<" ";
    cout<<q.isfull()<<" ";
    q.qenqueue(60);
    q.qenqueue(70);
    cout<<q.qfront()<<" ";
    return 0;
}