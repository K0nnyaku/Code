#include<bits/stdc++.h>
using namespace std;
int b,l,r,n,m1,m2,ans=0;
int a1[1000000],a2[1000000];
map<int,int>p1,p2;
int sol(int w){
	int an=0;
	int z1,z2;
	priority_queue<int> q1,q2;
	q1.push(-1000000000);
	q2.push(-1000000000);
	z1=w;z2=n-w;
	for(int i=1;i<=m1;i++){
		while(-q1.top()<=a1[i]){
			z1++;
			q1.pop();
		}
		if(z1>0){
			an++;
			z1--;
			//printf("(%d,%d)KE\n",a1[i],p1[a1[i]]);
			q1.push(-p1[a1[i]]);
		}
	}
	//cout<<an<<"jia ";
	for(int i=1;i<=m2;i++){
		while(-q2.top()<=a2[i]){
			z2++;
			q2.pop();
		}
		if(z2>0){
			an++;
			z2--;
			q2.push(-p2[a2[i]]);
		}
	}
	//cout<<an<<"jia "<<endl;
	return an;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
	cin>>a1[i]>>b;
	p1[a1[i]]=b;	
	}
	for(int i=1;i<=m2;i++){
	cin>>a2[i]>>b;
	p2[a2[i]]=b;	
	}
	sort(a1+1,a1+m1+1);
	sort(a2+1,a2+m2+1);
	for(int i=0;i<=n;i++){
		ans=max(ans,sol(i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

