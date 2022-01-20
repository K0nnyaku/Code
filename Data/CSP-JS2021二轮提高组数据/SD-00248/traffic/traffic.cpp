#include <bits/stdc++.h>

using namespace std;

//������������ѯ�ʴ��� 
int n, m, T;

//�к����������ֵ 
#define MMN 500 

//���ڵ��� 
#define MS MMN * MMN + 4 * MMN 

//�ڵ㼯���뷴������ ������� = MS + ������� 
int ufs[MS * 2 + 1];

//���鼯��ʼ�� 
int ufs_init(int MAX = MS)
{
	for(int i = 1; i <= MAX; i++)
	{
		ufs[i] = i; ufs[i + MS] = i + MS;
	}
}

//���Ҽ��� 
int fs(int x)
{
	if(x == ufs[x]) return x;
	else return ufs[x] = fs(ufs[x]);
}

//�ϲ�����
int us(int a, int b)
{
	ufs[fs(a)] = fs(b);
}

//get������������ 
int gtpt(int i, int j)
{
	return (i - 1) * 500 + j;
}

//get���ӵ�������� 

//�����Ȩ��������� 
#define MBQ MMN * MMN * 2 - 2 * MMN + 4 * MMN 

//�����Ȩ������ 
struct bqin{
	int a, b;
	int bq;
}ybqin[MBQ + 1];

//ԭʼ��Ȩ������ԭʼ�ڵ�������ԭʼ�ܱ�Ȩ�� 
int ysbq = 1, yssp, ysum; 

//�ڵ���������Ȩ�������ܱ�Ȩ���������� 
int sp[51], sbq[51], sum[51], ans[51];

//���ӵ� 
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
	
	//�ó� ԭʼ�ڵ�����ysp��ԭʼ��Ȩ����ysbq��ԭʼ��Ȩ���ܺ�ysum��
	
	//ԭʼ��Ȩ����ybqin������ԭʼ�����Ȩ���ڵ㲢�鼯δ��ʼ��
	
	//��ʼ����ÿ��ѯ���� 
	
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
