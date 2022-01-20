#include<iostream>
#include<cstdio>
#include<algorithm>
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)

using namespace std;

const int N = 1e5+10;
template <typename LFJQWQ>
void read(LFJQWQ &NUM){
    NUM = 0;bool FFF = true;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')FFF = false;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		NUM = (NUM << 3) + (NUM << 1) + (ch ^ 48);
		ch = getchar();
	}
	NUM = FFF ? NUM : -NUM;
}
int n,m[2],Cnt[2][N],S[2][N];
struct Air{
	int a,b;	
}P[2][N];
bool cmp1(Air A,Air B){return A.a < B.a;}
int t[2][N << 2];
void push_up(int p,int k){t[k][p] = min(t[k][ls(p)],t[k][rs(p)]);}
void modify(int k,int p,int l,int r,int v){
	if(l == r){
		if(t[k][p] > P[k][v].a)return ;
		t[k][p] = P[k][v].b;
		Cnt[k][l] ++;
		return ;
	}
	int mid = (l + r) >> 1;
	if(t[k][ls(p)] <= P[k][v].a)modify(k,ls(p),l,mid,v); 
	else modify(k,rs(p),mid+1,r,v);
	push_up(p,k);
}
int main(){
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    read(n);read(m[0]);read(m[1]);
    for(int k = 0 ; k <= 1 ; k ++)
    	for(int i = 1 ; i <= m[k] ; i ++){read(P[k][i].a);read(P[k][i].b);}
    sort(P[0]+1,P[0]+1+m[0],cmp1);
    sort(P[1]+1,P[1]+1+m[1],cmp1);
    for(int k = 0 ; k <= 1 ; k ++){
    	for(int i = 1 ; i <= m[k] ; i ++)modify(k,1,1,n,i);
    	for(int i = 1 ; i <= n ; i ++)S[k][i] = S[k][i - 1] + Cnt[k][i];
	}
    int ans = -10;
    for(int i = 0 ; i <= n ; i ++){
		ans = max(ans,S[0][i] + S[1][n-i]);
	} 
	printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
	return 0;
}
