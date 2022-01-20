#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct airp{
	int a,b;
}p1[100005],p2[100005];
int n,m1,m2,f1[100005],f2[100005],s1[100005],s2[100005],c1,c2,ans;
bool cmd(airp x,airp y){return x.a<y.a;}
void read(int &x){
	int f=1;char c=getchar();x=0;
	while(c<'0'||c>'9'){
		if (c=='-')f=-f;
		c=getchar(); 
	}
	while (c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}x*=f;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for (int i=1;i<=m1;i++){
		read(p1[i].a);
		read(p1[i].b);
		f1[i]=0;
	}sort(p1+1,p1+m1+1,cmd);f1[0]=0;
	for (int i=1;i<=m2;i++){
		read(p2[i].a);
		read(p2[i].b);
		f2[i]=0;
	}sort(p2+1,p2+m2+1,cmd);f2[0]=0;
	c1=0;c2=0;
	for (int i=1;i<=n;i++){
		int u=0;
		if (c1<m1)for (int j=1;j<=m1;j++){
			if (f1[j]==0&&p1[j].a>u){
				u=p1[j].b;
				f1[j]=1;
				c1++;
			}
		}s1[i]=c1;u=0;
		if (c2<m2)for (int j=1;j<=m2;j++){
			if (f2[j]==0&&p2[j].a>u){
				u=p2[j].b;
				f2[j]=1;
				c2++;
			}
		}s2[i]=c2;
	}s1[0]=0;s2[0]=0;ans=0;
	for (int i=0;i<=n;i++)ans=max(ans,s1[i]+s2[n-i]);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
