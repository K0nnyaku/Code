//palin
#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[1010],b[1010],vis[1010],c[1010];

int check(int lt,int rt)
{
	
//	cout<<lt<<' '<<rt<<endl;
	int p=0;
	while(p<=n)
	{
		p++;
		if(a[lt+1]==b[p])
		{
			lt++;
			c[n+p]=1;
		}
		else if(a[2*n-rt]==b[p])
		{
			rt++;
			c[n+p]=2;
		}
		else return 0;
	}
	return 1;
}

int dfs(int lt,int rt)
{
//	for(int i=1;i<=2*n;i++) cout<<c[i];cout<<endl;
//			for(int i=1;i<=2*n;i++) cout<<b[i];cout<<endl;
	int flag;
	if(lt+rt==n)
	{
//		return 0 ;
		flag=check(lt,rt);
		if(flag) 
		{
			return 1;
		}
		else return 0;
	}
	if(a[lt+1]<a[2*n-rt])
	{
		if(vis[a[lt+1]]==0&&vis[a[2*n-rt]]==0) 
		{
			vis[a[lt+1]]=1;
			b[lt+rt+1]=a[lt+1];
			c[lt+rt+1]=1;
			flag=dfs(lt+1,rt);
			if(flag==1) {return 1;}
			vis[a[lt+1]]=0;
			b[lt+rt+1]=0;
			c[lt+rt+1]=0;
			vis[a[2*n-rt]]=1;
			b[lt+rt+1]=a[2*n-rt];
			c[lt+rt+1]=2;
			flag=dfs(lt,rt+1);
			if(flag==1) {return 1;} 
			vis[a[2*n-rt]]=0;
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;	
		}
		else if(!vis[a[lt+1]]) 
		{
			vis[a[lt+1]]=1;
			b[lt+rt+1]=a[lt+1];
			c[lt+rt+1]=1;
			flag=dfs(lt+1,rt);
			if(flag==1) {return 1;}
			vis[a[lt+1]]=0;
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;
			
		}
		else if(!vis[a[2*n-rt]]) 
		{
			vis[a[2*n-rt]]=1;
			b[lt+rt+1]=a[2*n-rt];
			c[lt+rt+1]=2;
			flag=dfs(lt,rt+1);
			if(flag==1) {return 1;} 
			vis[a[2*n-rt]]=0;
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;	
		}	
		else return 0;
		
	}
	else if(a[lt+1]>a[2*n-rt])
	{
		if(	vis[a[lt+1]]==0&&vis[2*n-rt]==0) 
		{
			vis[a[2*n-rt]]=1;
			b[lt+rt+1]=a[2*n-rt];
			c[lt+rt+1]=2;
			int flag=dfs(lt,rt+1);
			if(flag==1) {return 1;} 
			vis[a[2*n-rt]]=0;
					c[lt+rt+1]=0;	
			vis[a[lt+1]]=1;
			b[lt+rt+1]=a[lt+1];
			c[lt+rt+1]=1;
			flag=dfs(lt+1,rt);
			if(flag==1) {return 1;}
			vis[a[lt+1]]=0;	
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;
			 
		}
		else if(!vis[a[2*n-rt]]) 
		{
			vis[a[2*n-rt]]=1;
			b[lt+rt+1]=a[2*n-rt];
			c[lt+rt+1]=2;
			flag=dfs(lt,rt+1);
			if(flag==1) {return 1;} 
			vis[a[2*n-rt]]=0;
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;	
		}
		else if(!vis[lt+1]) 
		{
			vis[a[lt+1]]=1;
			b[lt+rt+1]=a[lt+1];
			c[lt+rt+1]=1;
			flag=dfs(lt+1,rt);
			if(flag==1) {return 1;}
			vis[a[lt+1]]=0;	
				b[lt+rt+1]=0;
					c[lt+rt+1]=0;	
		}
		else return 0;
	}
//	else
//	{
//		vis[a[lt+1]]=1;
//			b[lt+rt+1]=a[lt+1];
//			c[lt+rt+1]=1;
//			flag=dfs(lt+1,rt);
//			if(flag==1) {return 1;}
//			vis[a[lt+1]]=0;
//			b[lt+rt+1]=0;
//			c[lt+rt+1]=0;
//			vis[a[2*n-rt]]=1;
//			b[lt+rt+1]=a[2*n-rt];
//			c[lt+rt+1]=2;
//			flag=dfs(lt,rt+1);
//			if(flag==1) {return 1;} 
//			vis[a[2*n-rt]]=0;
//				b[lt+rt+1]=0;
//					c[lt+rt+1]=0;
//	}
	
	
} 

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++) cin>>a[i];
		memset(vis,0,sizeof(vis));
		int flag=dfs(0,0);
		if(flag==1) 
		{
//			for(int i=1;i<=2*n;i++) cout<<c[i];cout<<endl;
			for(int i=1;i<=2*n;i++)
			{
				if(c[i]==1) cout<<'L';
				else cout<<'R'; 
			}
			cout<<endl;
		}
		else cout<<-1<<endl;	
	}
	return 0;
}

