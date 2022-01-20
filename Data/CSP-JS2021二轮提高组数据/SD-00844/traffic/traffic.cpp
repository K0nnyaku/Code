#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,T,k;
struct nod{
	int a,b,c,d,w;
}e[500];
bool v[1010][1010];
bool cmp(nod x,nod y){
	return x.w<y.w;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
		int cnt=0;
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				int x;
				cin>>x;
				cnt++;
				e[cnt].a=i;
				e[cnt].b=j;
				e[cnt].c=i+1;
				e[cnt].d=j;
				e[cnt].w=x;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				int x;
				cin>>x;
				cnt++;
				e[cnt].a=i;
				e[cnt].b=j;
				e[cnt].c=i;
				e[cnt].d=j+1;
				e[cnt].w=x;
			}
		}
		int ans=0;
		while(T!=0){
			T--;
			cin>>k;
			if(k==2){
				sort(e+1,e+1+cnt,cmp);
				for(int i=1;i<=cnt;i++){
					if(v[e[i].a][e[i].b]&&v[e[i].c][e[i].d]){
						for(int j=1;j<=i;j++){
							if((e[j].a==e[i].a&&e[j].b==e[i].b)||(e[j].a==e[i].c&&e[j].b==e[i].d)||(e[j].c==e[i].a&&e[j].c==e[i].b)||(e[j].c==e[i].c&&e[j].c==e[i].d)){
								ans+=e[j].w;
							}
						}
					}
					else{
						v[e[i].a][e[i].b]=true;
						v[e[i].c][e[i].d]=true;
					}
				}
				cout<<ans<<endl;
			}
			else cout<<"2021"<<endl;
		}
	
	return 0;
}
