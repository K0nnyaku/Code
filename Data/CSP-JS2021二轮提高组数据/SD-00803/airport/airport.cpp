#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long n,a,b;
long long s;
struct alo
{
	int x,y;
};
alo ra[100005],rb[100005];
bool ab(alo y,alo u)
{
	return y.x<u.x;
}
long long ta,tb,m;
long long i,j,rt;
void qwe()
{  rt++;
i=0;j=0;
	 if(ta==0)
	 while(j<a)
  {  
  	if(ra[j++].x>ra[i].y&&ra[i].y!=-1)
  	{   i=j-1;
  	ra[i].y=-1;
  		ta++;
	  }
  } i=0;j=0;
   if(tb==0)
   while(j<b)
  {  
  	if(rb[j++].x>rb[i].y&&rb[i].y!=-1)
  	{   i=j-1;
  	    rb[i].y=-1;
  		tb++;
	  }
  }
  if(ta>=tb)
  {
  	m+=ta+1;
  	n--;
  	ta=0;
   } 
   else 
   {
   	m+=tb+1;
   	n--;
   	tb=0;
   }
   if(n>0) qwe();
}
int main()
{  freopen("airport.in","r",stdin);
   freopen("airport.out","w",stdout);

  cin>>n>>a>>b;
  for(int i=0;i<a;i++)
  cin>>ra[i].x>>ra[i].y;
  for(int i=0;i<b;i++)
  cin>>rb[i].x>>rb[i].y;
  sort(ra,ra+a,ab);
  sort(rb,rb+b,ab);
qwe();
  cout<<m;
  fclose(stdin);
  fclose(stdout);
  return 0;	
}
