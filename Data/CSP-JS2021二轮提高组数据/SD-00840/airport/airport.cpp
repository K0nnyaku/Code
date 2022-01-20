#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#define ll long long
#define qwq 100007
int n;
int m1,m2;
struct p{
	int l,r;
	int wh;
}a1[qwq],a2[qwq];
bool cmp(p x,p y){
	return x.l<y.l;
}
int t[qwq];
int las=1;
std::priority_queue<std::pair<int,int> >p_que;
std::set<int>se;
void init(){
	memset(t,0,sizeof(t));
	while(!p_que.empty())p_que.pop();
	se.clear();
	for(int i=1;i<=n+1;++i)se.insert(i);
	las=1;
	return ;
}
inline void workt(int x,int v){
	if(x>=n+1)return ;
	t[x]+=v;
	if(t[x]==1){
		se.erase(x);
		las=*se.begin();
		return ;
	}
	if(t[x]==0){
		se.insert(x);
		las=*se.begin();
		return ;
	}
	return ;
}
int ans1[qwq],ans2[qwq];
void worka1(){
	for(int i=1;i<=m1;++i){
		while(!p_que.empty()){
			if(-p_que.top().first>=a1[i].l)break;
			int x=p_que.top().second;
			p_que.pop();
			workt(x,-1);
		}
		a1[i].wh=las;
		++ans1[las];
		p_que.push(std::make_pair(-a1[i].r,a1[i].wh));
		workt(las,1);
	}
	return ;
}
void worka2(){
	for(int i=1;i<=m2;++i){
		while(!p_que.empty()){
			if(-p_que.top().first>=a2[i].l)break;
			int x=p_que.top().second;
			p_que.pop();
			workt(x,-1);
		}
		a2[i].wh=las;
		++ans2[las];
		p_que.push(std::make_pair(-a2[i].r,a2[i].wh));
		workt(las,1);
	}
	return ;
}
int ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i){
		scanf("%d%d",&a1[i].l,&a1[i].r);
	}
	std::sort(a1+1,a1+m1+1,cmp);
	init();
	worka1();
//	for(int i=1;i<=m1;++i){
//		printf("ans:%d\n",a1[i].wh);
//	}
	for(int i=1;i<=m2;++i){
		scanf("%d%d",&a2[i].l,&a2[i].r);
	}
	std::sort(a2+1,a2+m2+1,cmp);
	init();
	worka2();
//	for(int i=1;i<=m2;++i){
//		printf("ans:%d\n",a2[i].wh);
//	}
	for(int i=1;i<=n;++i){
		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
	}
	for(int i=0;i<=n;++i){
		ans=std::max(ans,ans1[i]+ans2[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
