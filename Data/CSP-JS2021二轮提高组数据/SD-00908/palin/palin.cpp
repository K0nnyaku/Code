#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int n,book,k;
int a[500005],b[500005];
char ans[500005];
void baoli(int head,int l,int r)
{
	if(book==1)return;
	if(head==2*k+1)
	{
		for(int i=1;i<=2*k;i++)
		{
			cout<<ans[i];
		}
		book=1;
		return;
	}
//	if(head>=k+2)
//	{
//		if(b[2*k-head+2]!=b[head-1])return;
//	}
	if(head<=k)
	{
		b[2*k-head+1]=a[l];
		ans[head]='L';
		baoli(head+1,l+1,r);
		if(book==1)return;
		b[2*k-head+1]=a[r];
		ans[head]='R';
		baoli(head+1,l,r-1);
	}
	if(head>=k+1)
	{
		if(b[head]==a[l])
		{
			b[2*k-head+1]=a[l];
			ans[head]='L';
			baoli(head+1,l+1,r);
			if(book==1)return;
		}
		else
		{
			if(b[head]==a[r])
			{
				b[2*k-head+1]=a[r];
				ans[head]='R';
				baoli(head+1,l,r-1);
			}
			else
			return;
		}
	}

}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		book=0;
		cin>>k;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=2*k;i++)
		{
			scanf("%d",&a[i]);
		}
		baoli(1,1,2*k);
		if(book==0)
		cout<<-1;
		cout<<endl;
	}
	return 0;
}
