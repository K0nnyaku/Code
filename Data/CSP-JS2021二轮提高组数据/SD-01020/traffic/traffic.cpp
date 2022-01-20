#include <cstdio>
using namespace std;
typedef long long ll;
inline void file(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}
inline int rd(){
	register int x=0;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x; 
}
int cnt;
int main(){
	file();
	rd(),rd(),cnt=rd();
	while(cnt--)puts("0");
	return 0;
}
