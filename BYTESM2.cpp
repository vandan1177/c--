#include<bits/stdc++.h>

using namespace std;
int n,m;
int arr[1000][1000];
int memo[1000][1000];
int max(int a,int b,int c)
{
    if(a>b)
        if(a>c)
        return a;
    else
        if(b>c)
        return b;
    if (c>a)
        if(c>b)
        return c;
}
int rec(int x,int y)
{
    cout<<memo[x][y]<<" ";
    if(x==n)
        return 0;
    else
        return memo[x][y] = max(rec(x+1,y),rec(x+1,y-1),rec(x+1,y+1))+arr[x][y];
}
int main()

{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            memo[i][j]=0;
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<memo[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<rec(0,2);
}
