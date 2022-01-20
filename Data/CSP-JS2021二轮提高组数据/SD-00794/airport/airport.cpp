#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MAXN = 100010;

int n,fm,sm,Max;
pii aj[MAXN],bj[MAXN],ac[MAXN],bc[MAXN];
bool flag[MAXN];

int main(void)
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&fm,&sm);
	for(int i=1;i<=fm;i++)
		scanf("%d%d",&aj[i].first,&ac[i].first),aj[i].second=i,ac[i].second=i;
	sort(aj+1,aj+1+fm);
	sort(ac+1,ac+1+fm);
	for(int i=1;i<=sm;i++)
		scanf("%d%d",&bj[i].first,&bc[i].first),bj[i].second=i,bc[i].second=i;
	sort(bj+1,bj+1+sm);
	sort(bc+1,bc+1+sm);
	for(int nei=0;nei<=n;nei++)
	{
		int wai=n-nei, ans=0, curn=0, chu=1;
		//cout << "ÄÚ£º" << endl;
		
		//memset(flag,0,sizeof(flag));
		for(int ru=1;ru<=fm;ru++)
		{
			while(aj[ru].first>ac[chu].first&&chu<=ru)
			{
				if(flag[ac[chu].second])	curn--,flag[ac[chu].second]=0;
				chu ++;
			}
			if(aj[ru].first<ac[chu].first&&curn<nei)
				curn++,ans++,flag[aj[ru].second]=1;
		}
		//cout << ans<< ' ';
		while(chu<=fm)
		{
			flag[ac[chu].second]=0;
			chu ++;	
		}
		//memset(flag,0,sizeof(flag));
		chu=1,curn=0;
		for(int ru=1;ru<=sm;ru++)
		{
			while(bj[ru].first>bc[chu].first&&chu<=ru)
			{
				if(flag[bc[chu].second])	curn--,flag[bc[chu].second]=0;
				chu ++;
			}
			if(bj[ru].first<bc[chu].first&&curn<wai)
				curn++,ans++,flag[bj[ru].second]=1;
		}
		while(chu<=fm)
		{
			flag[bc[chu].second]=0;
			chu ++;	
		}
		//cout << ans << endl;
		Max = max(Max,ans);
	}
	cout << Max << endl;
	return 0; 
}







