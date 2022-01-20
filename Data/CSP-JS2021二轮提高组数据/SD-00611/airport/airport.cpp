#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
inline int read(){
	int x=0,c=getchar();
	while(c>57||c<48)c=getchar();
	while(c<58&&c>47)x=(x<<1)+(x<<3)+c-48,c=getchar();
	return x;
}
struct flight{
	int a,b,fnt,nxt,ed;
}f1[100005],f2[100005];
bool operator<(flight f_1,flight f_2){return f_1.a<f_2.a;}
int n,m1,m2,ans1[100005],ans2[100005],maxx;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)f1[i].a=read(),f1[i].b=read();
	for(int i=1;i<=m2;++i)f2[i].a=read(),f2[i].b=read();
	sort(f1+1,f1+m1+1),sort(f2+1,f2+m2+1);
	for(int i=0;i<=m1;++i)f1[i].fnt=i-1,f1[i].nxt=i+1;
	for(int i=0;i<=m2;++i)f2[i].fnt=i-1,f2[i].nxt=i+1;
	for(int i=1;i<=n;++i){
		ans1[i]=ans1[i-1];
		for(int k=f1[0].nxt,now=0;k<=m1&&f1[m1].a>now;k=f1[k].nxt)
			if(f1[k].a>now)now=f1[k].b,f1[f1[k].fnt].nxt=f1[k].nxt,f1[f1[k].nxt].fnt=f1[k].fnt,f1[k].ed=1,++ans1[i];
		while(f1[m1].ed)--m1;
	}
	for(int i=1;i<=n;++i){
		ans2[i]=ans2[i-1];
		for(int k=f2[0].nxt,now=0;k<=m2&&f2[m2].a>now;k=f2[k].nxt)
			if(f2[k].a>now)now=f2[k].b,f2[f2[k].fnt].nxt=f2[k].nxt,f2[f2[k].nxt].fnt=f2[k].fnt,++ans2[i];
		while(f2[m2].ed)--m2;
	}
	for(int i=0;i<=n;++i)if(ans1[i]+ans2[n-i]>maxx)maxx=ans1[i]+ans2[n-i];
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
