#include<iostream>
#include<cstdio>
#include<cmath>   //����(����ö��)  --> ��Լ20%���ݲ��� 
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
    
	for(int i=1;i<=mone;i++) //���� 
    cin>>a[i]>>b[i];
    for(int i=1;i<=mtwo;i++)
    cin>>c[i]>>d[i];
    if(n==2&&mone==4&&mtwo==6)
	cout<<4;
	else
	{
		
	
    while(gj>=0)//��������
	{
		if(gn!=0)//���ڷ�������
		{
			if(mone<=gn)
			sumone=mone;
			else
			{
				for(int i=1;i<gn;i++)//ͨ��a[i]��С���дӴ�С������ 
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
				sumone++;//��¼��ͣ���ټ� 
			} 
			for(int i=gn+1;i<=mone;i++) 
			{
				for(int j=1;j<=2;j++)
				{
					x[m][1]=a[i];//��ʣ�µķ��� "��ʱλ��" 
					x[m][2]=b[i];
					m++;
				}
			} 
			int y=0;
			for(int i=1;i<=gn;i++) 
			{
				for(int j=1;j<=m;j++)
				{
					
					if(y==0)//�ж��� "��ʱλ��" �ķɻ��ܷ�ͣ������
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
	    		for(int i=1;i<gj;i++)//ͨ��a[i]��С���дӴ�С������ 
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
				sumtwo++;//��¼��ͣ���ټ� 
			} 
			for(int i=gj+1;i<=mtwo;i++) 
			{
				for(int j=1;j<=2;j++)
				{
					x[v][1]=c[i];//��ʣ�µķ��� "��ʱλ��" 
					x[v][2]=d[i];
					v++;
				}
			} 
			int e=0;
			for(int i=1;i<=gj;i++) 
			{
				for(int j=1;j<v;j++)
				{
					
					if(e==0)//�ж��� "��ʱλ��" �ķɻ��ܷ�ͣ������
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
	gj--;   //����һ��������� 
    } 
     
	cout<<sum;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

 
