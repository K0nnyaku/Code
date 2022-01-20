#include<bits/stdc++.h>
using namespace std;
int search(int);
int print();
int p,q,sum=0,t,n[500010],l,m,y,z,u,a[1000010],b[1000010];
char c[1000010],d[1000010];
bool s[1000010];
bool ss,sss;
int main()
{freopen("palin.in","r",stdin);
 freopen("palin.out","w",stdout);
 cin>>t;
 for(int i=1;i<=t;i++)
     {sss=false;
      sum=0;
	  cin>>n[i];
	  u=n[i];
      p=1;
      q=2*u;
      for(int j=1;j<=2*u;j++)
      d[j]='R';
      for(int j=1;j<=2*u;j++)
      cin>>a[j];
	  l=2*u;
	  search(1);
     }
	return 0;
 fclose(stdin);
 fclose(stdout);
}
int search(int x)
{for(int i=1;i<=2;i++)
     {if(i==1)
         {for(int j=2*u;j>=1;j--)
          if(s[j]==false)
		     {m=j;
		      b[j]=a[p];
		      s[j]=true;
		      c[x]='L';
		      p++;
		      break;
		     }
		 }
	  else
	     {for(int j=2*u;j>=1;j--)
          if(s[j]==false)
             {m=j;
              b[j]=a[q];
              s[j]=true;
			  c[x]='R';
			  q--;
              break;
		     }
	     }
	if(x==2*u) print();
	else search(x+1);
	s[m]=false;
	p--;
	q++;
    }
}
int print()
{sum++;
 ss=false;
 for(int i=1;i<=u;i++)
     {z=2*u+1-i;
	  if(b[i]!=b[z])
        {ss=true;
         break;
	    }
	 }
 if(ss==false)
    {for(int i=1;i<=2*u;i++)
        {if(c[i]<d[i])
            {for(int j=1;j<=2*u;j++)
                 d[j]=c[j];
            sss=true;
            break;
			}
		}
	}
 if(sum==4*u)
   {if(sss==true)
      {for(int i=1;i<=2*u;i++)
	    cout<<d[i];
  	  }
    else
      cout<<"-1";
   }
}
