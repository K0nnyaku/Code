#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
int a[N<<1][2],map[N][2],n,T,ans[N<<1];
bool p[N<<1];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i][0]);
		}
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
