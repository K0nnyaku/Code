#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
const int inf_int = 0x7fffffff;
typedef long long ll;
#define maxn 300009
struct node{
	int s,t;
}a1[maxn],a2[maxn];
int n,m1,m2;
int l1[maxn],l2[maxn];
int sum1[maxn],sum2[maxn];
int bel1[maxn],bel2[maxn];
int pid[maxn];
int val[maxn*3],cnt=0;
int cmp(node a,node b)
{
	return a.s<b.s;
}
void Init()
{
	for(int i=1;i<=m1;i++)val[++cnt]=a1[i].s,val[++cnt]=a1[i].t;
	for(int i=1;i<=m2;i++)val[++cnt]=a2[i].s,val[++cnt]=a2[i].t;
	sort(val+1,val+1+cnt);
	int last=0;map<int,int> mp;
	for(int i=1;i<=cnt;i++)
	{
		if(val[i]==val[i-1])continue;
		mp[val[i]]=++last;
	}
	for(int i=1;i<=m1;i++)
	{
		a1[i].s=mp[a1[i].s];
		a1[i].t=mp[a1[i].t];
		bel1[a1[i].t]=i;
	}
	for(int i=1;i<=m2;i++)
	{
		a2[i].s=mp[a2[i].s];
		a2[i].t=mp[a2[i].t];
		bel2[a2[i].t]=i;
	}
}
void Solve1()
{
	set<int> q;
	memset(pid,0,sizeof(pid));
	q.insert(a1[1].t);
	pid[a1[1].t]=1;
	int now=1;
	l1[now]++;
	for(int i=2;i<=m1;i++)
	{
		if(*q.begin()>a1[i].s)//��С�Ķ���s�� 
		{
			now++;
			l1[now]++;
			pid[a1[i].t]=now;
			q.insert(a1[i].t);
		}else
		{
			auto it=q.lower_bound(a1[i].s);
			//��һ�����ڵ���s��λ�� ��ǰ���� 
			it--;
			int minx=inf_int,v;
			for(;;it--)
			{
				if(pid[*it]<minx)
				{
					v=*it;minx=pid[*it];
				}
				if(it==q.begin())break;
			}
			q.erase(v);
			pid[a1[i].t]=minx;
			l1[minx]++;
			q.insert(a1[i].t);
		}
	}
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+l1[i];
//	printf("NOW:%d\n",now);
//	for(int i=1;i<=m1;i++)
//	{
//		printf("%d : %d\n",i,pid[a1[i].t]);
//	}
}
void Solve2()
{
	set<int> q;
	memset(pid,0,sizeof(pid));
	q.insert(a2[1].t);
	pid[a2[1].t]=1;
	int now=1;
	l2[now]++;
	for(int i=2;i<=m2;i++)
	{
		if(*q.begin()>a2[i].s)//��С�Ķ���s�� 
		{
			now++;
			l2[now]++;
			pid[a2[i].t]=now;
			q.insert(a2[i].t);
		}else
		{
			auto it=q.lower_bound(a2[i].s);
			//��һ�����ڵ���s��λ�� ��ǰ���� 
			it--;
			int minx=inf_int,v;
			for(;;it--)
			{
				if(pid[*it]<minx)
				{
					v=*it;minx=pid[*it];
				}
				if(it==q.begin())break;
			}
			q.erase(v);
			pid[a2[i].t]=minx;
			l2[minx]++;
			q.insert(a2[i].t);
		}
	}
///	printf("NOW:%d\n",now);
//	for(int i=1;i<=m2;i++)
//	{
//		printf("%d : %d\n",i,pid[a2[i].t]);
//	}
	for(int i=1;i<=n;i++)sum2[i]=sum2[i-1]+l2[i];
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[i].s,&a1[i].t);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&a2[i].s,&a2[i].t);
	}
	Init();
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	Solve1();
	Solve2();
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,sum1[i]+sum2[n-i]);
//		printf("%d %d\n",sum1[i],sum2[n-i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
��ʱ����ɢ��  
ת��Ϊ ����һЩ�߶� 
Ҫ����Щ�߶�����һ�������� ���Էֲ� ���������� 
��ÿ�����˶��� 
�����ڷֲ� ���Ը����鶼�ֲ� 
Ȼ��ö��ÿ�ߵĲ��� 
��һ�����ȶ��б�����С��t 
����Լ��ˡ������� 
���Ա��setÿ��lowerbound������С�� 
Ȼ����������Ԫ�� ȡһ��min 
���� �Ȼ����ˡ� 
3:26д�ꡣԭ�ؿ�ʼ���ġ� 
3:41ɵ�� ����д���� �����˴����� 
4:08�۹������������ĳ���һ���� 
*/
