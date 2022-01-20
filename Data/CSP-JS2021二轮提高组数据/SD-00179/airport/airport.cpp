#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
//define int long long
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

const int maxn=1e6+2049;
const int MAXN=2049*2;
int n,m_1,m_2,Ans=-10086;
struct flight1{int st,en;
   
}f[maxn];
struct flight2{int st,en;
	 
}F[maxn];
bool cmp(flight1 a,flight1 b){
	if(a.st!=b.st) return a.st<b.st;
	else return a.en<b.en;
}
bool cmp2(flight2 a2,flight2 b2){
	if(a2.st!=b2.st) return a2.st<b2.st;
	else return a2.en<b2.en;
}

struct flight3{
   int st,en;
   bool friend operator < (flight3 x,flight3 y){
   	   return  x.en>y.en;
   }
};
struct flight4{
    int stt,endd;
    bool friend operator < (flight4 x,flight4 y){
	 	return x.endd>y.endd;
   }
};
priority_queue<flight3,vector<flight3>,less<flight3> >q; int cnt,Ans1;
priority_queue<flight4,vector<flight4>,less<flight4> >q2;int Cnt,Ans2;
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    n=read(); m_1=read(); m_2=read();
    for(int i=1;i<=m_1;i++) f[i].st=read(),f[i].en=read();
    for(int i=1;i<=m_2;i++) F[i].st=read(),F[i].en=read();
    sort(f+1,f+m_1+1,cmp);  sort(F+1,F+m_2+1,cmp2);
    for(int k=0;k<=n;k++){
    	int guonei=k,guowai=n-k;
		cnt=0,Cnt=0;Ans1=0,Ans2=0;
		while(!q.empty()) q.pop(); while(!q2.empty()) q2.pop();
    	while(q.size()!=guonei+1&&++cnt<=m_1){
		    flight3 u; u.st=f[cnt].st,u.en=f[cnt].en;
		    if(f[cnt].st>=q.top().en&&!q.empty()) q.pop();
			if(q.size()!=guonei) q.push(u),Ans1++;
		}
    	while(q2.size()!=guowai+1&&++Cnt<=m_2){
            flight4 u1; u1.stt=F[Cnt].st,u1.endd=F[Cnt].en;
		    if(F[Cnt].st>=q2.top().endd&&!q2.empty()) q2.pop();
			if(q2.size()!=guowai) q2.push(u1),Ans2++;
		}
		Ans=max(Ans1+Ans2,Ans);
	}
	printf("%d\n",Ans);
	fclose(stdin);fclose(stdout);
    return 0;
}

