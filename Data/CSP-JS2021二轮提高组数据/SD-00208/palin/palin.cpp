#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5e5+10;
int a[2*N];
int dis[N][2];
struct aa{
	int dis;int rnk;
}num[N];
bool cmp(aa a,aa b){
	if(a.dis==b.dis){
		return min(dis[a.dis][0],dis[a.dis][1])<=min(dis[b.dis][0],dis[b.dis][1]); 
//		return a.rnk>b.rnk;
	}
	return a.dis>b.dis;
}
bool ans[2*N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;bool vis=0;
		memset(dis,-1,sizeof(dis));
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
//			cout<<a[i]<<'\n';
			if(dis[a[i]][0]==-1){
				dis[a[i]][0] = i-1;
			}else{
				dis[a[i]][1] = 2*n-i;
				num[a[i]].dis = abs(dis[a[i]][1]-dis[a[i]][0]);
				num[a[i]].rnk = a[i];
			}
		}
//		cout<<"!!!"<<dis[4][0]<<" "<<dis[4][1]<<" "<<num[4].dis<<" "<<num[4].rnk<<'\n';
		int l = 1,r = 2*n;
		sort(num+1,num+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<num[i].rnk<<" "<<num[i].dis<<"\n";
//		}
		cout<<"\n";
		for(int i=1;i<=n;i++){
			if(a[l]==num[i].rnk){
				ans[i]=1;
				l++;
			}else if(a[r]==num[i].rnk){
				ans[i]=0;
				r--;
			}else{
				vis = 1;
				break;
			}
		}
		if(vis==1){
			printf("-1\n");
			continue;
		}
		for(int i=n;i>=1;i--){
			if(a[l]==num[i].rnk){
				ans[2*n-i+1]=1;
				l++;
			}else if(a[r]==num[i].rnk){
				ans[2*n-i+1]=0;
				r--;
			}else{
				vis=1;
				break;
			}
		}
		if(vis==1){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;i++){
			if(ans[i]==1){
				printf("L");
			}else{
				printf("R");
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
/*
1
20
3 5 13 2 19 9 20 6 11 4 10 8 7 17 15 1 18 14 16 18 15 17 7 12 8 10 4 11 6 20 9 19 2 13 3 5 1 14 16 12
*/
