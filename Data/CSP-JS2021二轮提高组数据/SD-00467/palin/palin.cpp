#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
char ans[5000009],a[5000009],b[5000009],flag;
int t,n;
int head=1,tail;char q[5000009];
int main()
{
		freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
     cin>>t;
     for(int u=1;u<=t;u++)
     {
     	cin>>n;
	   for(int i=1;i<=2*n;i++)
       cin>>a[i];
       flag=0;
	 //  dfs(1,2*n,1,0,1);
	   if(flag==0) cout<<"-1"<<endl;
	 }
	

	return 0;
	
	
}

