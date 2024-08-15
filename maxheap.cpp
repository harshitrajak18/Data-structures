#include<iostream>
#include<vector>
using namespace std;
class maxheap
{
    public:
    vector<int> heap;
    int parent(int i)
    {
        return (i-1)/2;
    }
    void heapup(int index)
    {
        if(index && heap[parent(index)]<heap[index])
        {
            swap(heap[index],heap[parent(index)]);
            heapup(parent(index));
        }

    }
    void print()
    {
        for(auto i:heap)
        {
            cout<<i<<" ";
        }
    }
    void insert(int data)
    {
          heap.push_back(data);
        int index = heap.size() - 1;
        heapup(index);
    }
};
int main()
{
    maxheap m;
    m.insert(10);
    m.insert(20);
    m.insert(30);
    m.insert(40);
    m.print();
}