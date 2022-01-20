#include<cstdio>

using namespace std;

const int N=1000005; 
int a[N],b[N],n,al,ar,bl,sd[N];
bool c[N];

inline int read(){
	int a=0,f=1;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){a=a*10+s-'0';s=getchar();}
	return a*f;
}
bool hw(){
	int l=0,r=n-1;
	while(l<r){
		if(b[l]!=b[r])return false;
		l++;r--;
	}
	return true;
}
bool dfs(){
	if(bl==n)return hw();
	if(sd[a[al]]==0||sd[a[al]]==bl){
		bool gs;
		if(sd[a[al]]==0)sd[a[al]]=n-bl-1;
		c[bl]=0;
		b[bl++]=a[al++];
		gs=dfs();
		b[bl]=0;
		bl--;al--;sd[a[al]]=0;
		if(gs)return true;
	}
	if(sd[a[ar]]==0||sd[a[ar]]==bl){
		bool gs;
		if(sd[a[ar]]==0)sd[a[ar]]=n-bl-1;
		c[bl]=1;
		b[bl++]=a[ar--];
		gs=dfs();
		b[bl]=0;
		bl--;ar++;sd[a[ar]]=0;
		if(gs)return true;
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=read();
	while(t--){
		n=read();n<<=1;
		al=0;ar=n-1;bl=0;
		for(int i=0;i<n;i++)a[i]=read();
		if(dfs()){
			for(int i=0;i<n;i++)
				putchar(c[i]?'R':'L');
			putchar('\n');
		}
		else printf("-1\n");
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}

