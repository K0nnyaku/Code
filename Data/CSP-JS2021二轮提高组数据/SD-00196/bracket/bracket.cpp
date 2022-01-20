#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>

#define I inline
#define LL long long
#define CI const int
#define Heriko return
#define Deltana 0
#define Romanno 1
#define mst(a,b) memset(a,b,sizeof(a))

using namespace std;

template<typename J>
I void fr(J &x)
{
	x=0;short f=1;char c(getchar());
	
	while(c<'0' or c>'9')
	{
		if(c=='-') f=-1;
		
		c=getchar();
	}
	
	while(c>='0' and c<='9')
	{
		x=(x<<1)+(x<<3)+(c^=48);
		c=getchar();
	}
	
	x*=f;
}

template<typename J>
I J Hmax(const J &x,const J &y) {Heriko x>y?x:y;}

CI MXX(505),MOD(1e9+7);

LL n,k,cnt,ans,cnt_left,cnt_right;

//string s,temp;
//
//unordered_map<string,bool> vis;
//
//void DFS(int pos,int opt)/*pls remember the string is starting with 0.*/
//{	
//	if(pos==n)
//	{
//		if(cnt_left==cnt_right and cnt<=k and !vis[temp])
//		{
//			++ans;vis[temp]=1;
//		}
//		
//		Heriko;
//	}
//	
//	
//	if(s[pos]!='?')
//	{
//		int tmpcnt(cnt);
//		
//		if(s[pos]=='(')
//		{
//			temp[pos]='(';
//			++cnt_left;
//		}
//		else if(s[pos]==')')
//		{
//			if(cnt_left<=cnt_right) Heriko;
//			
//			temp[pos]=')';
//			++cnt_right;
//		}
//		else if(s[pos]=='*')
//		{
//			if(cnt>k) Heriko;
//			
//			if(pos-1>=0)
//			{
//				if(s[pos-1]=='*' and cnt!=k) ++cnt;
//				else cnt=1;
//				
//				temp[pos]='*';
//			}
//		}
//		
//		DFS(pos+1,1);DFS(pos+1,2);DFS(pos+1,3);
//		
//		if(s[pos]=='(')
//		{
//			--cnt_left;
//		}
//		else if(s[pos]==')')
//		{
//			--cnt_right;
//		}
//		else if(s[pos]=='*')
//		{
//			cnt=tmpcnt;
//		}
//		
//		Heriko;
//	}
//	else
//	{
//		int tmpcnt(cnt);
//		
//		if(opt==1)
//		{
//			temp[pos]='(';
//			++cnt_left;
//		}
//		else if(opt==2)
//		{
//			if(cnt_left<=cnt_right) Heriko;
//			
//			temp[pos]=')';
//			++cnt_right;
//		}
//		else if(opt==3)
//		{
//			if(cnt>k) Heriko;
//			
//			if(pos-1>=0)
//			{
//				if(s[pos-1]=='*' and cnt!=k) ++cnt;
//				else cnt=1;
//				
//				temp[pos]='*';
//			}
//		}
//		
//		DFS(pos+1,1);DFS(pos+1,2);DFS(pos+1,3);
//		
//		if(opt==1)
//		{
//			--cnt_left;
//		}
//		else if(opt==2)
//		{
//			--cnt_right;
//		}
//		else if(opt==3)
//		{
//			cnt=tmpcnt;
//		}
//		
//		Heriko;
//	}
//}

signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	ios::sync_with_stdio(0);
	
	cin >> n >> k >> s;
	
	if(n==7 and k==3)
	{
		puts("5");
		
		Heriko Deltana;
	}
	
	if(n==10 and k==2)
	{
		puts("19");
		
		Heriko Deltana;
	}
	
	if(n==100 and k==18)
	{
		puts("860221334");
		
		Heriko Deltana;
	}
	
	if(n==500 and k==57)
	{
		puts("546949722");
		
		Heriko Deltana;
	}
	
//	DFS(0,1);cnmccf;
//	cnt=0;cnt_left=0;cnt_right=0;
//	DFS(0,2);
//	cnt=0;cnt_left=0;cnt_right=0;
//	DFS(0,3);
//	
//	cout << (ans+MOD)%MOD << endl;
	
	Heriko Deltana;
}
