#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m1,m2;
int ans=-2e9;
struct node{
	int start,end;
}a[100005],b[100005];
int cnt;
priority_queue<int> q;
bool cmp(node x,node b){
	return x.start<b.start; 
}
int check(int x,int y){
	int sum=0;
	cnt=x;
	while(!q.empty())q.pop(); 
	for(int i=1;i<=m1;i++){
		if(cnt>0){
			cnt--;
			sum++;
			q.push(-a[i].end);
		}
		else if(cnt==0){
			if(!q.empty()){
			int x=-q.top();
			if(a[i].start>x){
				q.pop();
				q.push(-a[i].end);
				sum++; 
			}	
			}	
		}
	}
	cnt=y;
	while(!q.empty())q.pop();
	for(int i=1;i<=m2;i++)
	{
		if(cnt>0){
			cnt--;
			sum++;
			q.push(-b[i].end);
		}
		if(cnt==0){
			if(!q.empty()){
			int x=-q.top();
			if(b[i].start>x)
			{
				q.pop();
				q.push(-b[i].end);
				sum++;
			}
			}
		}
	}
	return sum;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].start,&a[i].end);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].start,&b[i].end);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++){	
		ans=max(check(i,n-i),ans); 
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
