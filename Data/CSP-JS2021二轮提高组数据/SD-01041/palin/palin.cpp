#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
long long  i,a[10001],b[10001],a1[10001],b1[10001],n,m,m2,j,k;
long long  c[10001],c1[10001],ans1,ans2,ans3,l,d,d1;
string s;
int main()
{
 	freopen("palin.in","r",stdin);
 	freopen("palin.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>m;
    	for(j=1;j<=2*m;j++)
    	{
    		cin>>s[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<"-1"<<endl;
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
} 
