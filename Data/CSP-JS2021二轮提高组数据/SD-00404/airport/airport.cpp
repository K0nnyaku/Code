#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct Air{
	int s;
	int e;
	bool z;
};
struct A{
	int s;
	int e;
}; 
bool cmd(A x, A y){
	return x.s<y.s;
}
Air e[100005];
Air f[100005];
A b[100005];//国内 
A c[100005];// 国际
int t1=0;
int t2=0;
int ans=0;
int pb(int x){//国n 
	int n1=0;//ji
	int an=0;
	bool f1=1;
	for(int t=0;t<=t2;t++){
		f1=1;
		if(b[n1].s==t){
			for(int n2=0;n2<x;n2++){
			if(e[n2].z==0){
				e[n2].s=b[n1].s;
				e[n2].e=b[n1].e;
				e[n2].z=1;
				an++;
				n1++;
				f1=0;
				break;
			}	
		}
		if(f1){
			n1++;
		}
	}
	for(int n2=0;n2<x;n2++){
		if(e[n2].e==t){
			e[n2].z=0;
		}
		
	}
}
	return an;
}
int pa(int x){//国j 
	int n1=0;//ji
	int an=0;
	bool f1=0;
	for(int t=0;t<=t1+5;t++){
		f1=0;
		if(c[n1].s==t){
			for(int n2=0;n2<x;n2++){
			if(!f[n2].z){
				f[n2].s=c[n1].s;
				f[n2].e=c[n1].e;
				f[n2].z=1;
				an++;
				n1++;
				f1=1;
				break;
			}	
		}
		if(!f1){
			n1++;
		}
	}
	for(int n2=0;n2<=x;n2++){
		if(f[n2].e==t){
			f[n2].z=0;
		}
		
	}
}
	return an;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>b[i].s>>b[i].e; 
		t1=max(t1,b[i].e);
	}
	for(int i=0;i<m2;i++){
		cin>>c[i].s>>c[i].e; 
		t2=max(t2,c[i].e);
	}
	sort(c,c+m2,cmd);
	sort(b,b+m1,cmd);
	for(int k=0;k<=n;k++){
		int sum=0;
		int p=n-k;
		for(int o=0;o<=n;o++){
			e[o].z=0;
			f[o].z=0;
		}
		sum=pb(p)+pa(k);
		ans=max(ans,sum);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4 5 6 7 8 9 10
*/
