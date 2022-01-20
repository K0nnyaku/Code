#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<vector>

using namespace std;

const int N = 100000+10;

int n,m1,m2;
struct Node{
	int l,r;
}a[N],b[N];
bool cmp(Node x,Node y){
	return x.l<y.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	int ans=0;
	priority_queue<int> q;
	while(q.size()) q.pop();
	for(int i=0;i<=n;i++){
		while(q.size()) q.pop();
		int num1=i,num2=n-i;
		int sum=0;
		
		if(num1!=0){
			
			num1--;
			sum++;
			q.push(-a[1].r);
			
			for(int j=2;j<=m1;j++){
				if(a[j].l>(-q.top())){
					q.pop();
					q.push(-a[j].r);
//					num1++;
					sum++;
				}
				else if(num1){
					num1--;sum++;
					q.push(-a[j].r);
				}
			}
			
		}
		while(q.size()) q.pop();
		
		if(num2!=0){
			num2--;
			sum++;
			q.push(-b[1].r);
			
			for(int j=2;j<=m2;j++){
				if(b[j].l>(-q.top())){
					q.pop();
					q.push(-b[j].r);
//					num2++;
					sum++;
				}
				else if(num2){
					num2--;sum++;
					q.push(-b[j].r);
				}
			}
			
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}

