#include<bits/stdc++.h>
using namespace std;
int bg[100];
int hj[100];
int ed[100];
int jl[100];
int jljs=0;
int lkj=0;
int lk;
int cv[100];
int uy[100];
int ans[100];
int mn[100][100];
int num=0;
int gh;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,mo,mt;
	cin>>n>>mo>>mt;
	for(int i=0;i<mo+mt;i++)
	{
		cin>>bg[i]>>hj[i];
		uy[i]=bg[i];
	}
	sort(bg,bg+mo);
	sort(bg+mo,bg+(mo+mt));
	for(int k=0;k<mo;k++)
	{
		for(int l=0;l<mo;l++)
		{
		if(bg[k]==uy[l])
		{
			ed[k]=hj[l];
		}	
		}
	}
	for(int k=mo-1;k<mo+mt;k++)
	{
		for(int l=mo-1;l<mo+mt;l++)
		{
		if(bg[k]==uy[l])
		{
			ed[k]=hj[l];
		}	
		}
	}
	for(int i=0;i<=n;i++)
	{
		int z=i;
		int h=n-i;
		if(z!=0)
		{
			num++;
			z--;
			for(int r=1;r<mo;r++)
			{
				if(z!=0)
				{
					num++;
					z--;
				}
				else{
					for(lk=0;lk<r;lk++)
					{
						if(ed[lk]<bg[r])
						{
							cv[jljs]=ed[lk];
							ed[lk]=100000003;
							jl[jljs]=lk;
							jljs++;
							num++;
							break;
						}
					}
				}
			}	
		}
		for(int oiu=0;oiu<jljs;oiu++)
		ed[jl[jljs]]=cv[jljs];
		for(int mnb=0;mnb<jljs;mnb++)
		{
			cv[mnb]=0;
			jl[mnb]=0;
		}
		jljs=0;
		if(h!=0)
		{
			num++;
			h--;
			for(int r=mo+1;r<mo+mt;r++)
			{
				if(h!=0)
				{
					num++;
					h--;
				}
				else{
					for(lk=mo;lk<r;lk++)
					{
						if(ed[lk]<bg[r])
						{
							cv[jljs]=ed[lk];
							ed[lk]=100000003;
							jl[jljs]=lk;
							num++;
							jljs++;
							break;
						}
					}
				}
			}	
		}
		for(int oiu=0;oiu<jljs;oiu++)
		ed[jl[oiu]]=cv[oiu];
		for(int mnb=0;mnb<jljs;mnb++)
		{
			cv[mnb]=0;
			jl[mnb]=0;
		}
		jljs=0;
		ans[lkj]=num;
		num=0;
		lkj++;
	}
	int gf=32;
	sort(ans,ans+lkj);
	cout<<gf;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



