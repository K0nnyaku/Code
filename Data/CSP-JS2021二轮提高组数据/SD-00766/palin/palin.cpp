#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000100;
int N,M,A[MX];

char S[MX],T[MX];
int sc,tc;

bool Solve(int a,int b,int l,int r)
{
	Fr(i,2,N)
	{
		if(a<l-1&&A[a]==A[l-1])
			++a,--l,S[++sc]='L',T[++tc]='L';
		else if(a<l&&r<b&&A[a]==A[r+1])
			++a,++r,S[++sc]='L',T[++tc]='R';
		else if(a<l&&r<b&&A[b]==A[l-1])
			--b,--l,S[++sc]='R',T[++tc]='L';
		else if(r+1<b&&A[b]==A[r+1])
			--b,++r,S[++sc]='R',T[++tc]='R';
		else return 0;
	}
	return 1;
}

int mian()
{
	scanf("%d",&N),M=2*N;
	Fr(i,1,M)scanf("%d",&A[i]);
	
	sc=tc=0;
	Fr(i,2,M)if(A[1]==A[i])
	{
		S[++sc]='L',T[++tc]='L';
		if(Solve(2,M,i,i))return 1;
	}
	
	sc=tc=0;
	Fr(i,1,M-1)if(A[M]==A[i])
	{
		S[++sc]='R',T[++tc]='L';
		if(Solve(1,M-1,i,i))return 1;
	}
	
	return 0;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
//	freopen("palin2.in","r",stdin);
//	freopen("palin2.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int r=mian();
		if(!r)printf("-1\n");
		else
		{
			Fr(i,1,sc)putchar(S[i]);
			Fl(i,tc,1)putchar(T[i]);
			putchar('\n');
		}
		
		memset(A,0,(M+2)*sizeof(int));
	}
	
	return 0;
}
