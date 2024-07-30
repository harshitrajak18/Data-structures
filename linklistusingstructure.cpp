#include<iostream>
using namespace std;
struct node
{
    int data;
    node * next;
};
//node * head= nullptr;
//node * tail=nullptr;
node * create(int data)
{
    node * newnode =new node();
    newnode->data=data;
    newnode->next=nullptr;
    return newnode;
}
void insert(node* &head ,node * &tail,int data)
{
    node * newnode= create(data);
    if(head==nullptr)
    {

        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}
void print(node * & head)
{
    node * temp=head;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    node * head=nullptr;
    node * tail=nullptr;
    insert(head,tail,10);
    insert(head,tail,20);
    insert(head,tail,30);
    print(head);
}
