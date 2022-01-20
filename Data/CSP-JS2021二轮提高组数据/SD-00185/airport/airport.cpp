#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
bool f1[5000],f2[5000];
int search(int,int);
int n,m1,m2;//桥廊，国内，国际；
struct node{
  long long	re;
  long long	le;
};node a[5000],b[5000];
int ans;
bool px(node x,node y)
{ return x.re<y.re;}	
int main()
{  freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);
   int max1=-1000;
   cin>>n>>m1>>m2;
   for(int i=1;i<=m1;i++)
   cin>>a[i].re>>a[i].le;
   for(int i=1;i<=m2;i++)
   cin>>b[i].re>>b[i].le;
   sort(a+1,a+1+m1,px);
   sort(b+1,b+1+m2,px);
   for(int i=0;i<=n;i++)
   { int v=search(i,n-i);
	 if(v>max1) max1=v;
   }
   cout<<max1;   
   fclose(stdin);
   fclose(stdout);	
	return 0;
} 
int search(int x,int y)//内，外； 
{   int time1[5000],time2[5000];
    int xx1=0,xx2=0;
    int e=0,r=0;
    bool flag;
	if(x>0)
    {for(int i=1;i<=m1;i++)
     { flag=false; 
	  if(r>=x)
       { for(int j=1;j<=x;j++)
         { if(time1[j]<=a[i].re)
           { r--;flag=true;
           }
         }
       	
       }
	   time1[++r]=a[i].le;
	   if(r<=x||(flag==true)) xx1++;
	   	
     }
    }
    r=0;
    e=y;
    flag=false;
    if(y>0)
    { for(int i=1;i<=m2;i++)
      { flag=false;
	    if(r>=y)
        { for(int j=1;j<=y;j++)
          { if(time2[j]<=b[i].re)
            { r--;flag=true; }            	                     	 
          }
        }
			
		time2[++r]=b[i].le;	
		if(r<=y||(flag==true)) xx2++;
		
      }
     } 	
    
    
   return xx1+xx2;
	
	
	
} 
