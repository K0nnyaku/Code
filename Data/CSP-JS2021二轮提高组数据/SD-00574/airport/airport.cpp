#include<bits/stdc++.h>
using namespace std;
long long n,m1,m2,ans[5050],b,ans1,s,m;
struct Node{
	long long x,y;
};
Node a1[5020],a2[5020];
bool cmp(Node q,Node p){
	if(q.x ==p.x ) return q.y <p.y;
	return q.x<p.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i].x>>a1[i].y ;
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i].x >>a2[i].y ;
	}
	if(n>=m1+m2){
		cout<<m1+m2<<endl;
		return 0;
	}
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=0;i<=n;i++){
		b++;
		int k=n-i;
		ans[b]+=i;
		s=i;
		m=i+1;
		for(int j=i+1;j<=m1;j++){
			if(i==0)break;
			if(a1[j].x >=a1[m-s].y){
			//	cout<<i<<" "<<j<<" "<<m<<" "<<s<<" "<<m-s<<endl;
				ans[b]++;
				s++;
				m=j;
			}
		}
		ans[b]+=k;
		s=k;
		m=k+1;
		//cout<<endl;
		for(int j=k+1;j<=m2;j++){
			if(k==0)break;
			if(a2[j].x >=a2[m-s].y){
				//cout<<k<<" "<<j<<" "<<m<<" "<<s<<" "<<m-s<<endl;
				ans[b]++;
				s++;
				m++;
			}
		}
		//cout<<ans[b]<<endl;	
	}
	for(int i=1;i<=b;i++){
		ans1=max(ans1,ans[i]);
	}
	cout<<ans1<<endl;
/*	for(int i=1;i<=m1;i++){
		cout<<a1[i].x<<" "<<a1[i].y <<endl;
	}
	cout<<endl;
	for(int i=1;i<=m2;i++){
		cout<<a2[i].x<<" "<<a2[i].y <<endl;
	}*/
	return 0;
}
