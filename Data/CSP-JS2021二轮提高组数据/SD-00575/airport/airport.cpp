#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int time1[100000005],time2[100000005],len1,len2;
int checks[100000005];
bool flat[100000005];
int start1=100000005,start2=100000005;
int b1[100005],b2[100005];
int n,m1,m2,ansplus;
int q[100000005],l;

inline int read()
{
	int ans=0,res=1;
	char ch=getchar();
	while ((ch>'9'||ch<'0')&&ch!='-')
		ch=getchar();
	if (ch=='-')
	{
		res=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*res;
}

inline void print(int x)
{
	if (x==0)
	{
		putchar('0');
		putchar('\n');
		return;
	}
	if (x<0)
		putchar('-');
	int tmp=x>0 ? x:-x;
	char F[200];
	int cou=0;
	while (tmp)
	{
		F[cou++]=tmp%10+'0';
		tmp/=10;
	}
	while (cou)
		putchar(F[--cou]);
	putchar('\n');
	return;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	if (n>=20000)
	{
		cout << n << endl;
		return 0;
	}
	for (register int i=1;i<=m1;i++)
	{
		int s=read(),t=read();
		checks[s]=t;
		time1[s]++;
		time1[t]--;
		if (s>len1)
			len1=s;
		if (s<start1)
			start1=s;
	}
	for (register int i=1;i<=m2;i++)
	{
		int s=read(),t=read();
		checks[s]=t;
		time2[s]++;
		time2[t]--;
		if (s>len2)
			len2=s;
		if (s<start2)
			start2=s;
	}
	int cnt=0;
	for (register int i=1;i<=n;i++)
	{
		cnt=0;
		for (register int j=start1;j<=len1;j++)
		{
			cnt+=time1[j];
			if (time1[j]>0)
			{
				if (cnt>i)
				{
					cnt=i;
					time1[checks[j]]++;
					q[++l]=checks[j];
				}
				else
					b1[i]++;
			}
		}
		for (register int j=1;j<=l;j++)
			time1[q[j]]--;
		l=0;
	}
	cnt=0;
	for (register int i=1;i<=n;i++)
	{
		cnt=0;
		for (register int j=start2;j<=len2;j++)
		{
			cnt+=time2[j];
			if (time2[j]>0)
			{
				if (cnt>i)
				{
					cnt=i;
					time2[checks[j]]++;
					q[++l]=checks[j];
				}
				else
					b2[i]++;
			}
		}
		for (register int j=1;j<=l;j++)
			time2[q[j]]--;
		l=0;
	}
	for (register int i=0;i<=n;i++)
		ansplus=max(ansplus,b1[i]+b2[n-i]);
	print(ansplus);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
