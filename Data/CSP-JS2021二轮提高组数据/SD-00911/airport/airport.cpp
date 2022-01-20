#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+10,inf=1e9;
inline ll read(){
	register ll x=0,f=1;
	register char ch=getchar();
	while(ch<'0'|| ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)	putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m1,m2;
struct node{
	int a,b;
}chi[N];
struct Node{
	int a,b;
}frg[N];
inline bool cmp1(node x,node y){
	return x.a<y.a;
}
inline bool cmp2(Node x,Node y){
	return x.a<y.a;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		chi[i].a=read(),chi[i].b=read();
	}
	sort(chi+1,chi+1+m1,cmp1);
	for(int i=1;i<=m2;i++){
		frg[i].a=read(),frg[i].b=read();
	}
	sort(frg+1,frg+1+m2,cmp2);
	int ans=0;
	for(int i=0;i<=n;i++){//分给国内i个 
		int ans1=0,ans2=0;
	//	cout<<q1q.size()<<" "<<q2q.size()<<endl;
	//	cout<<q1q.top()<<"***"<<endl;
	priority_queue<int> q1q;
	priority_queue<int> q2q;
		for(int j=1;j<=m1;j++){
			if(q1q.size()){
				int tmp=q1q.top();
				while(tmp<chi[j].a){
					q1q.pop();
					tmp=q1q.top();
				}
			}
			int siz=q1q.size();
			if(siz==i) continue;
			else if(siz<i){
				ans1++;
				q1q.push(chi[j].b);
			}
		} 
		
		for(int j=1;j<=m2;j++){
			if(q2q.size())
			while(q2q.top()<frg[j].a) q2q.pop();
			int siz2=q2q.size();
			if(siz2==(n-i)) continue;
			else if(siz2<i){
				ans2++;
				q2q.push(frg[j].b);
			}
		}
		if(ans1+ans2<ans) break;
		ans=ans1+ans2;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
