#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
int tt,n,m[1000010],a[1000010],oi=0,b[1000010];
deque<int> x,y;
void dfs(int step){
	if(oi!=1){
		if(step==n*2){
			//printf("haha\n");
			for(int i=0;i<n*2;i++){
				a[i]=y.front();
				y.pop_front();
				//printf("%d ",a[i]);
			}
			//printf("\n");
			for(int i=0;i<n*2;i++){
				y.push_back(a[i]);
			}
			for(int i=0;i<n;i++){
				if(a[i]!=a[n*2-i-1]){
					return ;
				}
			}
			for(int i=0;i<n*2;i++){
				if(b[i]==1){
					printf("%c",'L');
				}
				else if(b[i]==2){
					printf("%c",'R');
				}
			}
			printf("\n");
			oi=1;
			return ;
		}
		else{
			int s=x.front(),t=x.back();
			y.push_back(s);
			x.pop_front();
			b[step]=1;
			dfs(step+1);
			x.push_front(s);
			y.pop_back();
			
			y.push_back(t);
			x.pop_back();
			b[step]=2;
			dfs(step+1);
			x.push_back(t);
			y.pop_back();
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf("%d",&tt);
	for(int i=0;i<tt;i++){
		oi=0;
		scanf("%d",&n);
		for(int j=0;j<n*2;j++){
			scanf("%d",&m[j]);
			x.push_back(m[j]);
		}
		sort(m,m+n*2);
		int cnt=1;
		for(int i=1;i<n*2;i++){
			if(m[i]==m[i-1]) cnt++;
			else{
				if(cnt%2!=0){
					printf("-1\n");
					oi=1;
					break;
				}
				cnt=1;
			}
		}
		dfs(0);
		if(oi==0){
			printf("%d\n",-1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
