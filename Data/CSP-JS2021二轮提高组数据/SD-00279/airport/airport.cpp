#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
struct node{
	int l,r;
}a[N],b[N];
int n,s,t,sum,ans;
bool cmp(node aa,node bb){
	return aa.l<bb.l;
}
void check1(int x){
	priority_queue<int> q;
	if(x==0) return;
	int rest=x;
	for(int i=1;i<=s;i++){
		if(rest){
			rest--;
			sum++;
			q.push(-a[i].r);
		}
		else{
			while(!q.empty()&&-q.top()<=a[i].l){
				q.pop();
				rest++;
			}
			if(rest){
				rest--;
				q.push(-a[i].r);
				sum++;
			}
		}
	}
}
void check2(int x){
	priority_queue<int> q;
	if(x==0) return;
	int rest=x;
	for(int i=1;i<=t;i++){
		if(rest){
			rest--;
			sum++;
			q.push(-b[i].r);
		}
		else{
			while(!q.empty()&&-q.top()<=b[i].l){
				q.pop();
				rest++;
			}
			if(rest){
				rest--;
				sum++;
			}
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); s=read(); t=read();
	for(int i=1;i<=s;i++){
		a[i].l=read();
		a[i].r=read();
	}
	for(int i=1;i<=t;i++){
		b[i].l=read();
		b[i].r=read();
	}
	sort(a+1,a+s+1,cmp);
	sort(b+1,b+t+1,cmp);
	for(int i=0;i<=n;i++){
		sum=0;
		check1(i); check2(n-i);
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
