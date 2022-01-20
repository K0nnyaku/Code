#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100100
int t;
int n,len,a[N],vis[N];
string s;
string b;
void ss(int tot)
{
	
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		cin>>s;
		len=s.length();
		if(s[0]==s[len-1])
		{
			bool vis=0;
			int l=0,r=len-1;
			while(l<r)
			{
				if(s[l]==s[r])
				l++,r--;
				else 
				{
					printf("-1\n");
					vis=1;
					break;
				}
			}
			if(vis) continue;
			else
			{
				for(int j=1;j<=2*n;j++)
				printf("L");
				printf("\n");
				continue;
			}
			continue;
		}
		
	}
	return 0;
} 
