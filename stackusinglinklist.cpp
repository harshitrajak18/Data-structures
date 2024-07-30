#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class stack
{
    public:
    node * top;
    stack()
    {
        top=nullptr;

    }
    void push(int x)
    {
        node * newnode = new node(x);
        if(top==nullptr)
        {
            top=newnode;

        }
        else
        {
            newnode->next=top;
            top=newnode;
        }
    }
    void pop()
    {
        if(top==nullptr)
        {
            cout<<"stack underflow"<<endl;
        }
        else
        {
            node * temp=top;
            top=top->next;
            delete(temp);
        }
    }
   
    int peek()
    {
        if(top==nullptr)
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return top->data;
    }
    void show()
    {
        node * temp=top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }


};
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(50);
    st.show();


}