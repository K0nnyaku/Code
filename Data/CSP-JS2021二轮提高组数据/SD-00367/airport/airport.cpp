#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

#define maxn 1000005

using namespace std;
int n;
int cn,fr;
int a1[maxn],b1[maxn];
int a2[maxn],b2[maxn];
int f1[maxn],f2[maxn];
int q1[maxn],q2[maxn];
int head1,head2;
int ans;

int main(){
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%d",&cn);
	scanf("%d",&fr);
	for(int i = 1;i <= cn;i++){
		scanf("%d",&a1[i]);
		scanf("%d",&b1[i]);
	}
	for(int i = 1;i <= fr;i++){
		scanf("%d",&a2[i]);
		scanf("%d",&b2[i]);
	}
	for(int i = 1;i <= cn;i++){
		int cnt = 1;
		int now1;
		if(!f1[i]){
			now1 = b1[i];
			for(int j = i;j <= cn;j++){
			    if(now1 <= a1[j] && !f1[j]){
			    	now1 = b1[j];
				    cnt++;
				    f1[j] = 1;
			    }
	     	}
	     	f1[i] = 1;
	     	head1++;
	     	q1[head1] = cnt;
		}
	}
	for(int i = 1;i <= fr;i++){
		int cnt = 1;
		int now2;
		if(!f2[i]){
			now2 = b2[i];
			for(int j = i;j <= fr;j++){
			    if(now2 <= a2[j] && !f2[j]){
			    	now2 = b2[j];
				    cnt++;
				    f2[j] = 1;
			    }
	     	}
	     	f2[i] = 1;
	     	head2++;
	     	q2[head2] = cnt;
		}
	}
	for(int i = 1;i <= n;i++){
		int gg = 0;
		int x = i;
		int y = n-i;
		for(int j = 1;j <= x;j++) gg += q1[j];
		for(int j = 1;j <= y;j++) gg += q2[j];
		ans = max(ans,gg);
	}
	printf("%d\n",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
//90% 

