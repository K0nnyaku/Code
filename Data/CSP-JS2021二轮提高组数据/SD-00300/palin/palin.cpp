#include<bits/stdc++.h>
using namespace std;
int n;
struct unit{
	int x,y;
	bool operator < (const unit a)const{
		return x>a.x||x==a.x&&y>a.y;
	}
}m[10000];
void init(){
	freopen("int.in","r",stdin);
	freopen("int.out","w",stdout);
	cin>>n;	
	for(register int i=1;i<=n;i++){
		cin>>m[i].x>>m[i].y;
	}
	sort(m+1,m+1+n);
	for(register int i=1;i<=n;i++){
		cout<<m[i].x<<' '<<m[i].y<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
int main(){
	init();
	return 0;
} 
