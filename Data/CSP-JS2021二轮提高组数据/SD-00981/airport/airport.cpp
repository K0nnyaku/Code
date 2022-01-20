#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
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
const int N=2e5+5;
int n,m1,m2;
pair<int,int> a[N],b[N];
int disc[N<<2],len;
int Disc(int x){
	return lower_bound(disc+1,disc+len+1,x)-disc;
}
struct Bit{
	int t[N];
	void Add(int p,int k){
		for(;p<=m1+m2;p+=p&-p) t[p]+=k;
	}
	int Qry(int p){
		int res=0;
		for(;p;p-=p&-p) res+=t[p];
		return res;
	}
}bit1,bit2;
struct Node{
	int tp,i,tm;
}mes1[N<<1],mes2[N<<1];
bool operator<(const Node &n1,const Node &n2){
	return n1.tm<n2.tm;
}
int siz1,siz2,f1[N],f2[N],buk1[N],buk2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	Read(n,m1,m2);
	For(i,1,m1){
		Read(a[i].first,a[i].second);
		disc[++len]=a[i].first,disc[++len]=a[i].second;
	}
	For(i,1,m2){
		Read(b[i].first,b[i].second);
		disc[++len]=b[i].first,disc[++len]=b[i].second;
	}
	sort(disc+1,disc+len+1);
	len=unique(disc+1,disc+len+1)-disc-1;
	For(i,1,m1){
		a[i].first=Disc(a[i].first),a[i].second=Disc(a[i].second);
		mes1[++siz1]={0,i,a[i].first},mes1[++siz1]={1,i,a[i].second};
	}
	For(i,1,m2){
		b[i].first=Disc(b[i].first),b[i].second=Disc(b[i].second);
		mes2[++siz2]={0,i,b[i].first},mes2[++siz2]={1,i,b[i].second};
	}
	sort(mes1+1,mes1+siz1+1);
	sort(mes2+1,mes2+siz2+1);
	For(i,1,siz1){
		if(mes1[i].tp) bit1.Add(f1[mes1[i].i],-1);
		else{
			int l=1,r=m1;
			while(l<r){
				int mid=(l+r)>>1;
				if(bit1.Qry(mid)<mid) r=mid;
				else l=mid+1;
			}
			f1[mes1[i].i]=l;
			++buk1[l];
			bit1.Add(l,1);
		}
	}
	For(i,1,siz2){
		if(mes2[i].tp) bit2.Add(f2[mes2[i].i],-1);
		else{
			int l=1,r=m2;
			while(l<r){
				int mid=(l+r)>>1;
				if(bit2.Qry(mid)<mid) r=mid;
				else l=mid+1;
			}
			f2[mes2[i].i]=l;
			++buk2[l];
			bit2.Add(l,1);
		}
	}
	int ans=0,cnt1=0,cnt2=0;
	For(i,1,n) cnt2+=buk2[i];
	For(i,0,n){
//		printf("%d:%d %d\n",i,cnt1,cnt2);
		ans=max(ans,cnt1+cnt2);
		cnt1+=buk1[i+1],cnt2-=buk2[n-i];
	}
	printf("%d\n",ans);
	return 0;
}
