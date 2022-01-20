#include<cstdio>
#include<iostream>
using namespace std;
const int N=505,P=1e9+7;
int n,m,A[N][N],AS[N][N],A2[N][N];
char s[N];
bool l[N],r[N],sr[N],S[N][N],as[N][N];
inline int MOD(int x) {return x>=P?x-P:x;}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)  l[i]=(s[i]=='('||s[i]=='?'),r[i]=(s[i]==')'||s[i]=='?'),sr[i]=(s[i]=='*'||s[i]=='?');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m&&i+j-1<=n&&sr[j+i-1];j++)  S[i][j+i-1]=1;
	for(int i=1;i<n;i++)  A[i][i+1]=A2[i][i+1]=l[i]&&r[i+1];
	for(int L=3;L<=n;L++)
		for(int i=1,j=i+L-1;j<=n;i++,j++)
		{
			for(int k=i;k<j;k++)  AS[i][j]=MOD(AS[i][j]+A2[i][k]*S[k+1][j]);
			if(l[i]&&r[j])
			{
				A[i][j]=MOD(A[i][j]+S[i+1][j-1]);A[i][j]=MOD(A[i][j]+A[i+1][j-1]);
				for(int k=i+1;k<j;k++)  A[i][j]=MOD(A[i][j]+A[i+k][k]*S[k+1][j-1]%P);
				for(int k=i+1;k<j;k++)  A[i][j]=MOD(A[i][j]+S[i+1][k]*A[k+1][j-1]%P);
			}
			A2[i][j]=A[i][j];
			for(int k=i;k<j;k++)  A[i][j]=MOD(A[i][j]+1ll*AS[i][k]*A[k+1][j]%P);
			for(int k=i;k<j;k++)  A[i][j]=MOD(A[i][j]+1ll*A2[i][k]*A[k+1][j]%P);
		}
	printf("%d",A[1][n]);return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)
10 2
???(*??())  16
10 2
???(*??(*)  12

9 1
(*)(*)(*)
8 1
(?)(?)()
8 0
()()()()
6 0
()()()
7 1
()()*()
*/
