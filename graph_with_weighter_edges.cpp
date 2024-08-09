#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class graph
{
    public:
    int v;
    vector<pair<int,int>> *adj;
    graph(int v)
    {
        this->v=v;
        adj=new vector<pair<int,int>>[v];


    }
    void addedge(int u,int v, int weight)
    {
        adj[u].push_back({v,weight});
    }
    void show()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"vertex:"<<i<<"->";
            for(auto u:adj[i])
            {
                cout<<"("<<u.first<<","<<u.second<<")";
            }
            cout<<endl;
        }
    }
    void alledgessum()
    {
        int sum=0;
        for(int i=0;i<v;i++)
        {
            for(auto u:adj[i])
            {
                sum=sum+u.second;
            }
        }
        cout<<"the sum of all the vertices of the graph is :"<<sum<<endl;
    }
    void ptedges(int start,int end)
    {
        int sum=0;
        for(int i=start;i<end;i++)
        {
            for(auto u:adj[i])
            {
                sum=sum+u.second;
            }

        }
        cout<<sum<<endl; 
    }
    void mwv()
    {
        int maxi=0;
        int init=0;
        int final=0;
        for(int i=0;i<v;i++)
        {
            for(auto u:adj[i])
            {
                if(u.second>maxi)
                {
                    maxi=u.second;
                    init=i;
                    final=u.first;

                }
               

            }
        }
        cout<<"the maximum weighted vertices of this graph is between: "<<init<<" and "<<final<<endl;
    }
    void bfs(int start)
    {
        vector<bool> visited(v,false);
        queue<int> q;
        visited[start]=true;
        q.push(start);
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            cout<<current;
            visited[current]=true;
            for(auto i=adj[current].begin();i!=adj[current].end();i++)
            {
                if(visited[i->first]==false)
                {
                    q.push(i->first);
                    visited[i->first]=true;


                }
            }
        }




    }
    void bffs(int start)
    {
        vector<int> visited(v,false);
        queue<int>q;
        q.push(start);
        visited[start]=true;
        while(!q.empty())
        {
            int current=q.front();
            cout<<current;
            visited[current]=true;
            for(auto i=adj[current].begin();i!=adj[current].end();i++)
            {
                if(visited[i->first]==false)
                {
                    q.push(i->first);
                    visited[i->first]=true;
                }
            }
        }

    }
    void dfs(int n)
    {
        vector<bool> visited(v,false);
        stack<int> s;
        s.push(n);
        while(!s.empty())
        {
            int current=s.top();
            s.pop();

            if(visited[current]==false)
            {
                visited[current]=true;
                cout<<current;

                for(auto u:adj[current])
                {
                    if(visited[u.first]==false)
                    {
                        s.push(u.first);
                    }
                }
            }
        }


    }

};
int main()
{
    graph g(6);
    g.addedge(0,1,10);
   // g.addedge(0,1,2);
    g.addedge(1,2,4);
    g.addedge(2,4,6);
    g.addedge(4,5,8);
    g.addedge(4,4,10);
    g.addedge(3,5,5);
    g.addedge(5,3,7);
   
   // g.show();
    //g.alledgessum();
   // g.ptedges(0,2);
   // g.mwv();
   //g.bfs(5);
   g.dfs(4);
}