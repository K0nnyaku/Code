#include<bits/stdc++.h>
using namespace std;
//#define int long long
int read()
{
	int x=0,w=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-'){ch=getchar();w=-1;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*w;
}
const int N=1e5+100;
int n,m1,m2;
struct node{
	int a,b;
}f1[N],f2[N];
priority_queue<int>q;
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int calc(int x)
{
	while(!q.empty()) q.pop();
	int res=0;
	for(int i=1;i<=m1;++i){
		while(!q.empty()&&-q.top()<f1[i].a) q.pop();
		if(q.size()<x){
			res++;
			q.push(-f1[i].b);
		}
	}
	while(!q.empty()) q.pop();
	for(int i=1;i<=m2;++i){
		while(!q.empty()&&-q.top()<f2[i].a) q.pop();
		if(q.size()<n-x){
			res++;
			q.push(-f2[i].b);
		}
	}
	return res;
}
bool check(int x)
{
	if(calc(x)<calc(x+1)) return 0;
	return 1;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    n=read();m1=read();m2=read();
    for(int i=1;i<=m1;++i){
    	f1[i].a=read();
    	f1[i].b=read();
	}
	for(int i=1;i<=m2;++i){
		f2[i].a=read();
		f2[i].b=read();
	}
	sort(f1+1,f1+m1+1,cmp);
	sort(f2+1,f2+m2+1,cmp);
	int l=-1,r=n;
	while(l+1<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<calc(r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 6 4 
19 20
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
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
