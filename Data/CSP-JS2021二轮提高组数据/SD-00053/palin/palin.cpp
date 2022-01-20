#include <cstdio>
#include <algorithm>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=1e6+7,INF=1e9+7,Mod=998244353;
int T,n,a[N],pl[N],pr[N],fr[N],se[N],ans[N]; 

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n*2;i++)pl[i]=pr[i]=fr[i]=se[i]=ans[i]=0;
		for(int i=1;i<=n*2;i++){
			a[i]=read();
			if(fr[a[i]])pl[i]=fr[a[i]],pr[fr[a[i]]]=i,se[a[i]]=i;
			else fr[a[i]]=i;
		}
		n*=2;
		ans[1]=1,ans[pr[1]]=n;
		int L1=2,R1=pr[1]-1,L2=pr[1]+1,R2=n,k=2,tag=1;
		while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
		while(L2<R2&&a[L2]==a[R2])ans[L2]=n-k+1,ans[R2]=k,++L2,--R2,++k;
		for(int i=L2;i<=R2;){
			while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
			while(i<R2&&a[i]==a[R2])ans[i]=n-k+1,ans[R2]=k,++i,--R2,++k;
			if(i>R2)break;
			if(L1<=L2&&pl[i]==L1)ans[L1]=k,ans[i]=n-k+1,++L1,++k,++i;
			else if(L1<=R1&&pr[R1]==R2)ans[R1]=n-k+1,ans[R2]=k,--R1,--R2,++k;
			else{tag=0;break;}
		}
		while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
		for(int i=1;i<=n;i++)if(ans[i]==0)tag=0;
		int L=1,R=n;
		
		
		if(tag==0){
			for(int i=1;i<=n;i++)ans[i]=0;
			ans[pl[n]]=n,ans[n]=1;
			L1=1,R1=pl[n]-1,L2=pl[n]+1,R2=n-1,k=2,tag=1;
			while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
			while(L2<R2&&a[L2]==a[R2])ans[L2]=n-k+1,ans[R2]=k,++L2,--R2,++k;
			for(int i=L2;i<=R2;){
				while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
				while(i<R2&&a[i]==a[R2])ans[i]=n-k+1,ans[R2]=k,++i,--R2,++k;
				if(i>R2)break;
				if(L1<=L2&&pl[i]==L1)ans[L1]=k,ans[i]=n-k+1,++L1,++k,++i;
				else if(L1<=R1&&pr[R1]==R2)ans[R1]=n-k+1,ans[R2]=k,--R1,--R2,++k;
				else{tag=0;break;}
			}
			while(L1<R1&&a[L1]==a[R1])ans[L1]=k,ans[R1]=n-k+1,++L1,--R1,++k;
			for(int i=1;i<=n;i++)if(ans[i]==0)tag=0;
			if(tag==0){
				printf("-1\n");
				continue;
			}
		}
		while(L<=R){
			if(ans[L]<=ans[R])printf("L"),++L;
			else printf("R"),--R;
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
