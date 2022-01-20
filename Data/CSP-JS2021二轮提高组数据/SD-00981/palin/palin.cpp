#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
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
typedef long long ll;
const int N=5e5+5;
int T,n,a[N<<1],pos[N][2],cnt[N],seq[N],res[N<<1];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	Read(T);
	while(T--){
		Read(n);
		For(i,1,n*2){
			Read(a[i]);int x=a[i];
			if(pos[x][0]) pos[x][1]=i;
			else pos[x][0]=i;
		}
		if(n<=20){
			bool succ=0;
			For(st,0,(1<<n)-1){
				For(i,1,n) cnt[i]=0;
				int l=1,r=2*n;
				int flg=1;
				For(i,1,n){
					if(st&(1<<(n-i))){
						if(cnt[a[r]]>=1){
							flg=0;break;
						}
						++cnt[a[r]],seq[i]=a[r],res[i]=1,--r;
					}else{
						if(cnt[a[l]]>=1){
							flg=0;break;
						}
						++cnt[a[l]],seq[i]=a[l],res[i]=0,++l;
					}
				}
				if(!flg) continue;
				For(i,1,n) if(cnt[i]!=1){
					flg=0;break;
				}
				if(!flg) continue;
				Dec(i,n,1){
					if(a[l]==seq[i]) ++l,res[n+(n-i+1)]=0;
					else if(a[r]==seq[i]) --r,res[n+(n-i+1)]=1;
					else{
						flg=0;break;
					}
				}
				if(!flg) continue;
				succ=1;break;
			}
			if(succ) For(i,1,n*2) putchar(res[i]?'R':'L');
			else putchar('-'),putchar('1');
			puts("");
		}else{
			int tot=0,p=0,flg=1;
			stack<int> stk;
			For(i,1,n*2){
				if(pos[a[i]][0]==i){
					stk.push(a[i]);
				}else{
					if(stk.top()!=a[i]){
						flg=0;break;
					}
					stk.pop();
					if(stk.empty()){
						++tot,p=i;
						if(tot>1){
							flg=0;break;
						}
					}
				}
			}
			if(!flg) puts("-1");
			else{
				if(tot){
					For(i,1,p/2) putchar('L');
					For(i,1,2*n-p) putchar('R');
					For(i,1,p/2) putchar('L');
				}else{
					For(i,1,n*2) putchar('L');
				}
				puts("");
			}
		}
	}
	return 0;
}
