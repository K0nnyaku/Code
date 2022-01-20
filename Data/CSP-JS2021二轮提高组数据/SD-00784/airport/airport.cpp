#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
long long n,m1,m2;
struct qwe{
	long long a,b;
}a1a[100100],a2a[100100];
bool Cmp(qwe a,qwe b){
	return a.a<b.a;
}
long long ans=-1;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)a1a[i].a=read(),a1a[i].b=read();
	for(int i=1;i<=m2;i++)a2a[i].a=read(),a2a[i].b=read();
	
	sort(a1a+1,a1a+1+m1,Cmp);
	sort(a2a+1,a2a+1+m2,Cmp);
	if(m1+m2<=n){
		printf("%lld",m1+m2);
		goto NSSB;
	}
	for(int i=n-m2>=0? n-m2:0;i<=n&&i<=m1;i++){
		int j=n-i;
		long long WSND=0;
		if(i!=0){
			WSND++;
			int qwe[100100],R;
			memset(qwe,0,sizeof(qwe));
			qwe[1]=a1a[1].b;
			for(int k=2;k<=m1;k++){
				R=-1;
				for(int l=1;l<=i;l++)if(qwe[l]<a1a[k].a){qwe[l]=0,R=l;break;}
				if(R!=-1){
					qwe[R]=a1a[k].b;
					WSND++;
				}
			}
		}
		if(j!=0){
			WSND++;
			int qwe[100100],R;
			memset(qwe,0,sizeof(qwe));
			qwe[1]=a2a[1].b;
			for(int k=2;k<=m2;k++){
				R=-1;
				for(int l=1;l<=j;l++)if(qwe[l]<a2a[k].a){qwe[l]=0;R=l;break;}
				if(R!=-1){
					qwe[R]=a2a[k].b;
					WSND++;
				}
			}
		}
		if(WSND>ans)ans=WSND;
	}
	printf("%lld\n",ans);
	NSSB:;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
