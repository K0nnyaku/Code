#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+5;

int n,m1,m2,ans1[N],ans2[N],last[N],cnt[N],p[N],num,ans;
vector<int> next;

struct air
{
	int ent,exi;
} a[N],b[N];

bool cmp(air x,air y)
{
	return x.ent<y.ent;
}

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return x*f;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++) a[i].ent=read(),a[i].exi=read();
	for(int i=1;i<=m2;i++) b[i].ent=read(),b[i].exi=read();
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
//	ans1[1]=ans2[1]=1;
//	ans1[0]=ans2[0]=0;
	cnt[1]=1;
	next.push_back(1);
	for(int i=2;i<=m1;i++)
	{
		if(a[i].ent>a[cnt[1]].exi)
		{
			next.push_back(i);
			cnt[1]=i;
		}	
	}
	cnt[1]=0;
	for(int k=0;k<next.size();k++)
	{
		int h=1;
		for(int i=next[k];i<=m1;i++)
		{
//			p[i-next[k]+1]++;
			for(int j=h;j<=n;j++)
			{
				if(p[j]==j&&a[i].ent>a[next[k]].exi)
				{
					h++;
				}
				else if(p[j]<j)
				{
//					cout<<"###"<<j<<" "<<cnt[j]<<" "<<i<<endl;
					if(cnt[j]>=i)
					{
						continue;
					}
					if(a[i].ent>a[cnt[j]].exi&&i!=next[k])
					{
						p[j]--;
					}
					ans1[j]++;
					cnt[j]=i;
					p[j]++;
					
				}
				else if(a[i].ent>a[cnt[j]].exi)
				{
//					cout<<k<<" "<<a[i].ent<<" "<<a[cnt[j]].exi<<" "<<p[j]<<" "<<ans1[2]<<endl;
					ans1[j]++;
					cnt[j]=i;
					
				}
				
//				cout<<k<<" :"<<i<<" "<<j<<" "<<cnt[j]<<" "<<p[j]<<" "<<ans1[j]<<endl;
			}
			if(h>n)
			{
				break;
			}
		}
		memset(p,0,sizeof(p));
	}
	memset(cnt,0,sizeof(cnt));
	next.clear();
	next.push_back(1);
	cnt[1]=1;
	for(int i=2;i<=m2;i++)
	{
		if(b[i].ent>b[cnt[1]].exi)
		{
			cnt[1]=i;
			next.push_back(i);
		}
	}
	cnt[1]=0;
	for(int k=0;k<next.size();k++)
	{
		int h=1;
		for(int i=next[k];i<=m2;i++)
		{
			for(int j=h;j<=n;j++)
			{
				if(p[j]==j&&b[i].ent>b[next[k]].exi)
				{
					h++;
				}
				else if(p[j]<j)
				{
					if(cnt[j]>=i)
					{
						continue;
					}
					if(b[i].ent>b[cnt[j]].exi&&i!=next[k])
					{
						p[j]--;
					}
					ans2[j]++;
					cnt[j]=i;
					p[j]++;
				}
				else if(b[i].ent>b[cnt[j]].exi)
				{
					ans2[j]++;
					cnt[j]=i;
				}
			}
			if(h>n)
			{
				break;
			}
		}
		memset(p,0,sizeof(p));
	}
	ans=max(ans1[n],ans2[n]);
	for(int i=0;i<=n;i++)
	{
//		cout<<i<<" "<<ans1[i]<<" "<<ans2[n-i]<<" "<<endl;
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
