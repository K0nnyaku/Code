#include <algorithm>
#include <cstdio>
using namespace std;

FILE *fpi = fopen("airport.in" , "rb");
FILE *fpo = fopen("airport.out", "wb");

struct act
{
	int n, T; bool typ;

	bool operator<(const act &P) const
	{
		return T < P.T;
	}
};

act sche1[200000];
act sche2[200000];
bool onqu[100000];

int gen(act *sche, int n, int m)
{
	int ct = 0;

	if (n >= m) {return m; }

	for (int i = 0; i < m; ++i)
	{
		onqu[i] = false;
	}

	m <<= 1;

	for (int i = 0; i < m; ++i)
	{
		if (sche[i].typ)
		{
			if (onqu[sche[i].n])
			{
				onqu[sche[i].n] = false;
				++n;
			}
		}
		else
		{
			if (n > 0)
			{
				onqu[sche[i].n] = true;
				++ct, --n;
			}
		}
	}

	return ct;
}

int main()
{
    int n, m1, m2;
	fscanf(fpi, "%d%d%d", &n, &m1, &m2);

	m1 <<= 1, m2 <<= 1;

	for (int i = 0; i < m1; ++i)
	{
		fscanf(fpi, "%d", &sche1[i].T);
		sche1[i].typ = i & 1;
		sche1[i].n  = i >> 1;
	}

	for (int i = 0; i < m2; ++i)
	{
		fscanf(fpi, "%d", &sche2[i].T);
		sche2[i].typ = i & 1;
		sche2[i].n  = i >> 1;
	}

	sort(sche1, sche1 + m1);
	sort(sche2, sche2 + m2);

	int maxpl = 0;
	m1 >>= 1, m2 >>= 1;

	for (int i = 0; i <= n; ++i)
	{
		int pl = gen(sche1, i, m1)
			+ gen(sche2, n - i, m2);

		if (pl > maxpl)
		{
			maxpl = pl;
		}
	}

	fprintf(fpo, "%d\n", maxpl);
	return (fclose(fpi), fclose(fpo), 0);
}

