#include<iostream> 
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
void file(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int n=0;
	while(c>='0'&&c<='9'){
		n=n*10+c-'0';
		c=getchar();
	}
	return n;
}
const int MAX_N=1e5+500;
struct Plain{
	int s,t;
} p1[MAX_N],p2[MAX_N];
bool cmp(Plain a,Plain b){
	return a.s<b.s;
}

int test(int m,int n,Plain* ps){
	priority_queue<int,deque<int> ,greater<int> > q;
	int ans=0,l=0;
	for(int i=1;i<=m;i++){
		//!
		while(q.size()&&q.top()<=ps[i].s){
			q.pop();
			l--;
		}
		if(l<n){
			l++;
			ans++;
			q.push(ps[i].t);
		}
	}
	return ans;
}
int ans=0;
int calc(int m1,int m2,int i,int n){
	if(i>n)return 0;
	int v=test(m1,i,p1)+test(m2,n-i,p2);
	ans=max(v,ans);
	return v;
}
int main(){
	file();
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		cin>>p1[i].s>>p1[i].t;
	}
	for(int i=1;i<=m2;i++){
		cin>>p2[i].s>>p2[i].t;
	}
	sort(p1+1,p1+1+m1,cmp);
	sort(p2+1,p2+1+m2,cmp);
	int l=1,r=n-1;
	while(l<r){
		int mid=(l+r)>>1; 
		if(calc(m1,m2,mid,n)<calc(m1,m2,mid+1,n)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
