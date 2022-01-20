#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct plane{
	int a;
	int b;
};
bool cmp(plane x,plane y){
	if(x.a>y.a){
		return false;
	}else if(x.a==y.a){
		if(x.b>y.b){
			return false;
		}
	}
	return true;
}
plane inside[100010];
plane outside[100010];
int n,m1,m2,ans,ans1,ans2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airpor.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>inside[i].a>>inside[i].b;
	}
	for(int i=1;i<=m2;i++){
		cin>>outside[i].a>>outside[i].b;
	}
	sort(inside+1,inside+m1+1,cmp); 
	sort(outside+1,outside+m2+1,cmp);
	
	for(int i=0;i<=min(m1,n);i++){
		int j=n-i;
		
		int ansi=0;
		if(i!=0){
			queue<plane>mi;
			for(int x=1;x<=m1;x++){
				if(mi.size()<i){
					mi.push(inside[x]);
					ansi++;
				}else{
					if(mi.front().b<inside[x].a){
						mi.pop();
						mi.push(inside[x]);
						ansi++; 
					}
				}
			}
		}
		
		int ansj=0;
		if(j!=0){
			queue<plane>mj;	
			for(int x=1;x<=m2;x++){
				if(mj.size()<j){
					mj.push(outside[x]);
					ansj++;
				}else{
					if(mj.front().b<outside[x].a){
						mj.pop();
						mj.push(outside[x]);
						ansj++;
					}
				}
			}
		}
		ans=max(ansj+ansi,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
