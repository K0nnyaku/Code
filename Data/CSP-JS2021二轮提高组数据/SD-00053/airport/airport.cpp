#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=4e5+7,INF=1e9+7,Mod=998244353;
int n,m1,m2,ke1[N],ke2[N],ans,a[N];
struct p{
	int t,ty,id;
	p(int t=0,int ty=0,int id=0):t(t),ty(ty),id(id){}
	bool operator < (const p& A)const{return t<A.t;}
}s1[N],s2[N];
set<int> s;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1,l,r;i<=m1;i++)scanf("%d %d",&l,&r),s1[i*2-1]=p(l,0,i),s1[i*2]=p(r,1,i);
	for(int i=1,l,r;i<=m2;i++)scanf("%d %d",&l,&r),s2[i*2-1]=p(l,0,i),s2[i*2]=p(r,1,i);
	sort(s1+1,s1+m1*2+1),sort(s2+1,s2+m2*2+1);
	
	for(int i=0;i<=m1*2;i++)a[i]=0;
	s.clear();
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=1;i<=m1*2;i++){
		if(s1[i].ty==0&&s.size()!=0){
			++ke1[*s.begin()],a[s1[i].id]=*s.begin();
			s.erase(*s.begin());
		}
		if(s1[i].ty==1&&a[s1[i].id]>0)s.insert(a[s1[i].id]);
	}
	s.clear();
	for(int i=0;i<=m2*2;i++)a[i]=0;
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=1;i<=m2*2;i++){
		if(s2[i].ty==0&&*s.begin()!=0){
			++ke2[*s.begin()],a[s2[i].id]=*s.begin();
			s.erase(*s.begin());
		}
		if(s2[i].ty==1&&a[s2[i].id]>0)s.insert(a[s2[i].id]);
	}
	
	for(int i=1;i<=n;i++)ke1[i]+=ke1[i-1];
	for(int i=1;i<=n;i++)ke2[i]+=ke2[i-1];
	for(int i=0;i<=n;i++)ans=max(ans,ke1[i]+ke2[n-i]);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
