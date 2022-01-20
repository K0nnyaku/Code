#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long a[1000005],b[1000005];
char s[1000005],d[1000005],e[1000005],f[1000005];
long long w,n,t;
int search(int x,int y,int z)
{
      
	  if(x<=y)
	  { d[z]='L';
	  e[t-z]=a[x]+48;
	  f[z]=a[x]+48;
	  b[z++]=a[x];
	  x++;
	  if((z>w&&e[z-1]==f[z-1])||(z<=w)) search(x,y,z);
      }
      x--;z--;
	  if(x<y)
	  {  d[z]='R';
	   e[t-z]=a[y]+48;
	   f[z]=a[y]+48;
	    b[z++]=a[y];
	    y--;
	    if((z>w&&e[z-1]==f[z-1])||(z<=w)) search(x,y,z);
    
      }
      if(z==t)
      { 
      	if(strcmp(e,f)==0)
      	{
      	  if(strcmp(s,d)>0) strcpy(s,d);	
		}
	}
}
int main()
{   freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{ s[0]='Z';
	cin>>w;
	for(long long i=0;i<2*w;i++)
	 {
	cin>>a[i]; 
	 } 
	t=2*w-1;
	search(0,t,0);
    if(s[0]!='Z') cout<<s<<endl;
	 else cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
