#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct node
{
	int data;
}a[200005];

struct node2
{
	int sdata;
	int shere_is; 
}b[200005];

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].data;
	}
	

		
	
	while(m--)
	{
		int flag,x,y;
		cin>>flag;
		if(flag==1)
		{
			
			cin>>x>>y;
			a[x].data=y;
			
			
		    
		}
		else if(flag==2)
		{
			cin>>x;
			
			for(int i=1;i<=n;i++)
			{
				b[i].sdata=a[i].data;
				b[i].shere_is=i;
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = i; j>=2; j--)
				{
					if ( b[j].sdata < b[j-1].sdata )
					{
						int t1 = b[j-1].sdata;
						b[j-1].sdata = b[j].sdata;
						b[j].sdata = t1;
						
						int t2 = b[j-1].shere_is;
						b[j-1].shere_is = b[j].shere_is;
						b[j].shere_is = t2;
				 	}
			   }
	       }
	       for(int i=1;i<=n;i++)
			{
				if(x==b[i].shere_is)
				    cout<<i<<endl;
				    
			}
			
		}
	} 
    
	fclose(stdin);
	fclose(stdout);
   return 0;}
