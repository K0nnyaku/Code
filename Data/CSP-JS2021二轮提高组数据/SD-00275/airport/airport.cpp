#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=100010;
const int M=200000001;
struct qwq{
	int bl,dl;//beginline deadline
}p[N];
struct QWQ{
	int bl,dl;
}pp[N];
struct qaq{
	int l,r;
}h[N];
inline bool cmp(qwq a,qwq b){
	if(a.bl!=b.bl) return a.bl<b.bl;
	else return a.dl<b.dl;
}
inline bool cmp2(QWQ a,QWQ b){
	if(a.bl!=b.bl) return a.bl<b.bl;
	else return a.dl<b.dl;
}
int n,m1,m2;
int ans;
short vis[M];
//inline void dfs(int tm,int pidx,int hidx){
//	
//	if(vis[tm]){
//		pidx++;
//		return;
//	}
//	if(tm>1 && tm>=h[1].r){
//		for(int i=1;i<=n;i++){
//			h[i].l=h[i+1].l;
//			h[i].r=h[i+1].r;
//		}
//	}
//	if(hidx>n){
//		pidx++,tm++;
//		return;
//	} 
//	for(register int i=p[pidx].bl;i<=p[pidx].dl;i++) vis[i]=true;
//	h[hidx].l=p[pidx].bl,h[hidx].r=p[pidx].dl;
//	tm++;
//	ans++;
//	dfs(tm,pidx+1,hidx+1);
//}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(register int i=1;i<=m1;i++){
		p[i].bl=read(),p[i].dl=read();
	}
	for(register int i=1+m1;i<=m2+m1;i++){
		pp[i].bl=read(),pp[i].dl=read();
	}
	sort(p+1,p+1+m1,cmp);
	sort(pp+1,pp+1+m2+m1,cmp2);
	int tm=1,hidx=0,pidx=1;
	int anss=-0x7fffffff;
	for(int j=1;j<=n;j++){
		int temp=n-j;
		while(1){//给国内分配 
			if(j==0) break;
			if(pidx>(m1)) break;
			while(h[1].r && tm>=h[1].r ){//当前时间一号航站已经空闲 
				for(register int i=h[1].l;i<=h[1].r;i++){
					vis[i]--;
				}
				for(register int i=1;i<=j;i++){
					h[i].l=h[i+1].l;
					h[i].r=h[i+1].r;
				}
				hidx--;//占用的航班-1 
			}
			if(vis[p[pidx].bl]==j){//当前飞机已经无法降落 
				pidx++;
				continue;
			}
			if(vis[tm]==j){
				tm++;
				continue;
			}
			if(hidx>j){//当前没有空航站 
				pidx++,tm++;
				continue;
			} 
			for(register int i=p[pidx].bl;i<=p[pidx].dl;i++) vis[i]++;
			h[hidx].l=p[pidx].bl,h[hidx].r=p[pidx].dl;
			tm++;
			ans++;
			pidx++;
			hidx++;
		}
		memset(vis,0,sizeof vis);//初始化 
		memset(h,0,sizeof h);
		tm=1,hidx=0,pidx=m1;
		
		while(1){//给国外分配 
			if(temp==0) break;
			if(pidx>(m2)) break;
			while(h[1].r && tm>=h[1].r ){//当前时间一号航站已经空闲 
				for(register int i=h[1].l;i<=h[1].r;i++){
					vis[i]--;
				}
				for(register int i=1;i<=temp;i++){
					h[i].l=h[i+1].l;
					h[i].r=h[i+1].r;
				}
				hidx--;//占用的航班-1 
			}
			if(vis[pp[pidx].bl]==temp){//当前飞机已经无法降落 
				pidx++;
				continue;
			}
			if(vis[tm]==temp){
				tm++;
				continue;
			}
			if(hidx>temp){//当前没有空航站 
				pidx++,tm++;
				continue;
			} 
			for(register int i=pp[pidx].bl;i<=pp[pidx].dl;i++) vis[i]++;
			h[hidx].l=pp[pidx].bl,h[hidx].r=pp[pidx].dl;
			tm++;
			ans++;
			pidx++;
			hidx++;
		}  
		anss=max(anss,ans);
	}
	
	cout<<anss;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
