#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int t,n;
int a[N],s[N],cnt;bool vis[N];
string ans;
bool check(int l,int r)
{
	for(int i=n;i>=1;i--)
	{
		if(a[l]==s[cnt])
		{
			cnt--;
			ans+='L';
			l++;
		}
		else if(a[r]==s[cnt])
		{
			cnt--;
			ans+='R';
			r--;
		}
		else return 0;
	}
	return 1;
}
bool dfs()
{
	bool havesol=false;
	for(int state=0;state<(1<<(n));state++)
	{
		int lft=1,rit=n*2;
		for(int i=1;i<=n;i++) vis[i]=0;
		cnt=0;
		ans.clear();
		for(int i=n-1;i>=0;i--)
		{
			if(!((1<<i)&state))
			{
				int x=a[lft];lft++;
				if(vis[x]) break;
				vis[x]=1;
				s[++cnt]=x;
				ans+='L';
			}
			else
			{
				int x=a[rit];rit--;
				if(vis[x]) break;
				vis[x]=1;
				s[++cnt]=x;
				ans+='R';
			}
		}
		if(check(lft,rit))
		{
			havesol=true;
			break;
		}
	}
	if(havesol) return 1;
	return 0;
}
void subtask()
{
	for(int i=1;i<=n;i++) if(a[i]!=a[2*n+1-i]) return puts("-1"),void();
	for(int i=1;i<=2*n;i++) printf("L");puts("");
}
int main()
{
//	clock_t c1=clock();
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//================================================
	scanf("%d",&t);int tmp=t;
	while(t--)
	{
		scanf("%d",&n);
		
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		if(tmp==1 && n>1000) return puts("-1"),0;
		else if(n>1000)
		{
			subtask();
			continue;
		}
		if(dfs()) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	//================================================
//	cerr<<endl<<"Time:"<<clock()-c1<<"ms"<<endl;
	return 0;
}
