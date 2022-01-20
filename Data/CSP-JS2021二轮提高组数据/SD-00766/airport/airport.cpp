#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Cl(a) memset((a),0,sizeof(a))
using namespace std;
typedef long long ll;

const int MX=200100;
int N,M1,M2,A[2][MX];

int U[MX],uc;
int X[MX],B[MX],L[MX],R[MX];

void Solve(int t,int m)
{
	Fr(i,1,m)
	{
		scanf("%d%d",&L[i],&R[i]);
		U[++uc]=L[i],U[++uc]=R[i];
	}
	sort(U+1,U+uc+1);
	uc=unique(U+1,U+uc+1)-U-1;
	Fr(i,1,m)
	{
		L[i]=lower_bound(U+1,U+uc+1,L[i])-U;
		R[i]=lower_bound(U+1,U+uc+1,R[i])-U;
		X[L[i]]=i,X[R[i]]=-i;
	}
//	Fr(i,1,uc)printf("%d ",X[i]);putchar('\n');
	
	priority_queue<int> q;
	Fr(i,1,N)q.push(-i);
	Fr(i,1,uc)
	{
//		printf("%d: ",i),PrintHeap(q);
		int x=X[i];
		if(x>0)
		{
			if(!q.empty())B[x]=-q.top(),q.pop();
		}
		else
		{
			x=-x;
			if(B[x])q.push(-B[x]);
		}
	}
	
//	Fr(i,1,m)printf("%d ",B[i]);putchar('\n');
	Fr(i,1,m)if(B[i])++A[t][B[i]];
	Fr(i,1,N)A[t][i]+=A[t][i-1];
	
	Cl(B),Cl(U),Cl(X),Cl(L),Cl(R);
	uc=0;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
//	freopen("airport3.in","r",stdin);
//	freopen("airport3.out","w",stdout);
	
	scanf("%d%d%d",&N,&M1,&M2);
	Solve(0,M1);
	Solve(1,M2);
	
//	Fr(i,0,N)printf("%d ",A[0][i]);putchar('\n');
//	Fr(i,0,N)printf("%d ",A[1][i]);putchar('\n');
	
	int ans=0;
	Fr(i,0,N)ans=max(ans,A[0][i]+A[1][N-i]);
	printf("%d\n",ans);
	
	return 0;
}
