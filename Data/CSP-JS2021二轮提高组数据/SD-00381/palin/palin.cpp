#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
int T;
int n;
int a[1000007];
int wz[1000007][2];
int sl[1000007];
int js=0;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		js=0;
		n=read();
		for(int i=1;i<=n;++i)
		wz[i][0]=wz[i][1]=0;
		for(int i=1;i<=2*n;++i)
		{
			a[i]=read();
			if(wz[a[i]][0])
			wz[a[i]][1]=i;
			else
			wz[a[i]][0]=i;
		}
		a[0]=17891789,a[2*n+1]=-17891789;
		int l1=1,r1=2*n,l2,r2;
		l2=wz[a[l1]][1]-1;
		r2=wz[a[l1]][1]+1;
		++js;
		sl[js]=sl[2*n-js+1]=a[l1];
		++l1;
		bool pd=0;
		while(js<n)
		{
			if(a[l1]==a[l2]&&l1<l2&&wz[a[l1]][wzz[l1]^1]>l1&&wz[l1][wzz[a[l1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[l1];
				++l1;
				--l2;
			}
			else if(a[l1]==a[r2]&&l1<r2&&wz[l1][wzz[a[l1]]^1]>l1&&wz[l1][wzz[a[l1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[l1];
				++l1;
				++r2;
			}
			else if(a[r1]==a[l2]&&r1>l2&&wz[r1][wzz[a[r1]]^1]>l1&&wz[r1][wzz[a[r1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[r1];
				--r1;
				--l2;
			}
			else if(a[r1]==a[r2]&&r1>r2&&wz[r1][wzz[a[r1]]^1]>l1&&wz[r1][wzz[a[r1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[r1];
				--r1;
				++r2;
			}
			else
			{
				pd=1;
				break;
			}
		}
		if(pd)
		{
			pd=0,js=0;
			l1=1,r1=2*n;
			l2=wz[a[r1]][0]-1;
			r2=wz[a[r1]][0]+1;
			++js;
			sl[js]=sl[2*n-js+1]=a[r1];
			//cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<" "<<sl[js]<<endl;
			--r1;
			pd=0;
			while(js<n)
		{
			if(a[l1]==a[l2]&&l1<l2&&wz[a[l1]][wzz[l1]^1]>l1&&wz[l1][wzz[a[l1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[l1];
				++l1;
				--l2;
			}
			else if(a[l1]==a[r2]&&l1<r2&&wz[l1][wzz[a[l1]]^1]>l1&&wz[l1][wzz[a[l1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[l1];
				++l1;
				++r2;
			}
			else if(a[r1]==a[l2]&&r1>l2&&wz[r1][wzz[a[r1]]^1]>l1&&wz[r1][wzz[a[r1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[r1];
				--r1;
				--l2;
			}
			else if(a[r1]==a[r2]&&r1>r2&&wz[r1][wzz[a[r1]]^1]>l1&&wz[r1][wzz[a[r1]]^1]<r1)
			{
				++js;
				sl[js]=sl[2*n-js+1]=a[r1];
				--r1;
				++r2;
			}
			else
			{
				pd=1;
				break;
			}
		}
		}
		if(pd==1)
		{
			puts("-1");
			continue;
		}
		int l=1,r=2*n;
		for(int i=1;i<=2*n;++i)
		{
			if(sl[i]==a[l])
			putchar('L'),++l;
			else if(sl[i]==a[r])
			putchar('R'),--r;
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
