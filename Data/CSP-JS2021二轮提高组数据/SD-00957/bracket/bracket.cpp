#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=5e2+10;
const int Mod=1e9+7;

inline void add_mod(int &x,int y){ x+=y; if(x>=Mod) x-=Mod; }

int n,d;
char s[MAXN];
int dp[MAXN][MAXN];

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d\n%s",&n,&d,s+1);
	for(int i=1;i<=n-1;i++)
		if(s[i]=='(' || s[i]=='?')		// ()
		{
			if(s[i+1]==')' || s[i+1]=='?')
				dp[i][i+1]=1;
		}
		
	for(int len=3;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			
			// (A)
			if((s[i]=='(' || s[i]=='?') && (s[j]==')' || s[j]=='?'))
				add_mod(dp[i][j],dp[i+1][j-1]);
				
			// (S)
			if((s[i]=='(' || s[i]=='?') && (s[j]==')' || s[j]=='?'))
			{
				bool flg=true;
				for(int op=i+1;op<=j-1;op++)
					if(s[op]!='?' && s[op]!='*') flg=false;
				if(flg && j-i-1<=d) add_mod(dp[i][j],1);
			}
			
			// (SA)
			if((s[i]=='(' || s[i]=='?') && (s[j]==')' || s[j]=='?'))
			{
				for(int op=i+1;op<=j-2;op++)
					if(s[op]!='?' && s[op]!='*') break;
					else
					{
						if(op-i>d) break;
						add_mod(dp[i][j],dp[op+1][j-1]);
					}
			}
			
			// (AS)
			if((s[i]=='(' || s[i]=='?') && (s[j]==')' || s[j]=='?'))
			{
				for(int ed=j-1;ed>=i+2;ed--)
					if(s[ed]!='?' && s[ed]!='*') break;
					else
					{
						if(j-ed>d) break;
						add_mod(dp[i][j],dp[i+1][ed-1]);
					}
			}
			
			// AB
			for(int mid=i+1;mid<j-1;mid++)
				add_mod(dp[i][j],(ll)dp[i][mid]*dp[mid+1][j] %Mod);
			
			// ASB
			for(int l=i+2;l<=j-2;l++)
				for(int r=l;r<=j-2 && r-l+1<=d;r++)
					if(s[r]!='?' && s[r]!='*') break;
					else add_mod(dp[i][j],(ll)dp[i][l-1]*dp[r+1][j] %Mod);
		}
		
	printf("%d\n",dp[1][n]);
	
	return 0;
}


/*
7 3 
(*??*??

10 2
???(*??(?)


*/



