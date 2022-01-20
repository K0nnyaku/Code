//LFCode AK IOI
//qwaszx AK IOI
#include<bits/stdc++.h>//20pts±©Á¦ 
using namespace std;
int f1[100010],f2[100010];
int ans;
struct QwQ{
	int a;
	int b;
}p[100010];
int cmp(QwQ a1,QwQ a2){
	return a1.a<a2.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	int sz=0;
	scanf("%d%d%d",&n,&m1,&m2);
	if(n==m1+m2){
		cout<<m1+m2;
		return 0;
	}
	priority_queue<int> q;
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+1+m1,cmp);
	for(int i=1;i<=n;i++){
		sz=0;
		if(i>=m1){
			f1[i]=m1;
			continue;
		}
		for(int j=1;j<=m1;j++){
			int x,y;
			x=p[j].a;
			y=p[j].b;
			if(sz<i){
				f1[i]++;
				q.push(-y);
				sz++;
				continue;
			}
			while(q.size()){
				if(-q.top()<x){
					q.pop();
					sz--;
				}
				else
					break;
			}
			if(sz<i){
				sz++;
				q.push(-y);
				f1[i]++;
			}
		}
	}
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+1+m2,cmp);
	sz=0;
	priority_queue<int> q1;
	for(int i=1;i<=n;i++){
		if(i>=m2){
			f2[i]=m2;
			continue;
		}
		sz=0;
		for(int j=1;j<=m2;j++){
			int x,y;
			x=p[j].a;
			y=p[j].b;
			if(sz<i){
				f2[i]++;
				q1.push(-y);
				sz++;
				continue;
			}
			while(q1.size()){
				if(-q1.top()<x){
					q1.pop();
					sz--;
				}
				else
					break;
			}
			if(sz<i){
				sz++;
				q1.push(-y);
				f2[i]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,f1[i]+f2[n-i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
