#include<cstdio>
int T,n,a[500010],b[500010],flag;
inline int read(){
	register char ch=getchar();int f=1,x=0;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//freopen("data.in","r",stdin);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=(n<<1);++i) a[i]=read();
		for(int i=0;i<(1<<(n<<1));++i){
			int fst=1,lst=(n<<1);flag=0;
			for(int j=(n<<1);j;--j){
				if(i&(1<<(j-1))){
					b[j]=a[lst];
					--lst;
				}
				else{
					b[j]=a[fst];
					++fst;
				}
			}
			for(int j=1;j<=(n<<1);++j){
				if(b[j]!=b[(n<<1)+1-j]) flag=1;
			}
			if(!flag){
				for(int j=(n<<1);j;--j){
					if(i&(1<<(j-1))) printf("R");
					else printf("L");
				}
				break;
			}
		}
		if(flag) printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
