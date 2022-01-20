#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}f[3][100005];
int n,m[3],ans;
int z[100005],tot=0,an;
bool cmp(node x,node y){
	return x.a<y.a;
}
int fp(int x,int y){
	memset(z,0,sizeof(z));tot=0;an=0;
	for(int i=1;i<=m[y];i++){
		if(tot<x){
			tot++;
			z[tot]=f[y][i].b;
			an++;
		}
		sort(z+1,z+1+tot);
		for(int j=1;j<=tot;j++){
			if(f[y][i].a>z[j]){
				z[j]=f[y][i].b;
				an++;
				continue;
			}
		}
	}
	cout<<an<<endl;
	return an;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[1],&m[2]);
	for(int i=1;i<=m[1];i++){
		scanf("%d%d",&f[1][i].a,&f[1][i].b);
	}
	for(int i=1;i<=m[2];i++){
		scanf("%d%d",&f[2][i].a,&f[2][i].b);
	}
	//sort(fn+1,fn+1+m1,cmp);
	//sort(fw+1,fw+1+m2,cmp);
	for(int i=0;i<=n;i++){
		ans=max(ans,fp(i,1)+fp(n-i,2));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
