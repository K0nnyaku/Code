#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int M=100005;
int n,m1,m2,max1,max2,a,b,maxx;
struct node{
	int in;
	int out;
}p1[M],p2[M],b1[M],b2[M];
bool cmp1(node a,node b){
	return a.out<b.out;
}
bool cmp2(node a,node b){
	return a.in<b.in;
}
priority_queue < int > q1,q2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>p1[i].in>>p1[i].out;
		b1[i].in=p1[i].in;
		b1[i].out=p1[i].out;
	}
	for(int i=1;i<=m2;i++){
		cin>>p2[i].in>>p2[i].out;
		b2[i].in=p2[i].in;
		b2[i].out=p2[i].out;
	}
//	sort(p1+1,p1+1+m1,cmp1);//p:outÉýÐò 
//	sort(p2+1,p2+1+m2,cmp1);//p:outÉýÐò 
	sort(b1+1,b1+1+m1,cmp2);//b:inÉýÐò 
	sort(b2+1,b2+1+m2,cmp2);//b:inÉýÐò 
	//for(int i=1;i<=m1;i++)cout<<b1[i].in<<" ";
	int used=0,ans=0;
	for(int i=1;i<=n;i++){
		ans=0,used=0;
		while(q1.size())q1.pop();
		for(int j=1;j<=m1;j++){
			if(used>0)while(-q1.top()<b1[j].in&&q1.size()){
				used--;
				q1.pop();
			}
			if(used<i){
				used++;
				ans++;
				q1.push(-b1[j].out);	
			}	
		}
		used=0;
		while(q2.size())q2.pop();
		for(int j=1;j<=m2;j++){
			if(used>0)while(-q2.top()<b2[j].in&&q2.size()){
				used--;
				q2.pop();
			}
			if(used<n-i){
				used++;
				ans++;
				q2.push(-b2[j].out);	
			}	
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx<<endl;
	return 0;
}

