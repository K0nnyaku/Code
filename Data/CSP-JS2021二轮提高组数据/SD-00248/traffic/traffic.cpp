#include <bits/stdc++.h>

using namespace std;

//行数，列数，询问次数 
int n, m, T;

//行和列数的最大值 
#define MMN 500 

//最大节点数 
#define MS MMN * MMN + 4 * MMN 

//节点集合与反集数组 反集编号 = MS + 正集编号 
int ufs[MS * 2 + 1];

//并查集初始化 
int ufs_init(int MAX = MS)
{
	for(int i = 1; i <= MAX; i++)
	{
		ufs[i] = i; ufs[i + MS] = i + MS;
	}
}

//查找集合 
int fs(int x)
{
	if(x == ufs[x]) return x;
	else return ufs[x] = fs(ufs[x]);
}

//合并集合
int us(int a, int b)
{
	ufs[fs(a)] = fs(b);
}

//get常规点正集编号 
int gtpt(int i, int j)
{
	return (i - 1) * 500 + j;
}

//get附加点正集编号 

//读入边权的最大数量 
#define MBQ MMN * MMN * 2 - 2 * MMN + 4 * MMN 

//储存边权的数组 
struct bqin{
	int a, b;
	int bq;
}ybqin[MBQ + 1];

//原始边权数量，原始节点数量，原始总边权和 
int ysbq = 1, yssp, ysum; 

//节点数量，边权数量，总边权和数量，答案 
int sp[51], sbq[51], sum[51], ans[51];

//附加点 
struct TIN{
	int x, p , pp, t;
}tin[51];

int k[51];

int gtfj(int p, int n, int m)
{
	if(p >= 1 && p <= m)
		return gtpt(1, p);
	if(p >= m + 1 && p <= m + n)
		return gtpt(p - m, m);
	if(p >= m + n + 1 && p <= 2*m + n)
		return gtpt(n, 1 + m - (p - (m + n)));
	if(p >= 2 * m + n + 1)
		return gtpt(1 + n - (p - (2 * m + n)), 1);
}

int _gtfj(int p, int n, int m)
{
	if(p >= 1 && p <= m)
		return gtpt(1 + 1, p);
	if(p >= m + 1 && p <= m + n)
		return gtpt(p - m, m - 1);
	if(p >= m + n + 1 && p <= 2*m + n)
		return gtpt(n + 1, 1 + m - (p - (m + n)));
	if(p >= 2 * m + n + 1)
		return gtpt(1 + n - (p - (2 * m + n)), 1 + 1);
}

bool tincmp(TIN a, TIN b)
{
	return a.t < b.t;
}

bool cmp(bqin a, bqin b)
{
	return a.bq > b.bq;
}

int main()
{
	
	tin[0].t = 5;
	
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	cin >> n >> m >> T;
	
	yssp = n * m;
	
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> ybqin[ysbq].bq;	ysum += ybqin[ysbq].bq;
			
			ybqin[ysbq].a = gtpt(i, j);
			
			ybqin[ysbq].b = gtpt(i + 1, j);
			
			ysbq++;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m - 1; j++)
		{
			cin >> ybqin[ysbq].bq;	ysum += ybqin[ysbq].bq;
			
			ybqin[ysbq].a = gtpt(i, j);
			
			ybqin[ysbq].b = gtpt(i, j + 1);
			
			ysbq++;
		}
	}
	
	ysbq--;
	
	//cout << yssp << " " << ysbq << " " << ysum << endl;
	
	//得出 原始节点数量ysp，原始边权总数ysbq，原始边权和总和ysum；
	
	//原始边权队列ybqin里排满原始常规边权，节点并查集未初始化
	
	//开始读入每个询问组 
	
	for(int i = 1; i <= T; i++) 
	{
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> tin[j].x >> tin[j].p >> tin[j].t;
			tin[j].pp = gtfj(tin[j].p, n, m);
		}
		
		sort(tin + 1, tin + 1 + k[i], tincmp);
		
		sbq[i] = ysbq;
		
		ufs_init(yssp + k[i]);
		
		/*
		for(int j = ysbq + 1; j <= sbq[i] + k[i]; j++)
			if(tin[j - ysbq].t == tin[j - ysbq - 1].t)
				us(j, j - 1);*/
		
		sum[i] = ysum;
		
		for(int j = 1; j <= k[i]; j++)
		{
			++sbq[i]; ybqin[sbq[i]].bq = tin[j].x;
			ybqin[sbq[i]].a = tin[j].pp;
			ybqin[sbq[i]].b = _gtfj(tin[j].p, n, m);
			
			sum[i] += ybqin[sbq[i]].bq;
		}
		
		sort(ybqin + 1, ybqin + 1 + sbq[i], cmp);
		
		for(int j = 1; j <= sbq[i]; i++)
		{
			if(fs(ybqin[j].a) != fs(ybqin[j].b))
			{
				sum[i] -= ybqin[j].bq;
				us(ybqin[j].a + MS, ybqin[j].b);
				us(ybqin[j].a, ybqin[j].b + MS);
				us(ybqin[j].b + MS, ybqin[j].a);
				us(ybqin[j].b, ybqin[j].a + MS);
			}
		}
		ans[i] = sum[i];
	}
	
	for(int i = 1; i <= T; i++)
		cout << ans[i] << endl;
	
	return 0;
}
