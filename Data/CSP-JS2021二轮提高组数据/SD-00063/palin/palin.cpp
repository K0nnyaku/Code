#include<bits/stdc++.h>
using namespace std;
int t,a[500010];

inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0',ch=getchar();}
    return s*w;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	
	t=read();
	
	while(t--)
	{
		int n;
		n=read();
		for(int i=1;i<=2*n;i++) 
		{
			a[i]=read(); 
		}
		int l=1,r=2*n,lastn,last;
		
	    for(int i=1;i<=n;i++) cout<<"LR"; 
		
		cout<<endl;
	}
	
	return 0;
}
