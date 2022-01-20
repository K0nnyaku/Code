#include<bits/stdc++.h>
namespace MAIN{

using namespace std;
typedef long long LL;
#define pii pair<int,int>
#define fs first
#define sc second
const int N=1.1e6,mod=998244353;
int ans1[N],ans2[N];
int n,m1,m2;
//--
pii opt1[N],opt2[N];
bool vis[N],pt[N];
int func(int a){
	int b=n-a,cnt=0;
	if(a<0||b<0)return -1;
	for(int i=1;i<=m1*2;i++){
		int e=opt1[i].sc;
		if(vis[e]){
			if(pt[e])pt[e]=0,a++;
		}
		else{
			vis[e]=1;
			if(a>0)a--,pt[e]=1,cnt++;
		}
	}
	for(int i=1;i<=m1*2;i++)vis[opt1[i].sc]=pt[opt1[i].sc]=0;
	
	//cerr<<cnt<<endl;
	
	for(int i=1;i<=m2*2;i++){
		int e=opt2[i].sc;
		if(vis[e]){
			if(pt[e])pt[e]=0,b++;
		}
		else{
			vis[e]=1;
			if(b>0)b--,pt[e]=1,cnt++;
		}
	}
	for(int i=1;i<=m2*2;i++)vis[opt2[i].sc]=pt[opt2[i].sc]=0;
	return cnt;
}
void sub(){
	for(int i=1;i<=m1;i++){
		int a,b;scanf("%d%d",&a,&b);
		opt1[i*2-1]=pii(a,i),opt1[i*2]=pii(b,i);
	}
	for(int i=1;i<=m2;i++){
		int a,b;scanf("%d%d",&a,&b);
		opt2[i*2-1]=pii(a,i),opt2[i*2]=pii(b,i);
	}
	sort(opt1+1,opt1+2*m1+1),sort(opt2+1,opt2+2*m2+1);
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,func(i));//,cout<<func(i)<<" ";cout<<endl;
	printf("%d\n",ans);
}
//
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	if(n<=5000&&m1+m2<=5000)return sub(),0;
	set<pii>s1,s2;
	for(int i=1;i<=m1;i++){
		int a,b;scanf("%d%d",&a,&b);
		s1.insert(pii(a,b));
	}
	for(int i=1;i<=n;i++){
		ans1[i]=ans1[i-1];
		if(s1.empty())continue;
		pii nw=*s1.begin();ans1[i]++;
		s1.erase(s1.begin());
		while(1){
			set<pii>::iterator t=s1.lower_bound(pii(nw.sc,0));
			if(t==s1.end())break;
			ans1[i]++,nw=*t,s1.erase(t);
		}
	}
	for(int i=1;i<=m2;i++){
		int a,b;scanf("%d%d",&a,&b);
		s2.insert(pii(a,b));
	}
	for(int i=1;i<=n;i++){
		ans2[i]=ans2[i-1];
		if(s2.empty())continue;
		pii nw=*s2.begin();ans2[i]++;
		s2.erase(s2.begin());
		while(1){
			set<pii>::iterator t=s2.lower_bound(pii(nw.sc,0));
			if(t==s2.end())break;
			ans2[i]++,nw=*t,s2.erase(t);
		}
	}
//	for(int i=0;i<=n;i++)cout<<ans1[i]+ans2[n-i]<<" ";cout<<endl;
	int res=0;
	for(int i=0;i<=n;i++)res=max(res,ans1[i]+ans2[n-i]);
	printf("%d\n",res);
	return 0;
}

}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	MAIN::main();
	return 0;
}

