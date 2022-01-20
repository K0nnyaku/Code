#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=2200000;
int N;
char S[MX];

int C[MX][26],F[MX],len[MX],sz[MX],las=1,sc=1;
void Extend(char c)
{
	int k=c-'a',x=++sc,y=las;
	las=x,len[x]=len[y]+1,sz[x]=1;
	while(y&&!C[y][k])C[y][k]=x,y=F[y];
	if(!y)F[x]=1;
	else{
		int z=C[y][k];
		if(len[z]==len[y]+1)F[x]=z;
		else{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[z]));
			F[w]=F[z],len[w]=len[y]+1,F[x]=F[z]=w;
			while(C[y][k]==z)C[y][k]=w,y=F[y];
		}
	}
}

int cnt[MX],id[MX];


int main()
{
	scanf("%s",S+1),N=strlen(S+1);
	Fr(i,1,N)Extend(S[i]);
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,N)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	Fl(i,sc,1)sz[F[id[i]]]+=sz[id[i]];
	
//	Fr(i,1,sc)printf("%d ",id[i]);
	int ans=0;
	Fr(i,1,sc)if(sz[i]>1)
		ans=max(ans,sz[i]*len[i]);
	printf("%d\n",ans);
	
	return 0;
}