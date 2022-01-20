#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
const int N = 1e6+5; 
struct aaa{
	int x;int y;
}num1[N],num2[N];int ans[N][2];
bool cmp(aaa a,aaa b){
	return a.x<b.x;
}
queue<aaa>q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d %d %d",&n,&m1,&m2);
	int u,v;
	for(int i=1;i<=m1;i++){
		scanf("%d %d",&u,&v);
		num1[i].x = u;num1[i].y = v;
	}
	sort(num1+1,num1+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		scanf("%d %d",&u,&v);
		num2[i].x = u;num2[i].y = v;
	}
	sort(num2+1,num2+1+m2,cmp);
	
	for(int i=1;i<=n;i++){
		while(!q.empty()){
			q.pop();
		}
		q.push(num1[1]);
		
		ans[i][0] = 1;
		for(int j=2;j<=m1;j++){
			while(q.front().y<num1[j].x&&!q.empty()){
//				cout<<j<<": "<<q.front().y<<"\n";
				q.pop();
			}
			if(q.size()+1<=i){
				q.push(num1[j]);
				ans[i][0]++;
			}
		}
		while(!q.empty()){
			q.pop();
		}
		q.push(num2[1]);
		ans[i][1] = 1;
		for(int j=2;j<=m2;j++){
			while(q.front().y<num2[j].x&&!q.empty()){
				q.pop();
			}
			if(q.size()+1<=i){
				q.push(num2[j]);
				ans[i][1]++;
			}
		}
	}
	int anss = -1;
	for(int i=0;i<=n;i++){
//		cout<<i<<" "<<n-i<<" "<<ans[i][0]<<" "<<ans[n-i][1]<<"\n";
		anss = max(anss,ans[i][0]+ans[n-i][1]);
	}
	printf("%d",anss);
//	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
/*
1 5 0
1 5
3 8
6 10
9 14
13 18
*/
