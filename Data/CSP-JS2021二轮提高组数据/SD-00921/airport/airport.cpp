#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=100010;
int n,m,mm,ans,ans1,ans2,flag[M],flagg[M];
struct node
{
	int a,b;
}t[M],f[M];
bool com(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&t[i].a,&t[i].b);
	for(int i=1;i<=mm;i++)
		scanf("%d%d",&f[i].a,&f[i].b);
	sort(t+1,t+1+m,com);sort(f+1,f+1+mm,com);
	for(int i=0;i<=n;i++)
	{
		memset(flag,0,sizeof(flag));
		memset(flagg,0,sizeof(flagg));
		ans1=0;ans2=0;
//		cout<<i<<" ";
		for(int j=1;j<=m;j++)
		{
			int cnt=0;
			int la=j-1;
			while(la>0)
				{
					if(flag[la]&&t[j].a<t[la].b)
					cnt++;
					la--;
				}
				if(cnt<=i-1)
				{
					ans1++;
//					cout<<j<<"¡¡"; 
					flag[j]=1;
				}
		}
//		cout<<endl<<i<<" "; 
		for(int j=1;j<=mm;j++)
		{
			int cnt=0;
			int la=j-1;
			while(la>0)
			{
				if(flagg[la]&&f[j].a<f[la].b)
				cnt++;
				la--;
			}
			if(cnt<=n-i-1)
			{
				ans2++;
//				cout<<j<<" ";
				flagg[j]=1;
			}
		}
		ans=max(ans,ans1+ans2);
//		cout<<endl;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
