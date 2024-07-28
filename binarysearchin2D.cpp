#include<iostream>
#include<vector>
using namespace std;

bool binary(vector<vector<int>> & matrix,int target)
{
    int row=matrix.size();
    int col=matrix[0].size();
    int left=0;
    int right=row*col-1;

    while(left<=right)
    {
        int mid=left+(right-left)/2;
        int midelement=matrix[mid/col][mid%col];
        if(midelement==target)
        {
            return true;
        }
        else if(midelement<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }

    }
    return false;


}
int main()
{
    vector<vector<int>> matrix = {
       {1, 4},
        {2, 5},
        {3,4}
    };

    bool check=binary(matrix,2);
    cout<<check;
    
}