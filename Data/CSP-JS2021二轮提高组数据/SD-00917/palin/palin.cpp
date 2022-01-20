#include<bits/stdc++.h>
using namespace std;
int read()
{
	int o=0,e=1;
	char z;
	z=getchar();
	while(z<'0'||z>'9') {if(z=='-') e=-1;z=getchar();}
	while(z>='0'&&z<='9') {o=(o<<1)+(o<<3)+z-'0';z=getchar();}
	return o*e;
}
const int N=500010;
int T,n;
int shu[2*N];
int lie[2*N];
int fst[2*N];
int xz[2*N];
bool bol=false;
void search(int l,int r,int cnt)
{
	if(cnt==2*n+1)
	{
		bol=true;
		for(int i=1;i<=cnt-1;i++)
		{
			if(xz[i]==0) printf("L");
			if(xz[i]==1) printf("R");
		}
		printf("\n");
	}
	if(fst[shu[l]]==0)
	{
		fst[shu[l]]=cnt;
		lie[cnt]=shu[l];
		xz[cnt]=0;
		search(l+1,r,cnt+1);
		if(bol) return;
	}
	else
		if(fst[shu[l]]+cnt==2*n+1)
		{
			xz[cnt]=0,lie[cnt]=shu[l],search(l+1,r,cnt+1);
			if(bol) return;
		}
	
	lie[cnt]=0;
	if(fst[shu[l]]==cnt)
		fst[shu[l]]=0;
	
	if(fst[shu[r]]==0)
	{
		fst[shu[r]]=cnt;
		lie[cnt]=shu[r];
		xz[cnt]=1;
		search(l,r-1,cnt+1);
		if(bol) return;
	}
	else
		if(fst[shu[r]]+cnt==2*n+1)
		{
			xz[cnt]=1,lie[cnt]=shu[r],search(l,r-1,cnt+1);
			if(bol) return;
		}
			
	lie[cnt]=0;
	if(fst[shu[r]]==cnt)
		fst[shu[r]]=0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	
	T=read();
	while(T--)
	{
		n=read();
		bol=false;
		memset(fst,0,sizeof(fst));
		memset(lie,0,sizeof(lie));
		memset(xz,0,sizeof(xz));
		for(int i=1;i<=2*n;i++) shu[i]=read();
		search(1,2*n,1);
		if(!bol) printf("-1\n");
	}
	
	return 0;
}
