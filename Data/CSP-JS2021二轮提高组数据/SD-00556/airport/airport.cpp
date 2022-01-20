#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 200010
int n,m1,m2; 
using namespace std;
int ans1[N],ans2[N],max1,max2,maxt;
int js1[N],js2[N];
int cnt1[N],cnt2[N];
struct node1{
	int rc,lc;
}s1[N],s2[N];
/*
struct node2{
	int Add,Flag,Maxi;
}a[N*4];
*/
struct node3{
	int s,id,from;
}lsh[N*2];
/*
struct node4{
	int rc,lc;
};
bool operator(node4 x,node4 y){
	if(x.lc!=y.lc)return x.lc<y.lc;
	else return x.rc<y.rc;
}
set<node4>q;
*/ 
struct node5{
	int t,from;
};
bool operator <(node5 x,node5 y){
	if(x.t!=y.t)return x.t>y.t;
	else return x.from>y.from;
};
/*
struct node6{
	int t,from;
};
bool operator <(node6 x,node6 y){
	if(x.from!=y.from)return x.from<y.from;
	else return x.t<y.t;
}
*/
priority_queue<node5>avi;
priority_queue<int>in_queue;
//set<int>zy; 
int zzda;
int nowt;
int Read(){
	char ch;int res=0,zf=1;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')zf=!zf;res=(ch^48);
	while((ch=getchar())>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48);
	return zf?res:(-res);
}
bool operator < (node1 x,node1 y){
	if(x.lc==y.lc)return x.rc<y.rc;
	else return x.lc<y.lc;
}
bool operator < (node3 x,node3 y){
	if(x.s!=y.s)return x.s<y.s;
	if(x.id!=y.id)return x.id<y.id;
	return x.from<y.from; 
}
int maxx(int x,int y){return x>y?x:y;}
/*
int pushdown(int k,int l,int r,int mid){
	//int mid=(l+r)>>1;
	if(a[k].Flag){
		Add(k<<1,l,mid,l,mid,a[k].Flag);
		Add(k<<1|1,mid+1,r,mid+1,r,a[k].Flag);
		a[k].Add=a[k<<1].Add+a[k<<1|1].Add;
		a[k].Maxi=maxx(a[k<<1].Maxi,a[k<<1|1].Maxi);
		a[k].Flag=0;
	}
	return 0;
}
*/
/*
int pushdown(int k,int l,int r,int mid);
int Add(int k,int l,int r,int x,int y,int ss){
	if(x>r||y<l)return 0;
	if(x<=l&&y>=r){
		a[k].Add+=ss*(r-l+1);
		a[k].Maxi+=ss;
		a[k].Flag+=ss;
		return 0;
	}
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	Add(k<<1,l,mid,x,y,ss);
	Add(k<<1|1,mid+1,r,x,y,ss);
	a[k].Maxi=maxx(a[k<<1].Maxi,a[k<<1|1].Maxi);
	a[k].Add=a[k<<1].Add+a[k<<1|1].Add;
	return 0;
}
int Find(int k,int l,int r,int x,int y){
	if(x>r||y<l)return 0;
	if(x<=l&&y>=r)return a[k].Maxi;
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	return maxx(Find(k<<1,l,mid,x,y),Find(k<<1|1,mid+1,r,x,y));
}
	
	
int pushdown(int k,int l,int r,int mid){
	if(a[k].Flag){
		Add(k<<1,l,mid,l,mid,a[k].Flag);
		Add(k<<1|1,mid+1,r,mid+1,r,a[k].Flag);
		a[k].Add=a[k<<1].Add+a[k<<1|1].Add;
		a[k].Maxi=maxx(a[k<<1].Maxi,a[k<<1|1].Maxi);
		a[k].Flag=0;
	}
	return 0;
}
*/
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Read();m1=Read();m2=Read();
	for(int i=1;i<=m1;i++){
		lsh[i].s=Read();lsh[i+m1].s=Read();
		lsh[i].from=0;lsh[i+m1].from=1;
		lsh[i].id=i;lsh[i+m1].id=i;
	}
	std::sort(lsh+1,lsh+m1+m1+1);
	int js0=1;
	lsh[0].s=lsh[1].s;
	for(int i=1;i<=m1+m1;i++){
		if(lsh[i].s!=lsh[i-1].s)js0++;
		if(lsh[i].from)
			s1[lsh[i].id].rc=js0;
		else s1[lsh[i].id].lc=js0;
	}
	std::sort(s1+1,s1+m1+1);
//	puts("qaq");
	for(int i=1;i<=m1;i++)in_queue.push(-i); 
	for(int i=1;i<=m1;i++){
		nowt=s1[i].lc;
		
		while((!avi.empty())&&(avi.top().t<nowt)){
			int p=avi.top().from,q=avi.top().t;
			avi.pop();
		//	zy.erase(p);
			in_queue.push(-p);
		}
		
		int p=-(in_queue.top());
		
		in_queue.pop();
	//	puts("ovo");
	//	zy.insert(p);
		node5 ovo;
		ovo.from=p;
		ovo.t=s1[i].rc;
		avi.push(ovo);
		ans1[i]=p;
		
	}
