#include<bits/stdc++.h>
using namespace std;
bool flag=0;
int t,n,book1[500001],book2[500001],a[500001],ans[500001],R,L,cnt;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[2*n-i+1]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cout<<"L";
		}
		for(int i=1;i<=n;i++){
			cout<<"R";
		}cout<<endl;
	}
}
