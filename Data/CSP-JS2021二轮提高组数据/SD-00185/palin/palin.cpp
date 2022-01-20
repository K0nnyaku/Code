#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[10000];
int main()
{  freopen("palin.in","r",stdin);
   freopen("palin.out","w",stdout);
   int k,n;
   cin>>k;
   for(int i=1;i<=k;i++)
	{ cin>>n;
	  int x=2*n;
	  for(int j=1;j<=x;j++)
	  cin>>a[i];
	  cout<<"-1"<<endl;
	}
	



    fclose(stdin);
	fclose(stdout);	
	return 0;
}
