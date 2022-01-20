#include<iostream>
#include<cstdio>
using namespace std;
const int N = 3e5+5;
int T,n,a[N];
int fst[N];
int snd[N];
int lef,rig;
string ans;
bool vis[N];
int check(bool flag,int big)
{
	int cnt = 0;
	int l = lef,r = rig;
	if(!flag) l++;
	else r--;
	while(1)
	{
		if(!vis[a[l]])
		{
			cnt++;
			l++;
		}
		else break;
	}
	while(1)
	{
		if(!vis[a[r]])
		{
			cnt++;
			r--;
		}
		else break;
	}
	return cnt;
}
int added()
{
	return(lef-1)+(2*n-rig); 
}
void work()
{
	while(1)
	{
		if(vis[a[lef]])
		{
			;
		}
		if(check(0,a[lef])>=(2*n-added()+1))
		{
			ans+='L';
			vis[a[lef]] = 1;
			lef++;
		}
		else if(check(1,a[rig])>=(2*n-added()+1))
		{
			ans += 'R';
			vis[a[rig]] = 1;
			rig--;
		}
	}
	
}
int main ()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans = "#";
		bool flag = 0;
		scanf("%d",&n);
		lef = 1;rig = 2*n;
		for(int i = 1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
			if(!fst[a[i]])
			{
				fst[a[i]] = i;
			}
			else
			{
				if((i-fst[a[i]]-1)%2 != 0)
				{
					printf("-1\n");
					flag = 1;
				}
				snd[a[i]] = i;
			}
		}
		if(flag) continue;
	}
	
	//4 5 3 1 2 2 1 3 5 4
	//4 5 3 1 2 2 1 3 5 4
	return 0;
}
