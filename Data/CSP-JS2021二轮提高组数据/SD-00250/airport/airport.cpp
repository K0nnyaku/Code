#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
typedef long long LL;
void starT()
{freopen("airport.in", "r", stdin);freopen("airport.out", "w", stdout);}
void enD(){fclose(stdin);fclose(stdout);}
inline int read(){int a=1;int b=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();}while(c<='9'&&c>='0'){b=(b<<3)+(b<<1)+(c^'0');c=getchar();}return a*b;}
int max(int x, int y){if(x>y)return x;return y;}
struct node
{
	int arrive;
	int leave;
	bool operator < (const node x) const
	{return x.arrive > arrive;}// ½µÐò 
};
int n, shabi1, shabi2;
node m1[1000003];
node m2[1000003];
int Max1 = -0x3f3f, Max2 = -0x3f3f;
int	aNs = 0;
int rEs = -0x3f3f;
int seat1[1000003], seat2[1000003];
int main()
{
starT();
	n = read();
	shabi1 = read(), shabi2 = read();
	if (n >= shabi1 + shabi2)
	{
		printf("%d", shabi1 + shabi2);
		enD();
		return 0;
	}
	for (R int i = 1; i <= shabi1; ++i)
	{
		m1[i].arrive = read();
		m1[i].leave = read();
	}
	for (R int i = 1; i <= shabi2; ++i)
	{
		m2[i].arrive = read();
		m2[i].leave = read();
	}
	std :: sort(m1, m1 + shabi1);
	std :: sort(m2, m2 + shabi2);
	for (R int i = 0; i <= n; ++i)
	{
		aNs = 0;
		memset(seat1, 0, sizeof(seat1));
		memset(seat2, 0, sizeof(seat2));
		for (R int j = 1; j <= shabi1; ++j)
		{
			int flag = true;
			for (R int k = m1[j].arrive; k <= m1[j].leave; ++k)
			{
				if (seat1[k] < -i + 1)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (R int k = m1[j].arrive; k <= m1[j].leave; ++k)
					seat1[k]--;
				aNs++;
			}
		}
		for (R int j = 1; j <= shabi2; ++j)
		{
			bool flag = true;
			for (R int k = m2[j].arrive; k <= m2[j].leave; ++k)
			{
				if (seat2[k] < i - n + 1)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (R int k = m2[j].arrive; k <= m2[j].leave; ++k)
					seat2[k]--;
				aNs++;
			}
		}
		rEs = max(rEs, aNs);
	}
	printf("%d", rEs);
enD();
	return 0;
}