//	for(int i=1;i<=m1;i++)
	//printf("%d\n",ans1[i]);
	int m3=m1;
	m1=m2;
	
	while(!in_queue.empty())in_queue.pop();
	while(!avi.empty())avi.pop();
	for(int i=1;i<=m1;i++){
		lsh[i].s=Read();lsh[i+m1].s=Read();
		lsh[i].from=0;lsh[i+m1].from=1;
		lsh[i].id=i;lsh[i+m1].id=i;
	}
	std::sort(lsh+1,lsh+m1+m1+1);
	js0=1;
	lsh[0].s=lsh[1].s;
	for(int i=1;i<=m1+m1;i++){
		if(lsh[i].s!=lsh[i-1].s)js0++;
		if(lsh[i].from)
			s1[lsh[i].id].rc=js0;
		else s1[lsh[i].id].lc=js0;
	}
	std::sort(s1+1,s1+m1+1);
//	puts("qaq");
	//for(int i=1;i<=m1;i++)
	
	//	printf("p%d %d\n",s1[i].lc,s1[i].rc);
	for(int i=1;i<=m1;i++)in_queue.push(-i); 
	for(int i=1;i<=m1;i++){
		nowt=s1[i].lc;
		
		while((!avi.empty())&&(avi.top().t<nowt)){
			int p=avi.top().from,q=avi.top().t;
			avi.pop();
		//	zy.erase(p);
			in_queue.push(-p);
		}
		
		int p=-(in_queue.top());
		
		in_queue.pop();
	//	puts("ovo");
	//	zy.insert(p);
		node5 ovo;
		ovo.from=p;
		ovo.t=s1[i].rc;
		avi.push(ovo);
		ans2[i]=p;
		
	}
	for(int i=1;i<=m1;i++)
	//printf("%d\n",ans2[i]);	
	m1=m3;
	
	for(int i=1;i<=m1;i++){
		js1[ans1[i]]++;
	}
	for(int i=1;i<=m2;i++){
		js2[ans2[i]]++;
	}
	cnt1[1]=js1[1];
	for(int i=2;i<=m1;i++){
		cnt1[i]=cnt1[i-1]+js1[i];
	}
	
	cnt2[1]=js2[1];
	for(int i=2;i<=m2;i++){
		cnt2[i]=cnt2[i-1]+js2[i];
	}
	for(int i=0;i<=n;i++)
		if(cnt1[i]+cnt2[n-i]>zzda)zzda=cnt1[i]+cnt2[n-i];
	printf("%d\n",zzda);
	fflush(stdout);
	fclose(stdin);fclose(stdout);
	return 0;
}







/*
	for(int i=1;i<=m1;i++){
	//	printf("p%d %d\n",s1[i].lc,s1[i].rc);
	}
	for(int i=1;i<=m1;i++){
		Add(1,1,m1+m1,s1[i].lc,s1[i].rc,1);
		int p;
		js1[p=Find(1,1,m1+m1,s1[i].lc,s1[i].rc)]++;
	//	printf("a%d\n",p);
	}//puts("qaq");
	for(int i=1;i<=m1+m1+1;i++){
		ans1[js1[i]]++;
	}
	cnt1[1]=ans1[1];
	for(int i=2;i<=m1;i++){
		cnt1[i]=cnt1[i-1]+ans1[i];
	}
//--------------------------------------------------------------------------------
	memset(a,0,sizeof(a));
	memset(lsh,0,sizeof(lsh));
	js0=1;
	for(int i=1;i<=m2;i++){
		lsh[i].s=Read();lsh[i+m2].s=Read();
		lsh[i].from=0;lsh[i+m2].from=1;
		lsh[i].id=i;lsh[i+m2].id=i;
	}
	std::sort(lsh+1,lsh+m2+m2+1);
	js0=0;
	lsh[0].s=lsh[1].s;
	for(int i=1;i<=m2+m2;i++){
		if(lsh[i].s!=lsh[i-1].s)js0++;
		if(lsh[i].from)
			s2[lsh[i].id].rc=js0;
		else s2[lsh[i].id].lc=js0;
	}
	std::sort(s2+1,s2+m2+1);
	for(int i=1;i<=m2;i++){
		Add(1,1,m2,s2[i].lc,s2[i].rc,1);
		js1[Find(1,1,m2,s2[i].lc,s2[i].rc)]++;
	}
	for(int i=1;i<=m2+m2+1;i++){
		ans2[js2[i]]++;
	}
	cnt2[1]=ans2[1];
	for(int i=2;i<=m2;i++){
		cnt2[i]=cnt2[i-1]+ans2[i];
	}
	for(int i=0;i<=n;i++)
		if(cnt1[i]+cnt2[n-i]>zzda)zzda=cnt1[i]+cnt2[n-i];
	printf("%d\n",zzda);

	return 0;
}
*/
