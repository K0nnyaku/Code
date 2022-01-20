#include<bits/stdc++.h>
using namespace std;
char a[501];
int n,k;
int s=0;
int fl,p=0,b,r1=0,r2=0;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++)
	{
	cin>>a[i];	
	if(a[i]=='(')r1++;
	else if(a[i]==')')r2++;
	}
	for(int i=0;i<=n;i++) 
	{
		fl=0;
		if(a[i]=='*')
		p++;
		
		if(a[i]!='*')
		{
		p=0;
		if(a[i]=='(')	
		r1++;
		if(a[i]==')')	
		r2++;	
		}
		if(a[i]=='?')
		{
		for(int j=i;j<=n;j++)
	    {
	 	    if(a[i]!='*')break;
	 	    if(a[i]=='*')p++;
	 	    if(p==k)
	 	    {
	 		    fl=1;
	 		    break;
		    }
	    }
	    
	    if(fl==1)
		{
			if(r1>r2)
			{
			s++;	
		    r2++;		
			}
	        else if(r1<r2)
		    {
		    s++;	
		    r1++;	
		    }
		    else if(r1==r2)
		    s+=2;
	    }
	    else s+=2;
		}
	}
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
