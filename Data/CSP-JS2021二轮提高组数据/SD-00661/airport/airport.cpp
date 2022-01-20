#include<cstdio>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;
int n,m1,m2;//廊桥,内,国际
int ans[N];

struct in_china{
	int dao,li;
	bool zhanyong;
}a[N];
struct out_china{
	int dao,li;
	bool zhanyong;
}b[N];
inline bool cmp1(in_china a,in_china b){
	return a.dao<b.dao;
}
inline bool cmp2(out_china a,out_china b){
	return a.dao<b.dao;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	} 
	return x*f;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=m1;++i){
		a[i].dao=read(),a[i].li=read();
	}
	for(int i=1;i<=m2;++i){
		b[i].dao=read(),b[i].li=read();
	}
	sort(a+1,a+1+m1,cmp1);
	sort(b+1,b+1+m2,cmp2);
	int s=0;
	for(int i=1;i<=n;++i){
		int inc=i;//分给国内数量 
		int outc=n-i;//分给国际数量 
		s++;
		for(int j=1;j<=m1;++j){
			if(inc>0){
				inc--;
				ans[s]++;
				a[i].zhanyong=true;
			}
			for(int k=1;k<=j;++k){
				if(a[j].dao>a[k].li && a[k].zhanyong==true){
					inc++;
					a[k].zhanyong=false;
				}
			}
		}
		for(int j=1;j<+m2;++j){
			if(outc>0){
				outc--;
				ans[s]++;
				b[i].zhanyong=true;
			}
			for(int k=1;k<=j;++k){
				if(b[j].dao>b[k].li && b[k].zhanyong==true){
					outc++;
					b[k].zhanyong=false;
				}
			}
		}
	}
	sort(ans+1,ans+1+n);
	printf("%d",ans[n]);
	/*for(int i=1;i<=m1;++i){
		cout<<a[i].dao<<" "<<a[i].li<<endl;
	}
	for(int j=1;j<=m2;++j){
		cout<<b[j].dao<<" "<<b[j].li<<endl;
	}*/
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
