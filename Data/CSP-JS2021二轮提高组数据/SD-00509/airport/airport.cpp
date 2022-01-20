#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define mx 100005
using namespace std;
struct node{
	int st;
	int en;
	bool operator < (const node &x)const
	{
		return x.st<st;
	}
};
int n,m1,m2;
int k1[mx];//国内 
int end[mx];
priority_queue <node> q;
int k2[mx];//国际

int a,b;
node in;
int tot=0;
int main(void){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	
	if(n>=m1+m2){
		cout<<m1+m2<<endl;
		return 0;
	}
	
	while(m1--){
		cin>>a>>b;
		in.st=a;
		in.en=b;
		q.push(in);
	}
	
	while(!q.empty()){
		in=q.top();
		q.pop();
		for(int i=1;i<=n;i++){
			if(in.st>end[i]){
				end[i]=in.en;
				k1[i]++;
				break;
			}
		}
	}
	
	while(m2--){
		cin>>a>>b;
		in.st=a;
		in.en=b;
		q.push(in);
	}
	memset(end,0,sizeof(end));
	
	while(!q.empty()){
		in=q.top();
		q.pop();
		for(int i=1;i<=n;i++){
			if(in.st>end[i]){
				end[i]=in.en;
				k2[i]++;
				break;
			}
		}
	}
	int ans;
	int maxx=-1;
	for(int t=0;t<=n;t++){
		ans=0;
		for(int i=1;i<=t;i++)  ans+=k1[i];
		for(int i=1;i<=n-t;i++) ans+=k2[i];
		maxx=max(maxx,ans);
	}
	cout<<maxx<<endl;
	return 0;
}
