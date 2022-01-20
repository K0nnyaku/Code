#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
ifstream fin;
ofstream fout;

int pi[100005][2],p_l[100005],w[100005],ans[100005][2],n,b,c,t;
int bi(int a_l,int b_l)
{
	return(pi[a_l][0]<pi[b_l][0]);
}
int fff(bool f)
{
	if(f)
	{
	    fin.open("airport.in");
	    fout.open("airport.out");
	}
	else
	{
	    fin.close();
        fout.close();
	}
	return 0;
}

int p_cin()
{
	fin>>n>>b>>c;  
	for(int i=1;i<=b;i++)
	{
		fin>>pi[i][0]>>pi[i][1];
	}
	for(int i=1;i<=b+c;i++)  p_l[i]=i;
	sort(p_l+1,p_l+b,bi);
	for(int i=b+1;i<=b+c;i++)
	{
		fin>>pi[i][0]>>pi[i][1];
	}
	sort(p_l+b+1,p_l+b+c+1,bi);
	for(int i=1;i<=n;i++)  w[i]=-1;
	for(int i=1;i<=b;i++)
	{
		for(int f=1;f<=n;f++)
		{
			if(pi[p_l[i]][0]>w[f])
			{
				w[f]=pi[p_l[i]][1];
				ans[f][0]++;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)  w[i]=-1;
	for(int i=b+1;i<=b+c;i++)
	{
		for(int f=1;f<=n;f++)
		{
			if(pi[p_l[i]][0]>w[f])
			{
				w[f]=pi[p_l[i]][1];
				ans[f][1]++;
				break;
			}
		}
	}
	return 0;
}

int ans_gettt()
{
	int an=0;
	for(int i=1;i<=n;i++)
	{
		an+=ans[i][0];
		ans[i][0]=an;
	}
	an=0;
	for(int i=1;i<=n;i++)
	{
		an+=ans[i][1];
		ans[i][1]=an;
	}
	int ll=0,ln=0;
	an=0;
	for(int i=0;i<=n;i++)
	{
		ll=i;
		ln=n-i;
		if(ans[ll][0]+ans[ln][1]>an)  an=ans[ll][0]+ans[ln][1];
	}
	return an;
}
int main()
{
	fff(1);
    p_cin();
    fout<<ans_gettt()<<endl;
    fff(0);
    return 0;
}


