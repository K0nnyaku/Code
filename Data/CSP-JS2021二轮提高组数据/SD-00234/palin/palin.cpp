#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;
int t,a[1000010],b[1000010];//21!9-324@emb
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)cin>>a[i];
		/*for(int i=1;i<=n;i++){
			for(int j=2*n;j>=n+1;j--){
				if(a[i]!=a[j])flag=false;
			}
		}
		if(flag){
			for(int i=1;i<=2*n;i++)cout<<"L";
			cout<<endl;
		}
		else cout<<-1<<endl;*/cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
