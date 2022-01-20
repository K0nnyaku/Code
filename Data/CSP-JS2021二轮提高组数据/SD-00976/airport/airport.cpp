#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int rd(){
	int res=0,flag=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3)+(c-'0');
	return res*flag;
}
const int N=2e5+13;
struct Node{
	int pos,id;bool op;
	bool operator <(const Node &a)const{return pos<a.pos;}
}a[N],b[N];
int n,m1,m2,ida[N],idb[N],cnta[N],cntb[N];
std::set<int> t;
std::set<int>::iterator it;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rd(),m1=rd(),m2=rd();
	for(int i=1;i<=m1;++i){
		int l=rd(),r=rd();
		a[i*2-1]=(Node){l,i,1},a[i*2]=(Node){r,i,0};
	}
	m1<<=1;
	std::sort(a+1,a+m1+1);
	for(int i=1;i<=m2;++i){
		int l=rd(),r=rd();
		b[i*2-1]=(Node){l,i,1},b[i*2]=(Node){r,i,0};
	}
	m2<<=1;
	std::sort(b+1,b+m2+1);
	int cnt1=0;t.clear();
	for(int i=1;i<=m1;++i){
		if(a[i].op){
			if(t.empty()) ida[a[i].id]=++cnt1,cnta[cnt1]=1;
			else{
				it=t.begin();int p=(*it);t.erase(it);
				ida[a[i].id]=p,++cnta[p];
			}
		}
		else t.insert(ida[a[i].id]);
	}
	int cnt2=0;t.clear();
	for(int i=1;i<=m2;++i){
		if(b[i].op){
			if(t.empty()) idb[b[i].id]=++cnt2,cntb[cnt2]=1;
			else{
				it=t.begin();int p=(*it);t.erase(it);
				idb[b[i].id]=p,++cntb[p];
			}
		}
		else t.insert(idb[b[i].id]);
	}
	int res=0,lim=min(n,cnt1);
	for(int i=1;i<=lim;++i) res+=cnta[i];
	for(int i=1;i<=n-lim;++i) res+=cntb[i];
	int ans=res;
	for(int i=lim,j=n-lim+1;i&&j<=cnt2;--i,++j){
		res-=cnta[i],res+=cntb[j];
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}
