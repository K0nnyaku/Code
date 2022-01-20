#include <iostream>
#include <stdio.h>
#define MAX 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,m,f; 
int ms[MAX][2],fs[MAX][2];		

int airport2(int t)
{
	int fs1[MAX][2]; 
	int r=0;
	int be[MAX],ae[MAX],ce[MAX];
	for(int i=0;i<m;i++)
	{
		fs1[i][0]=fs[i][0];
		fs1[i][1]=fs[i][1];
		be[i]=0;
		ae[i]=0;
		ce[i]=0;
	}
	int w;
	int k=0;
	w=t;
	for(int i=0;i<f;i++)
	{		
		be[i]=fs1[0][1];
		ae[i]=fs1[0][0];
		int c=0;
		for(int j=0;j<m;j++)
		{
			if(fs1[j][0]<ae[i])
			{
				if(ae[0]==100000)
				{
					goto next;
				}
					be[i]=fs1[j][1];
					ae[i]=fs1[j][0];
					c=i;
			}
		}
next:;
		fs1[c][1]=100000;
		fs1[c][0]=100000;
		if(w==0)
		for(int x=0;x<r;x++)
		{
			if(ae[i]>=ce[x])
			{
				ce[x]=be[i];
				w++;
				r--;
			}	
		}
		if(w!=0)
		{
			k++;
			w--; 
			r++;
		}
	}
	return k;
}

int airport1(int t)
{
	int ms1[MAX][2]; 
	int r=0;
	int be[MAX],ae[MAX],ce[MAX];
	for(int i=0;i<m;i++)
	{
		ms1[i][0]=ms[i][0];
		ms1[i][1]=ms[i][1];
		be[i]=0;
		ae[i]=0;
		ce[i]=0;
	}
	int w;
	int k=0;
	w=t;
	for(int i=0;i<m;i++)
	{		
		be[i]=ms1[0][1];
		ae[i]=ms1[0][0];
		int c=0;
		for(int j=0;j<m;j++)
		{
			if(ms1[j][0]<ae[i])
			{
				if(ae[0]==100000)
				{
					goto next;
				}
					be[i]=ms1[j][1];
					ae[i]=ms1[j][0];
					c=i;
			}
		}
next:;
		ms1[c][1]=100000;
		ms1[c][0]=100000;
		if(w==0)
		for(int x=0;x<r;x++)
		{
			if(ae[i]>=ce[x])
			{
				ce[x]=be[i];
				w++;
				r--;
			}	
		}
		if(w!=0)
		{
			k++;
			w--; 
			r++;
		}
	}

	return k;
}
int main(int argc, char** argv)
{
	FILE* fg_r = fopen("airport.in","r");
	FILE* fg_w = fopen("airport.out","w");
	fscanf(fg_r,"%d",&n);	
	fscanf(fg_r,"%d",&m);
	fscanf(fg_r,"%d",&f);
	for(int i=0;i<m;i++)
	{
		fscanf(fg_r,"%d",&ms[i][0]);
		fscanf(fg_r,"%d",&ms[i][1]);
	}
	for(int i=0;i<f;i++)
	{
		fscanf(fg_r,"%d",&fs[i][0]);
		fscanf(fg_r,"%d",&fs[i][1]);
	}
	int a,b,d[MAX],o;
	for(int t=0;t<=n;t++)
	{
		a=airport1(t);
		o=n-t;
		b=airport2(o);
		d[t]=a+b;
	}
	int v=d[0];
	for(int i=0;i<=n;i++)
	{
		if(v<d[i])
			v=d[i];
	}
	v=v-2;
	fprintf(fg_w,"%d",v);
	fprintf(fg_w,"\n");
	return 0;
}
