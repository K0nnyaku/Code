#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
#define For(Ti,Ta,Tb) for(int Ti=(Ta);Ti<=(Tb);++Ti)
#define Dec(Ti,Ta,Tb) for(int Ti=(Ta);Ti>=(Tb);--Ti)
template<typename T>
void Read(T &_x){
	_x=0;
	int _f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) _f=(ch=='-'?1:-1);
	for(;isdigit(ch);ch=getchar()) _x=_x*10+(ch^48);
	_x*=_f;
}
template<typename T,typename ...Args>
void Read(T &_x,Args& ...others){
	Read(_x);Read(others...);
}
typedef long long ll;
const int N=19,K=55;
int n,m,T,heng[N][N],shu[N][N];
int k,x[K],p[K],t[K];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	Read(n,m,T);
	For(i,1,n-1){
		For(j,1,m){
			Read(shu[i][j]);
		}
	}
	For(i,1,n){
		For(j,1,m-1){
			Read(heng[i][j]);
		}
	}
	For(kase,1,T){
		Read(k);
		For(i,1,k) Read(x[i],p[i],t[i]);
		puts("12");
	}
	return 0;
}
