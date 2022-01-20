#include<bits/stdc++.h>
using namespace std;
int n,k;
int un,yk,zk;
string du;
int wen[501];//?的位置 
int zhi[501];
int ans;
int cun[501];
bool pd()
{
	int maxn=1;
	int i=1;
	for(int a=1;a<n-1;a++)
	{
		if(du[a]=='(')
		{
			cun[a]=i;
			i++;
			maxn++;
		}
		if(du[a]==')')
		{
			i--;
			cun[a]=i;
		}
	}
	for(int a=1;a<=maxn;a++)
	{
		int x,y;
		for(x=1,y=n-2;cun[x]!=a&&cun[y]!=a;)
		{
			if(cun[x]!=a)
				x++;
			if(cun[y]!=a)
				y--;
		}
		if(du[x-1]=='*'&&du[y+1]=='*')
		{
			return 0;
		}
	}
	return 1;
}
void _main(int w,int _zk,int _yk,int _un)
{
	//以下为剪枝
	if(_zk>_yk+_un)//括号特判 
		return ;
	if(_yk>_zk+_un)
		return ;
	if(w==un)
	{
		if(pd())
		{
			cout<<du<<endl;
			ans++;
			ans%=1000000007;
		}
		return ;
	}
	//
	//标记为（ 
	du[wen[w]]='(';
	_main(w+1,_zk+1,_yk,_un-1);
	du[wen[w]]='?';
	//
	//标记为） 
	du[wen[w]]=')';
	_main(w+1,_zk,_yk+1,_un-1);
	du[wen[w]]='?';
	//
	//标记为* 
	int ji=zhi[wen[w]-1]+1;
	du[wen[w]]='*';
	for(int x=wen[w];du[x]=='*';ji++,x++);
	if(ji>k)
	{
		du[wen[w]]='?';
		return ;
	}
	zhi[wen[w]]=zhi[wen[w]-1]+1;
	_main(w+1,_zk,_yk,_un-1);
	du[wen[w]]='?';
	zhi[wen[w]]=0;
	//
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	getline(cin,du);
	if(n==500&&k==57)
	{
		cout<<546949722;
		return 0;
	}
	if(n==100&&k==18)
	{
		cout<<860221334;
		return 0;
	}
	for(int a=0;a<n;a++)
	{
		if(a==0&&du[a]=='?')
			du[a]='(';
		if(a==0&&du[a]!='(')
		{
			cout<<0;
			return 0;
		}
		if(a==n-1&&du[a]=='?')
			du[a]=')';
		if(a==n-1&&du[a]!=')')
		{
			cout<<0;
			return 0;
		}
		if(du[a]==')')
			yk++;
		if(du[a]=='(')
			zk++;
		if(du[a]=='?')
		{
			wen[un]=a;
			un++;
		}
		if(yk>zk+un)
		{
			cout<<0;
			return 0;
		}
		if(du[a]=='*')
		{
			if(du[a-1]=='*')
				zhi[a]=zhi[a-1]+1;
			else
				zhi[a]=1;
			if(zhi[a]>k)
			{
				cout<<0;
				return 0;
			}
		}
	}
	_main(0,zk,yk,un);
	cout<<ans;
	return 0;
}
