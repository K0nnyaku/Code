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
	char c;c=getchar();
	while(!isdigit(c)){
		if(c=='-') fl=-1; c=getchar();
	}
	while(isdigit(c)){
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res*fl;
}
const int maxn=100010; 
int n, m1, m2, tot, Ans, A, B, C, D;
bool vis[maxn];
struct Plne{
	int tm, tp, fl, id;
//	inline bool operator < (const Plne P){
//		return this->tm < P.tm;
//	}
}p[maxn<<1];
bool cmp(Plne p1, Plne p2){
	return p1.tm < p2.tm;
}
void Work(){
	int res(0);
	memset(vis, 0, sizeof(vis));
	/*
	for(int i(1);i<=tot;++i){
//		printf("tm=%d tp=%d\n", p[i].tm, p[i].tp); 
		if(p[i].tp==1){
			if(p[i].fl==1){
				if(C<A) {
					printf("%d(%d) get\n", p[i].id, p[i].tm);
					res++, C++, vis[p[i].id]=1;
				}
			}
			else{
				if(vis[p[i].id]) C--;
			}
		}
		else{
			if(p[i].fl==1){
				if(D<B) {
					printf("%d(%d) get\n", p[i].id, p[i].tm);
					res++, D++, vis[p[i].id]=1;
				}
			}
			else{
				if(vis[p[i].id]) D--;
			}
		}
	}
	*/
	for(int i(1);i<=tot;++i){
		if(p[i].fl==-1){
			if(vis[p[i].id]){
				if(p[i].tp==1) C--;
				else D--;
			}
		}
		else{
			if(p[i].tp==1){
				if(C<A){
					C++; vis[p[i].id]=1;
					res++;
				}
			}
			else{
				if(D<B){
					D++; vis[p[i].id]=1;
					res++;
				}
			}
		}
	}
	Ans=max(Ans, res);
//	printf("when A=%d res=%d\n", A, res);
	return;
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n=rd(), m1=rd(), m2=rd();
	for(int i(1);i<=m1;++i){
		p[++tot].tm=rd(), p[tot].tp=1, p[tot].fl=1, p[tot].id=i;
		p[++tot].tm=rd(), p[tot].tp=1, p[tot].fl=-1, p[tot].id=i;
	}
	
	for(int i(1);i<=m2;++i){
		p[++tot].tm=rd(), p[tot].tp=2, p[tot].fl=1, p[tot].id=i+m1;
		p[++tot].tm=rd(), p[tot].tp=2, p[tot].fl=-1, p[tot].id=i+m1;
	}
	sort(p+1,p+1+tot,cmp);
	
	for(int i(0);i<=n;++i){
		A=i, B=n-i, C=0, D=0;
		Work();
	}
	printf("%d\n", Ans);
	return 0;
}

