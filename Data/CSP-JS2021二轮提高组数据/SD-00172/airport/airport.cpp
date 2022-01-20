#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m1,m2,ans,maxa;
int lst[5001];
struct node{
	int arr,lev;
}gn[100010],gw[100010];
inline int qread(){
	char c=getchar(),o=' ';int x=0;
	while(c>'9'||c<'0')o=c,c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=getchar();
	if(o=='-')return -x;return x;
}
inline bool cmp(node x,node y){
	return x.arr<y.arr;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=qread(),m1=qread(),m2=qread();
	for(int i=1;i<=m1;++i){
		gn[i].arr=qread(),gn[i].lev=qread();
	}
	for(int i=1;i<=m2;++i){
		gw[i].arr=qread(),gw[i].lev=qread();
	}
	sort(gn+1,gn+m1+1,cmp);sort(gw+1,gw+m2+1,cmp);
	for(int i=0;i<=n;++i){
		ans=0;
		int gnline=i,gwline=n-i;
		memset(lst,0,sizeof(lst));
		for(int j=1;j<=m1;++j){
			for(int k=1;k<=gnline;++k){
				if(gn[j].arr>lst[k]){
					lst[k]=gn[j].lev;
					ans++;
					break;
				}
			}
		}
//		cout<<i<<" gn ans="<<ans<<"  ";
		memset(lst,0,sizeof(lst));
		for(int j=1;j<=m2;++j){
			for(int k=1;k<=gwline;++k){
				if(gw[j].arr>lst[k]){
					lst[k]=gw[j].lev;
					ans++;
					break;
				}
			}
		}
		maxa=max(maxa,ans);
//		cout<<" tot ans="<<ans<<"---\n";
	}
	cout<<maxa<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
