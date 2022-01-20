#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
int t;
int main()
{   freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
    cin>>t;
    int b[t+1];
    for(int i=1;i<=t;i++)
       {cin>>b[i];
       for(int j=1;j<=(2*b[i]);j++)
          {if(j%2==0)
             cout<<"R"<<" ";
            else
              cout<<"l"<<" ";
		  }}
    return 0;
}
