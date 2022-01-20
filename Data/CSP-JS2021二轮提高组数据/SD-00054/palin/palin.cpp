#include<bits/stdc++.h>
#define Nope printf("-1")
#define Ent printf("\n")
using namespace std;
typedef long long ll;
const int range=1e6+6;
inline int read()
{
	int x=0; int f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int T,n,a[range],b[range],pl[range],pr[range],num,len;
char op[range];
bool ovo(int l,int r)
{
	int i,j;
	if(pr[l]=r)
	{
		if(r-l>1)
		{
			op[num]='L'; op[r+1-num]='L';
			num++; len+=2;
			return ovo(l+1,r-1);
		}
		if(r-l==1)
		return true;
	}
	else
	{
		op[num]='L'; op[r+1-num]='R';
		return qwq(l+1,pr[a[i]]-1,pr[a[i]]+1,r);
	}
}
bool qwq(int l1,int r1,int l2,int r2)
{
	int i,j;
	if(pr[l1]<=r1)
	{
		op[num]='L'; op[r2]='R';
	}
	return qwq(a[i],pr[a[i]]-1);
		
	
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i,j;
	T=read();
	while(T--)
	{
		num=1; len=0;
		n=read(); n=(n<<1); 
		memset(a,0,sizeof(a));
		memset(pl,0,sizeof(pl));
		memset(pr,0,sizeof(pr));
		for(i=1;i<=n;i++)
		{
			a[i]=read();
			if(!pl[a[i]]) pl[a[i]]=i;
			else pr[a[i]]=i;
		}
		if(!ovo(1,n))
		Nope;
		else
		{
			for(i=1;i<=n;i++)
			printf("%d",op[i]);
			Ent;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

