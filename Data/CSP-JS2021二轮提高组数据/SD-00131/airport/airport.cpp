#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int M=100100;
inline int read(){
	int x=0;
	char ch=getchar();
	bool flag=true;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			flag=false;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return flag?x:~(x-1);
}
int n,mnei,mwai;
int lnei,lwai;
int cnei,cwai;
int maxn=-M;
priority_queue<int,vector<int>,greater<int> > qnei;
priority_queue<int,vector<int>,greater<int> > qwai;
struct f{
	int a,b;
};
f nei[M],wai[M];
bool cmp(f x,f y){
	return x.a<y.a;
}
int main(){
	n=read();
	mnei=read();
	mwai=read();
	for(int i=1;i<=mnei;i++)
		nei[i].a=read(),nei[i].b=read();
	for(int i=1;i<=mwai;i++)
		wai[i].a=read(),wai[i].b=read();
	sort(nei+1,nei+mnei+1,cmp);
	sort(wai+1,wai+mwai+1,cmp);
	for(int i=0;i<=n;i++){
		lnei=i,lwai=n-i;
		cnei=0,cwai=0;
		while(!qnei.empty()) 
			qnei.pop();
		while(!qwai.empty())
			qwai.pop();
		for(int j=1;j<=mnei;j++){
			if(lnei==0){
				cnei=0;
				continue;
			}
			if(qnei.empty()){
				cnei++;
				qnei.push(nei[j].b);
				continue;		
			}
			if(nei[j].a>=qnei.top())
				qnei.pop();
			if(qnei.size()<lnei){
				cnei++;
				qnei.push(nei[j].b);		
			}
		}
		for(int j=1;j<=mwai;j++){
			if(lwai==0){
				cwai=0;
				continue;
			}
			if(qwai.empty()){
				cwai++;
				qwai.push(wai[j].b);
				continue;
			}
			if(wai[j].a>=qwai.top())
				qwai.pop();
			if(qwai.size()<lwai){
				cwai++;
				qwai.push(wai[j].b);		
			}
		}
		maxn=maxn>(cnei+cwai)?maxn:(cnei+cwai);
	}
	printf("%d\n",maxn);
	return 0;
}

