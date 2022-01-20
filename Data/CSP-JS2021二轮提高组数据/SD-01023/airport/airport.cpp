#include<bits/stdc++.h>
using namespace std;
namespace _zzd{
	const int maxn=1e5+10;
	int n,m1,m2,ans,temp,Max1,Max2;
	struct node{
		int s,t;
	}a1[maxn],a2[maxn];
	
	bool vis[105];
	priority_queue<int> q;
	void read(int &x){
		x=0;int f=1;char c=getchar();
		while(c<'0'||c>'9'){
		if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		x=x*f;
	}	
	
   bool cmp(node a,node b){
   	return a.s<b.s;
   }
   
void check(int x){
		int sum=0,head=1;
		temp=0;
    for(int i=1;i<=Max1;i++){
    	while(q.size()){
    		int p=-q.top();
    		if(p<i) {q.pop(),sum--;continue;}
    		 break;
		}
		while(a1[head].s<i) head++;
    	while(sum<x&&head<=m1&&i==a1[head].s) q.push(-a1[head].t),head++,temp++,sum++;
    
	}


	sum=0,head=1;
	while(q.size()) q.pop();
	
	 for(int i=1;i<=Max2;i++){
    	while(q.size()){
    		int p=-q.top();
    		if(p<i) {q.pop(),sum--;continue;}
    		 break;
		}
			while(a2[head].s<i)head++;
    	while(sum<n-x&&head<=m2&&i==a2[head].s) q.push(-a2[head].t),head++,temp++,sum++;
	}
		while(q.size()) q.pop();
	}
	void check1(int x){
		int sum=0,head=1;
		temp=0;
    for(int i=a1[head].s;i<=Max1;i++){
    	while(q.size()){
    		int p=-q.top();
    		if(p<i) {q.pop(),sum--;continue;}
    		 break;
		}
		
    	if(sum<x&&head<=m1) q.push(-a1[head].t),head++,temp++,sum++;
    
	}


	sum=0,head=1;
	while(q.size()) q.pop();
	
	 for(int i=a2[head].s;i<=Max2;i++){
    	while(q.size()){
    		int p=-q.top();
    		if(p<i) {q.pop(),sum--;continue;}
    		 break;
		}
		
    	if(sum<n-x&&head<=m2) q.push(-a2[head].t),head++,temp++,sum++;
	}
		while(q.size()) q.pop();
	}
	
	void part1(){
			int l=1;int r=n;
			while(l<=r){
				int mid=(l+r)>>1;
			check(mid); if(temp>ans&&mid>=n-mid) ans=temp,l=mid+1;
			else ans=max(ans,temp),r=mid-1;
	}} 
	void part2(){
		for(int i=0;i<=n;i++)
	check1(i),ans=max(ans,temp);
	}
	void part3(){
		int l=1;int r=n;
	
			while(l<=r){
				int mid=(l+r)>>1;
			check1(mid); if(temp>ans&&mid>=n-mid) ans=temp,l=mid+1;
			else ans=max(ans,temp),r=mid-1;
	}}
	void mymain(){
		scanf("%d%d%d",&n,&m1,&m2);
			for(int i=1;i<=m1;i++){
			scanf("%d%d",&a1[i].s,&a1[i].t);
			Max1=max(Max1,a1[i].t);	
			}
			for(int i=1;i<=m2;i++){
			scanf("%d%d",&a2[i].s,&a2[i].t);
			Max2=max(Max2,a2[i].t);	
			}
			sort(a1+1,a1+1+m1,cmp);
			sort(a2+1,a2+1+m2,cmp);
			
			if(n<=3000){
		for(int i=0;i<=n;i++)
	check(i),ans=max(ans,temp);
			
			}
	if(n>3000&&n<5000) part1();
	if(n>=5000&&n<400000) part2();
	if(n>=400000)part3();
	printf("%d",ans);
			return;
		}
}
int main(){	

 freopen("airport.in", "r", stdin);
freopen("airport.out", "w", stdout);
 //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<1;
_zzd::mymain();
	//fclose(stdin);
    //fclose(stdout);

	return 0;
}

