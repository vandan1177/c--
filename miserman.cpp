#include<bits/stdc++.h>

using namespace std;
long long int n,m,t;
long long int arr[1000][1000];
long long int memo[1000][1000];
int mex(long long int a,long long int b,long long int c)
{
    if(a<b)
        if(a<c)
        return a;
    if(b<a)
        if(b<c)
        return b;
    if (c<a)
        if(c<b)
        return c;
}
int rec(long long int x,long long int y)
{

    if(y==4)
        cout<<"pos: "<<x+1<<" "<<memo[x][y]<<"   "<<arr[x][y]<<endl;
    if (y>=m||y<0)
        return 0;
    if (memo[x][y]!= -1)
    {
        return memo[x][y];
    }
    if (x==0){//cout<<x<<" "<<y<<endl;
        return memo[x][y] = arr[x][y];}
    return memo[x][y] = mex(rec(x-1,y-1),rec(x-1,y),rec(x-1,y+1))+arr[x][y];
}
int main()
{
    cin>>t;
    for(long long int z=0;z<t;z++)
    {

    cin>>n>>m;
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            memo[i][j]=-1;
        }
    }

    //for(long long int i=0;i<m;i++)
    //{
        rec(n-1,3);
    //}
    long long int result=0;
    for(long long int i=0;i<m;i++)
    {
        if(memo[n-1][i]>result)
            result=memo[n-1][i];
    }
    cout<<result<<endl;
    }
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
}
