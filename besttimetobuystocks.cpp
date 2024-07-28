#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int> arr={7,1,5,3,6,4};
    int maxi=0;
    int mini=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]-mini);

    }
    cout<<maxi;
    
}