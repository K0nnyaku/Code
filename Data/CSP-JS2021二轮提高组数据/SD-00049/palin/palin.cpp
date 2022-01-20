#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#define N 10100
using namespace std;
int T,n,a[N],b[N];
void read(int &x)
{
	char c;x=0;int f=1;
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	x*=f;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--)
	{
		string s1,s2;
		int flag=0;
		read(n);
		for(int i=1;i<=n*2;++i)
			read(a[i]),b[2*n-i+1]=a[i],s1+=(a[i]+'0'); 
		for(int i=1;i<=n*2;++i)s2+=(b[i]+'0');
		string ans;string num;
		int l=1,r=2*n+1;
		ans+='L';num=(a[1]+'0');
		while(ans.size()<2*n)
		{
			string now1=num;
			now1+=(a[l+1]+'0');
			string now2=num;
			now2+=(a[r-1]+'0');
			string m1,m2;int len=now1.size();
			for(int i=0;i<len;++i)m1+=s1[i];
			//for(int i=0;i<len;++i)m2+=s2[i+len];
			//cout<<now1<<"!!!"<<endl;
			//cout<<m1<<"###"<<endl;
			int k1,k2,p1,p2;
			if(now1==m1)
			{
				m1.clear();
				for(int i=0;i<s1.size()-len;++i)m1+=s1[i+len];
				for(int i=0;i<s2.size()-len;++i)m2+=s2[i+len];
				k1=m1.find(now1),k2=m2.find(now1);
				p1=m1.find(now2),p2=m2.find(now2);
			}
			else
			{
				k1=s1.find(now1),k2=s2.find(now1);
				p1=s1.find(now2),p2=s2.find(now2);
			}
			//cout<<m1<<"!!!"<<endl;
			//cout<<m2<<"???"<<endl;
			if(k1==-1&&k2==-1&&p1==-1&&p2==-1)
			{
				printf("-1\n");
				flag=1;
				break;
			}
			if(k1!=-1||k2!=-1)
			{
				ans+='L';l++;
				num+=(a[l]+'0');
			}
			else
			{
				ans+='R';r--;
				num+=(a[r]+'0');
			}
			if(ans.size()==n)break;
		}
		if(flag==1)continue;
		string fn;
		for(int i=l+1;i<=r-1;++i)fn+=(a[i]+'0');
		l=0,r=n+1;int p=n-1;
		while(p>0)
		{
			if(fn[l]==num[p])ans+='L',l++,p--;
		else ans+='R',r--,p--;
		}
		ans+='L';
		cout<<ans<<endl;
	}
	
	return 0;
}
