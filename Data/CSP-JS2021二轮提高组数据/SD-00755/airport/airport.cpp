#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

inline int read(){
	int ch=0;
	char xxx=getchar();
	while(!(xxx>='0'&&xxx<='9')) xxx=getchar();
	while(xxx>='0'&&xxx<='9'){
		ch=ch*10+xxx-'0';
		xxx=getchar();
	}
	return ch;
}

struct node{
	int a,b;
}nei[100010],wai[100010];

inline bool cmp(node pl1,node pl2){
	return pl1.a<pl2.a;
}

int n,m1,m2,brd1,brd2;//brd1国内廊桥 brd2国外廊桥 

int nei_ck(){
	if(brd1<=0||m1<=0) return 0;
	int mx=brd1,ans=0;
	priority_queue<int> q;
	
	for(int i=1;i<=m1;i++){
		if(mx){
			q.push(-nei[i].b);
			mx--;
			ans++;
			continue;
		}
		if(nei[i].a>(-q.top())){
			q.pop();
			q.push(-nei[i].b);
			ans++;
		}
	}
	return ans;
}

int wai_ck(){
	if(brd2<=0||m2<=0) return 0;
	int mx=brd2,ans=0;
	priority_queue<int> q;
	for(int i=1;i<=m2;i++){
		if(mx){
			q.push(-wai[i].b);
			mx--;
			ans++;
			continue;
		}
		if(wai[i].a>(-q.top())){
			q.pop();
			q.push(-wai[i].b);
			ans++;
		}
	}
	return ans;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		nei[i].a=read();
		nei[i].b=read();
	}
	for(int i=1;i<=m2;i++){
		wai[i].a=read();
		wai[i].b=read();
	}
	sort(nei+1,nei+m1+1,cmp);
	sort(wai+1,wai+m2+1,cmp);
	int f_ans=0;
	for(int i=0;i<=n;i++){
		brd1=i;brd2=n-i;
		int as1=nei_ck(),as2=wai_ck();
		f_ans=max(f_ans,as1+as2);
	}
	printf("%d",f_ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
e1
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

e2
*/
