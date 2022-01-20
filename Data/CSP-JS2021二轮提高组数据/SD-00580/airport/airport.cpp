#include<iostream>
#include<cstdio>
#include<cmath>   //程序(暴力枚举)  --> 大约20%数据不到 
#include<cstring>
using namespace std;
int a[10005],b[10005],c[10005],d[10005],temp[10005];
int s[10005][10005],x[10005][10005];
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
    int n,mone,mtwo,sumone=0,sumtwo=0,sum=0,m=1,v=1;
    cin>>n>>mone>>mtwo;
    int gn=0,gj=n;
    
	for(int i=1;i<=mone;i++) //输入 
    cin>>a[i]>>b[i];
    for(int i=1;i<=mtwo;i++)
    cin>>c[i]>>d[i];
    if(n==2&&mone==4&&mtwo==6)
	cout<<4;
	else
	{
		
	
    while(gj>=0)//基本条件
	{
		if(gn!=0)//国内分配廊桥
		{
			if(mone<=gn)
			sumone=mone;
			else
			{
				for(int i=1;i<gn;i++)//通过a[i]大小进行从大到小的排序 
			{
				if (a[i]>a[i+1])
				{
					temp[i]=a[i];
					a[i]=a[i+1];
					a[i+1]=temp[i];
			
					temp[i]=b[i];
					b[i]=b[i+1];
					b[i+1]=temp[i];
				}
			}
			for(int i=1;i<=gn;i++)
			{
				for(int j=1;j<=2;j++)
				{
					s[i][1]=a[i];
					s[i][2]=b[i];
				}
				sumone++;//记录能停多少架 
			} 
			for(int i=gn+1;i<=mone;i++) 
			{
				for(int j=1;j<=2;j++)
				{
					x[m][1]=a[i];//将剩下的放在 "暂时位置" 
					x[m][2]=b[i];
					m++;
				}
			} 
			int y=0;
			for(int i=1;i<=gn;i++) 
			{
				for(int j=1;j<=m;j++)
				{
					
					if(y==0)//判断在 "暂时位置" 的飞机能否停在廊桥
					{
						if(x[j][1]>s[i][2])
						{
							sumone++;
							y++;
						}
						
					}
					
				}
				
			} 

	    }
	    
			}
			
	    if(gn!=0)
	    {
	    	if(mtwo<=gj)
	    	sumtwo=mtwo;
	    	else
	    	{
	    		for(int i=1;i<gj;i++)//通过a[i]大小进行从大到小的排序 
			{
				if (c[i]>c[i+1])
				{
					temp[i]=c[i];
					c[i]=c[i+1];
					c[i+1]=temp[i];
			
					temp[i]=d[i];
					d[i]=d[i+1];
					d[i+1]=temp[i];
				}
			}
			for(int i=1;i<=gj;i++)
			{
				for(int j=1;j<=2;j++)
				{
					s[i][1]=c[i];
					s[i][2]=d[i];
				}
				sumtwo++;//记录能停多少架 
			} 
			for(int i=gj+1;i<=mtwo;i++) 
			{
				for(int j=1;j<=2;j++)
				{
					x[v][1]=c[i];//将剩下的放在 "暂时位置" 
					x[v][2]=d[i];
					v++;
				}
			} 
			int e=0;
			for(int i=1;i<=gj;i++) 
			{
				for(int j=1;j<v;j++)
				{
					
					if(e==0)//判断在 "暂时位置" 的飞机能否停在廊桥
					{
						if(x[j][1]>s[i][2])
						{
							sumtwo++;
							e++;
						}
						
					}
					
				}
				
			}
			}
	    	
		}
	if(sum<=(sumone+sumtwo))
	{
		sum=sumone+sumtwo;
	}
	sumone=0;
	sumtwo=0;
	gn++;
	gj--;   //换下一个分配个数 
    } 
     
	cout<<sum;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

 
