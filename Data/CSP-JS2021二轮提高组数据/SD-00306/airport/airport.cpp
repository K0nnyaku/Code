#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=5e8;
int n,m1,m2,p,q,ans,res,last;
struct Inyour{
	int x, y;
}a[N],b[N];
bool cmp(Inyour e,Inyour r){
	return e.x<r.x;
}
priority_queue<int,vector<int>,greater<int> > h;
void nmsl(){
	for(int j=0;j<=n;j++){
		p=j;q=n-j;res=0;
		while(h.size())h.pop();
		if(p)for(int i=1;i<=m1;i++){
			if(h.empty()&&p>0){
				p--;
				res++;
				h.push(a[i].y);
				continue;
			}
			if(h.top()<=a[i].x){
				h.pop();
				res++;
				h.push(a[i].y);
			}else if(p>0){
				p--;
				res++;
				h.push(a[i].y);
			}
		}
		while(h.size())h.pop();
		if(q)for(int i=1;i<=m2;i++){
			if(h.empty()&&q>0){
				q--;
				res++;
				h.push(b[i].y);
				continue;
			}
			if(h.top()<=b[i].x){
				h.pop();
				res++;
				h.push(b[i].y);
			}else if(q>0){
				q--;
				res++;
				h.push(b[i].y);
			}
		}
		ans=max(ans,res);
	}
}
void inyour(int l,int r){
		if(l==r)return;
		int j=l+r>>1;
		last=j;
		p=j;q=n-j;res=0;
		while(h.size())h.pop();
		if(p)for(int i=1;i<=m1;i++){
			if(h.empty()&&p>0){
				p--;
				res++;
				h.push(a[i].y);
				continue;
			}
			if(h.top()<=a[i].x){
				h.pop();
				res++;
				h.push(a[i].y);
			}else if(p>0){
				p--;
				res++;
				h.push(a[i].y);
			}
		}
		while(h.size())h.pop();
		if(q)for(int i=1;i<=m2;i++){
			if(h.empty()&&q>0){
				q--;
				res++;
				h.push(b[i].y);
				continue;
			}
			if(h.top()<=b[i].x){
				h.pop();
				res++;
				h.push(b[i].y);
			}else if(q>0){
				q--;
				res++;
				h.push(b[i].y);
			}
		}
		ans=max(ans,res);
		inyour(l,j);
		inyour(j+1,r);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	if(n<=5000)nmsl();
	else{
		inyour(1,n);
	for(int j=max(0,last-5);j<=min(n,last+5);j++){
		p=j;q=n-j;res=0;
		while(h.size())h.pop();
		if(p)for(int i=1;i<=m1;i++){
			if(h.empty()&&p>0){
				p--;
				res++;
				h.push(a[i].y);
				continue;
			}
			if(h.top()<=a[i].x){
				h.pop();
				res++;
				h.push(a[i].y);
			}else if(p>0){
				p--;
				res++;
				h.push(a[i].y);
			}
		}
		while(h.size())h.pop();
		if(q)for(int i=1;i<=m2;i++){
			if(h.empty()&&q>0){
				q--;
				res++;
				h.push(b[i].y);
				continue;
			}
			if(h.top()<=b[i].x){
				h.pop();
				res++;
				h.push(b[i].y);
			}else if(q>0){
				q--;
				res++;
				h.push(b[i].y);
			}
		}
		ans=max(ans,res);
	}
	}
	printf("%d",ans);
	
	return 0;
}




