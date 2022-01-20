#include<cstdio>
#include<iostream>
int T,n,a[1000005],c[500005],j[1000005],temp=0;
char ans[1000005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)scanf("%d",&a[i]),j[i]=1;
		for(int i=1;i<=n;++i)c[i]=0;
		while(temp<n){
			for(int i=1;i<=n*2;i+=j[i]){
				if(c[a[i]]^0&&i-c[a[i]]==n){
					int b[n],t=0;
					for(int k=c[a[i]];k<=i;k+=j[k]){
						if(b[a[k]]^114514)b[a[k]]=1114514;
						else t=1;
					}
					if(!t){
						ans[n-temp]='L',ans[n+temp+1]='R',++temp;
						j[c[a[i]]]+=j[c[a[i]]]+1,j[i]=j[i]+1;
					}
				}
				if(a[i]==a[i-1]){
					ans[n-temp]='L',ans[n+temp+1]='R',++temp;
					j[i-2]=j[i]+2;
				}
				if(!c[a[i]])c[a[i]]=i;
			}
			int t=0;
			for(int i=1;i<=2*n;i++)if(j[i]^1)t=1;
			if(!t){printf("-1\n");break;}
		}
		if(temp==n)for(int i=1;i<=n*2;++i)printf("%c",ans[i]);
	}
	return 0;
}
