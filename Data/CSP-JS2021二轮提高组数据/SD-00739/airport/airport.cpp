#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<map>
using namespace std;
long long n,m1,m2;
long long mm1,mm2;
long long num1,num2;
long long l1,l2;
pair<long long,long long> q1[100050],q2[100050];
bool vis1[100050],vis2[100050];
long long ans1[100050],ans2[100050],ans;
long long read()
{
	long long f=1,sum=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9')
	{
		sum*=10;
		sum+=ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read(); 
	mm1=m1;
	mm2=m2;
	for(int i=1;i<=m1;i++)
	{
		q1[i].first=read();
		q1[i].second=read();
	}
	for(int i=1;i<=m2;i++)
	{
		q2[i].first=read();
		q2[i].second=read();
	}
	if(n>=m1+m2) printf("%lld",m1+m2);
	else{
		sort(q1+1,q1+m1+1);
		sort(q2+1,q2+m2+1);
		for(int i=1;i<=n;i++)
		{
			if(!mm1){
				ans1[i]=m1;
				continue;
			} 
			else{
				num1=0;
				l1=0;
				for(int j=1;j<=m1;j++)
				{
					if(q1[j].first<l1) continue;
					else if(!vis1[j]){
						vis1[j]=1;
						mm1--;
						num1++;
						l1=q1[j].second;
					}
				}
				ans1[i]=ans1[i-1]+num1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!mm2){
				ans2[i]=m2;
				continue;
			} 
			else{
				num2=0;
				l2=0;
				for(int j=1;j<=m2;j++)
				{
					if(q2[j].first<l2) continue;
					else if(!vis2[j]){
						vis2[j]=1;
						mm2--;
						num2++;
						l2=q2[j].second;
					}
				}
				ans2[i]=ans2[i-1]+num2;
			}
		}
		for(int i=0;i<=n;i++)
		{
			ans=max(ans,ans1[i]+ans2[n-i]);
		}	
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
