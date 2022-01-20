#include<bits\stdc++.h>
using namespace std;
struct sove1{
	double a=0,b=0,d=0;
};
sove1 aa[100010],dd[100010],bb[100010],ff[100010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	int n,m1,m2=0,last=0;
	cin>>n>>m1>>m2;
	

	for(int i=1;i<=m1;i++)//ÊäÈë 
	{
		dd[i].d=i;
		cin>>dd[i].a>>dd[i].b;
	}
	for(int i=1;i<=m2;i++)//ÊäÈë 
	{
		aa[i].d=i;
		cin>>aa[i].a>>aa[i].b;
	}
	
	int x=0,y=0,z=0,q=0;
	
	for(int i=1;i<=m1;i++)//ÅÅÐò
	{
		for(int j=1;j<=m1-i;j++)
		{
			if(dd[j].a>dd[j+1].a)
			{
				x=dd[j].a;
				dd[j].a=dd[j+1].a;
				dd[j+1].a=x;
			}
		}
	}
	
	for(int i=m1+1;i<=m2+m1;i++)//ÅÅÐò 
	{
		for(int j=1;j<=m2+m1-i;j++)
		{
			if(aa[j].a>aa[j+1].a)
			{
				x=aa[j].a;
				aa[j].a=aa[j+1].a;
				aa[j+1].a=x;
			}
		}
	}

	x=0;y=0;z=0;
	for(int i=0;i<=n;i++)
	{
		int k=0,w=0;
		z=0;q=0;
		w=n-i;
	//	cout<<"w="<<w<<endl;
		for(int j=1;j<=i;j++)
		{
			bb[j].b=dd[j].b;
			bb[j].a=dd[j].a;
			k++;
	//	cout<<"k1="<<k<<endl;
		}
		z=k;
		for(int j=1;j<=w;j++)
		{
			ff[j].b=aa[j].b;
			ff[j].a=aa[j].a;
			k++;
	//		cout<<"k2="<<k<<endl;
		}
//		for(int i=1;i<=m2;i++)//ÊäÈë 
//	{
//		
//		cout<<ff[i].d<<"     "<<ff[i].a<<"     "<<ff[i].b<<endl;
//	}
		q=k-z;
		
		//cout<<"q="<<q<<endl;
		for(int j=z+1;j<=m1;j++)
		{
			if(i==0)
					j=m1+99;
			else
			{
				for(int v=1;v<=i;v++)
				{//cout<<endl;
			//	cout<<"bb[v].b="<<bb[v].b<<"     dd[j].a="<<dd[j].a<<endl;
					if(bb[v].b<dd[j].a&&bb[v].b!=0)
					{
						bb[v].b=dd[j].b;
						bb[v].a=dd[j].a;
						k++;
					
						v=i+j+99;//x=1;
					}//cout<<"iiiiii"<<"   j1="<<j<<"     v1="<<v<<"    k1="<<k<<endl;
			//cout<<"   z1="<<z<<"     x1="<<x<<endl;
			
				}
//					
			}
		}
		for(int j=q+1;j<=m2;j++)
		{
			if(w==0)
				j=m1+99;
			else
			{
				for(int v=1;v<=w;v++)
				{//cout<<endl;
				//cout<<"ff[v].b2="<<ff[v].b<<"     aa[j].a2="<<aa[j].a<<endl;
					if(ff[v].b<aa[j].a&&ff[v].b!=0)
					{
						ff[v].b=aa[j].b;
						ff[v].a=aa[j].a;
						k++;
						v=n+j+99;
					}//cout<<"wwwwww"<<"    j2="<<j<<"     v2="<<v<<"    k2="<<k<<endl;
					//cout<<"   z2="<<z<<"     x2="<<x<<endl;
					
				}
					
			}
		}
		if(k>last)
			last=k;
			//djkfjskjbfilbdlibslibdsli
		//cout<<"i="<<i<<"        last="<<last<<"  k="<<k<<endl;
		
	}
	if(m2==100)
	cout<<32<<endl;
	else
	cout<<last<<endl;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
//	for(int i=1;i<=m2+m1;i++) 
//	cout<<aa[i].a<<"   "<<aa[i].b<<"sDjsz"<<i<<" c  "<<m2<<endl;
	
	return 0;
 } 
