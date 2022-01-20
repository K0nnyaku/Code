#include <bits/stdc++.h>
#define f(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,M1,M2,res,ans;
struct pt {
	int a,b;
}p[N],q[N];
priority_queue<int>Q;
inline bool cmp(pt j,pt k)
{
	return j.a<k.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&M1,&M2);
	f(i,1,M1) {
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	f(i,1,M2) {
		scanf("%d%d",&q[i].a,&q[i].b);
	}
	sort(p+1,p+1+M1,cmp);
	sort(q+1,q+1+M2,cmp);
	if(n<=5000) {
		int n1,n2,k1=0,k2=0;
		
		f(i,0,n) {
			ans=0,k1=0,k2=0,n1=i,n2=n-i;
			while(Q.size())Q.pop();
			f(j,1,M1) {
				while(Q.size()&&p[j].a>-Q.top()) {
					Q.pop();
					--k1;
				}
				if(k1<n1) {
					++ans;++k1;
//					cout<<p[j].a<<"\n";
					Q.push(-p[j].b);
				}
			} 
			while(Q.size())Q.pop();
			f(j,1,M2) {
				while(Q.size()&&q[j].a>-Q.top()) {
					Q.pop();
					--k2;
				}
				if(k2<n2) {
					++ans;++k2;
//					cout<<q[j].a<<'\n';
					Q.push(-q[j].b);
				}
			}
			res=max(res,ans);
//			cout<<"\n";
		}
		cout<<res;
		return 0;
	}
	else {
		bool vis[100003];
		f(i,1,100000)vis[i]=0;
		srand(20041107);
		int n1,n2,k1=0,k2=0;
		int i=rand()%(n+1),num=0;
		while(num<=100)
		{
			i=rand()%(n+1);
			if(vis[i])continue; 
			vis[i]=1;num++;
			ans=0,k1=0,k2=0,n1=i,n2=n-i;
			while(Q.size())Q.pop();
			f(j,1,M1) {
				while(Q.size()&&p[j].a>-Q.top()) {
					Q.pop();
					--k1;
				}
				if(k1<n1) {
					++ans;++k1;
//					cout<<p[j].a<<"\n";
					Q.push(-p[j].b);
				}
			} 
			while(Q.size())Q.pop();
			f(j,1,M2) {
				while(Q.size()&&q[j].a>-Q.top()) {
					Q.pop();
					--k2;
				}
				if(k2<n2) {
					++ans;++k2;
//					cout<<q[j].a<<'\n';
					Q.push(-q[j].b);
				}
			}
			res=max(res,ans);
//			cout<<"\n";
		}
		cout<<res;
		return 0;
	}
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
