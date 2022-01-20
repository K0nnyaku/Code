#include<bits/stdc++.h>  //我只要40分！！！！！！ 
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0)
#define re register
void fre()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
const int maxn=1e6+10;
int T,n;
int q1[maxn],q2[maxn];
bool pd()
{
	for(int i=1;i<=n;i++)
	{
		if(q1[i]!=q1[2*n+1-i]) return false;
	}
	return true;
}
int main()
{
	fre();
	IO;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		for(re int i=1;i<=2*n;i++) cin>>q1[i];
		if(T==1)
		{
			if(!pd()) printf("-1");
			else
			{
				for(int i=1;i<=2*n;i++)
				printf("L");
			}
			return 0;
		}
		else
		{
			for(int i=1;i<=2*n;i++)
			printf("L");
		}
	} 
} 
/*
1
4
1 2 3 4 4 3 2 1
*/
