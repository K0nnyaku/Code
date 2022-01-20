#include<bits/stdc++.h>
#include<cstdio>
#include<functional>
using namespace std;
struct node{
	int a,b;
}fc[100010],fa[100010];
bool cmp(node a,node b){
	return a.a<b.a;
}
struct ttt{
	int ti,num;
}fin1[100010],fin2[100010];
int n,m1,m2,maxn=-1,ans1[100010],ans2[100010],_ans=-2;
void check(){
	priority_queue<int,vector<int>,greater<int> > q;
	int res=0;
	while(!q.empty())q.pop(); 
	for(int i=1;i<=m1;i++){
		int s=fc[i].a;
		while(!q.empty()&&s>q.top()){
			q.pop();
		}
		q.push(fc[i].b);
		if(fin1[q.size()].ti>s){
			 ans1[q.size()]+=i-fin1[q.size()].num; 
			 fin1[q.size()].ti=max(fc[i].b,fin1[q.size()].ti);
			 fin1[q.size()].num=i;
		}else {
			ans1[q.size()]+=q.size();
			fin1[q.size()].ti=fc[i].b;
			fin1[q.size()].num=i;
		}
		
	}
	
	while(!q.empty())q.pop(); 
	for(int i=1;i<=m2;i++){
		int s=fa[i].a;
		q.push(fa[i].b);
		if(fin2[q.size()].ti>s){
			 ans2[q.size()]+=i-fin2[q.size()].num; 
			 fin2[q.size()].ti=max(fa[i].b,fin2[q.size()].ti);
		}else {
			ans2[q.size()]+=q.size();
			fin2[q.size()].ti=fa[i].b;
		}
	}
	return;
}
void getans(int ans){
	priority_queue<int,vector<int>,greater<int> > q;
	int res=0;
	while(!q.empty())q.pop(); 
	for(int i=1;i<=m1;i++){
		int s=fc[i].a;
		while(!q.empty()&&s>q.top()){
			q.pop();
		}
		if(q.size()<ans){
			res++;
			q.push(fc[i].b);
		}
		 
	}
	
	while(!q.empty())q.pop(); 
	for(int i=1;i<=m2;i++){
		int s=fa[i].a;
		while(!q.empty()&&s>q.top()){
			q.pop();
		}
		if(q.size()<n-ans){
			res++;
			q.push(fa[i].b);
		}
	}
	_ans=max(_ans,res);
	
	return;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&fc[i].a,&fc[i].b);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&fa[i].a,&fa[i].b);
	}
	sort(fc+1,fc+1+m1,cmp);
	sort(fa+1,fa+1+m2,cmp);
	check();
	//int ff;
	for(int i=0;i<=n;i++){
		if(ans1[i]+ans2[n-i]>maxn){
			maxn=ans1[i]+ans2[n-i];
		//	ff=i;
		}
	}
	for(int i=0;i<=n;i++){
		if(ans1[i]+ans2[n-i]==maxn){
			getans(i);
		}
	}
	//getans(ff);
	printf("%d",_ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
