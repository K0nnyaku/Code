#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int rd(){
	int res(0), fl(1);
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') fl=-1; c=getchar();
	}
	while(isdigit(c)){
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res*fl;
}
const int maxn=500010;
int t, n, a[maxn], b[maxn], ans[maxn], Flg, top, cnt, N, ans2[maxn], cnt1, cnt2;
int pos[maxn][3];
struct Op{
	int l, r, i, j, tp1, tp2, pre;
}P[10000010];

int Q[10000010], hd, tl;
void prnt(int op){
	ans[++cnt1]=P[op].tp1;
	ans2[++cnt2]=P[op].tp2;
	if(P[op].pre) prnt(P[op].pre);
	return;
}
void Prnt(int op){
	cnt1=0, cnt2=0, Flg=1;
	prnt(op);
	for(int i(cnt1);i>=1;--i) if(ans[i]==1) printf("L"); else printf("R");
	for(int i(1);i<=cnt2;++i) if(ans2[i]==1) printf("L"); else printf("R");
	printf("\n");
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	t=rd();
	for(;t--;){
		top=0, Flg=0; memset(pos, 0, sizeof(pos)); memset(ans, 0, sizeof(int)*n); memset(ans2, 0, sizeof(int)*n);
		n=rd(); N=n*2;
		for(int i(1);i<=N;++i) a[i]=rd(), pos[a[i]][++pos[a[i]][0]]=i;
		P[++top]=Op{1,N+1,pos[a[1]][2],pos[a[1]][2],1,1,0};
		tl=0, hd=1;
		Q[++tl]=1;
		P[++top]=Op{0,N,pos[a[N]][1],pos[a[N]][1],2,1,0};
		Q[++tl]=2;
		while(hd<=tl){
			int op=Q[hd++];
//			printf("%d %d %d %d\n", P[op].l, P[op].i, P[op].j, P[op].r); 
			if(P[op].l+1==P[op].i&&P[op].j+1==P[op].r){
				Prnt(op); break;
			}
			if(P[op].l+1<P[op].i-1&&a[P[op].l+1]==a[P[op].i-1]){
				P[++top]=Op{P[op].l+1,P[op].r,P[op].i-1,P[op].j,1,1,op};
				Q[++tl]=top;
			}
			if(P[op].l+1<P[op].i&&P[op].j+1<P[op].r&&a[P[op].l+1]==a[P[op].j+1]){
//				printf("l+1 j+1\n");
				P[++top]=Op{P[op].l+1,P[op].r,P[op].i,P[op].j+1,1,2,op};
				Q[++tl]=top;
			} 
			if(P[op].i-1>P[op].l&&P[op].r-1>P[op].j&&a[P[op].i-1]==a[P[op].r-1]){
				P[++top]=Op{P[op].l,P[op].r-1,P[op].i-1,P[op].j,2,1,op};
				Q[++tl]=top;
			} 
			if(P[op].j+1<P[op].r-1&&a[P[op].j+1]==a[P[op].r-1]){
				P[++top]=Op{P[op].l,P[op].r-1,P[op].i,P[op].j+1,2,2,op};
				Q[++tl]=top;
			} 
		} 
		if(!Flg) printf("-1\n");
	}
	return 0;
}
