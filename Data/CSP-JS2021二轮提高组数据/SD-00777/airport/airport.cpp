#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n,m1,m2;
int maxx=-1;
int vis[100005];
int ans[100005];
int Ans,cnt;
queue<int> q1,q2;

struct node{
	
	int l,r,data;
		
}a[100005];

int cmp(node x,node y){
	
	return x.l<y.l;
	
}

int rd(){
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){	
		if(ch=='-') r=-1;
		ch=getchar();	
	}
	while(ch>='0'&&ch<='9'){
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();	
	}
	return r*w;
}

void get_data(){
	
	n=rd();m1=rd();m2=rd();
	for(int i=1;i<=m1;i++){
		
		a[i].l=rd();
		a[i].r=rd();
		a[i].data=1;
		
	}
	for(int i=m1+1;i<=m2+m1;i++){
		
		a[i].l=rd();
		a[i].r=rd();
		a[i].data=2;
		
	}
	
}

void print_data(){
	for(int i=1;i<=n;i++) Ans+=ans[i];
	cout<<Ans<<endl;
}

void calc_data(){
	
	sort(a+1,a+m1+m2+1,cmp);
	
	for(int i=1;i<=m1+m2;i++){
		
		if(a[i].data==1&&!vis[i]){
			vis[i]=1;
			ans[i]++;
			q1.push(a[i].r);
			for(int j=1;j<=m1+m2;j++)
				if(a[j].data==1&&a[j].l>=q1.front()&&!vis[j]){
					q1.pop();
					q1.push(a[j].r);
					vis[j]=1;
					ans[i]++;
				}
			q1.pop();
		}
		if(a[i].data==2&&!vis[i]){
			ans[i]++;
			vis[i]=1;
			q2.push(a[i].r);
			for(int j=1;j<=m1+m2;j++)
				if(a[j].data==2&&a[j].l>=q2.front()&&!vis[j]){
					q2.pop();
					q2.push(a[j].r);
					ans[i]++;
					vis[j]=1;
				}
			q2.pop();
		}

	}
	
	print_data();
	
}

int main(){

	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	get_data(); 
	
	calc_data();
	
	return 0;

}
