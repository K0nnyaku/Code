#include<bits/stdc++.h>
using namespace std;
struct plane{
	int l,r;
}s1[100005],s2[100005];
int n,m1,m2,shu1[100005],shu2[100005],f1[100005],f2[100005],ans=0,do1[100005],do2[100005];
bool cmp(plane h1,plane h2){
	return h1.l<h2.l;
}
int main(){
	freoepn("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		scanf("%d",&s1[i].l);
		scanf("%d",&s1[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d",&s2[i].l);
		scanf("%d",&s2[i].r);
	}
	sort(s1+1,s1+1+m1,cmp);
	sort(s2+1,s2+1+m2,cmp);
	if(n>=m1+m2){
		cout<<m1+m2<<endl;
		return 0;
	}
	int w=0,mk,jliju;
	for(int i=1;i<=m1;i++){
		mk=0;
		for(int j=1;j<=w;j++){
			if(s1[i].l>=do1[j]){
				mk++;do1[j]=s1[i].r;f1[j]++;break;
			}
		}
		if(!mk){
			if(w>=n)continue;
			w++,do1[w]=s1[i].r,f1[w]++;
		}
	}
	w=0;
	for(int i=1;i<=m2;i++){
		mk=0;
		for(int j=1;j<=w;j++){
			if(s2[i].l>=do2[j]){
				mk++;do2[j]=s2[i].r;f2[j]++;break;
			}
		}
		if(!mk){
			if(w>=n)continue;
			w++,do2[w]=s2[i].r,f2[w]++;
		}
	}
	for(int i=1;i<=m1&&i<=n;i++)shu1[i]=shu1[i-1]+f1[i];
	for(int i=1;i<=m2&&i<=n;i++)shu2[i]=shu2[i-1]+f2[i];
	for(int i=0;i<=m1&&n-i>=0;i++){
		if(ans<shu1[i]+shu2[n-i])ans=shu1[i]+shu2[n-i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
