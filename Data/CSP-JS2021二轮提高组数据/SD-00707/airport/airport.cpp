#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector> 
#include<ctime>
#include<cstdlib>

using namespace std;

typedef unsigned long long ull; 
typedef pair<int,int> PII;
typedef long long ll;

const int N=1e5+5;

int n;
int m1;
int m2;

int read(){
	int a=0,b=1;
	char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-'){
		ch=getchar();
	}
	if(ch=='-')
	{
		b=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*b;
}

struct node{
	int b,a;
	int num;
};
node pl1[N],pl2[N];

bool cmp(node x,node y){
	return x.a<y.a;
}

int get(int x,int y){//国内x个廊桥，国外y个廊桥 
	priority_queue<int,vector<int>,greater<int> >q;//存b值 从小到大
	
	int ans=0;
	for(register int i=1;i<=m1;i++){
		if(q.size()<x){
			q.push(pl1[i].b);
			ans++;
			continue;
		}
		while(!q.empty() && q.top()<=pl1[i].a){
			q.pop();
		}
		if(q.size()<x){
			q.push(pl1[i].b);
			ans++;
		}
	} 
	priority_queue<int,vector<int>,greater<int> >q2;//存b值 从小到大
	int anss=0;
	for(register int i=1;i<=m2;i++){
		if(q2.size()<y){
			q2.push(pl2[i].b);
			anss++;
			continue;
		}
		while(!q2.empty() && q2.top()<=pl2[i].a){
			q2.pop();
		}
		if(q2.size()<y){
			q2.push(pl2[i].b);
			anss++;
		}
	} 
	return ans+anss;
}

int Max(int a,int b){
	return a>b?a:b;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	n=read();
	m1=read();
	m2=read();
	for(register int i=1;i<=m1;i++){
		pl1[i].a=read();
		pl1[i].b=read();
	}
	for(register int i=1;i<=m2;i++){
		pl2[i].a=read();
		pl2[i].b=read();
	}
	sort(pl1+1,pl1+m1+1,cmp);
	sort(pl2+1,pl2+m2+1,cmp);
	int minn=0;
	for(register int i=0;i<=n;i++){
		minn=Max(minn,get(i,n-i));
	}
	printf("%d\n",minn);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//21!9-324@emb

