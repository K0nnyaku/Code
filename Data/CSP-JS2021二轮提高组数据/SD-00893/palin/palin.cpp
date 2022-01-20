#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
int n,k;
char a[1000001],b[1000001];
char ans[1000001];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>k;
	while(k--)
	{
		cin>>n;
		if(n<18)
		{
			for(int i=1;i<=2*n;i++)
			cin>>a[i];
			if(a[1]==a[2*n])
			{
				cout<<"-1";
				continue;
			}	
		}
		else if(n>=18&&n<=20)
		{
			for(int i=1;i<=2*n;i++)
			cin>>a[i];
			for(int i=1;i<=n;i++)
			swap(a[i],a[n-i+1]);
			for(int i=n;i<=2*n;i++)
			{
				b[i-n]=a[i];
				a[i]='0';b[i]='0';
			}
			if(strcmp(a,b)==1)
			for(int i=1;i<=2*n;i++)
			cout<<"L";
			else
			cout<<"-1";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

