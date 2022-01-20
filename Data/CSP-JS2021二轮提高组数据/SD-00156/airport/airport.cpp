#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define int long long
using namespace std;
inline bool isdigit(char x){return x>='0'&&x<='9';}
inline int read(){
	char x=getchar();int fl=1,ans=0;
	while(!isdigit(x)){if(x=='-')fl=-1;x=getchar();}
	while(isdigit(x)){ans=(ans<<3)+(ans<<1)+(int)(x-'0');x=getchar();}
	return fl*ans;
}
char inf[]="airport.in",ouf[]="airport.out";
int n,m1,m2,maxans=-1;
inline int gmax(int x,int y){
	return x>y?x:y;
}
struct plane{
	int arrive,department;
	void init(){
		arrive=read();
		department=read();
	}
	bool operator<(plane ano)const{return arrive<ano.arrive;}
}a[N],b[N];
signed main(){
	freopen(inf,"r",stdin);
	freopen(ouf,"w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)a[i].init();
	for(int i=1;i<=m2;i++)b[i].init();
	sort(a+1,a+1+m1);sort(b+1,b+1+m2);
	for(int inter=0,gross=n;inter<=n;inter++,gross--){
		priority_queue<int,vector<int>,greater<int> > leaving;
		int ans=0,ggross=gross,iinter=inter;
		if(gross!=0)
			for(int i=1;i<=m1;i++){
				if(gross>0)leaving.push(a[i].department),ans++,gross--;
				else{
					if(leaving.top()>a[i].arrive)continue;
					else{
						if(leaving.top()<a[i].arrive)leaving.pop();
						leaving.push(a[i].department);
						ans++;
					}
				}
			}
		gross=ggross;
		priority_queue<int,vector<int>,greater<int> > departing;
		if(inter!=0)
			for(int i=1;i<=m2;i++){
				if(inter>0)departing.push(b[i].department),ans++,inter--;
				else{
					if(departing.top()>b[i].arrive)continue;
					else{
						if(departing.top()<b[i].arrive)departing.pop();
						departing.push(b[i].department);
						ans++;
					}
				}
			}
		inter=iinter;
		maxans=gmax(ans,maxans);
	}
	printf("%lld",maxans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//IDK 40pts
