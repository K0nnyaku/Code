#include<cstdio>
#include<iostream>
using namespace std;
int b[1010];
int pp(int x){
	int n=1;
	for(int i=1;i<=x;i++)
	n*=2;
	return n;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n,m,a[5010],c[1010],p;
	char s[1010];
	scanf("%d",&n);
	for(int l=1;l<=n;l++){
		cin>>m;
		m=m*2;
		for(int i=1;i<=m;i++)
		b[i]=0;
		for(int i=1;i<=m;i++)
		cin>>a[i];
		
		long long qq=pp(m);
		b[m]=-1;
		for(int j=0;j<qq;j++){
		b[m]++;
		for(int i=m;i>=1;i--)
		if(b[i]==2){
			b[i]=0;
			b[i-1]++;
		} 
		
		int ll=1,rr=m;
		for(int i=1;i<=m;i++){
			if(b[i]==0){
				c[i]=a[ll];
				ll++;
				}
			if(b[i]==1) {
				c[i]=a[rr];
				rr--;} }
		 p=1;
		for(int i=1;i<=m;i++)
			if(c[i]!=c[m-i+1]) {
			p=0;
			break;}
		if(p==1) {
		for(int i=1;i<=m;i++)
		if(b[i]==0) cout<<"L";
		else cout<<"R";
		cout<<endl;
		break;
	}}
		if(p==0)
		cout<<"-1"<<endl; 
	
		}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
