#include<bits/stdc++.h>
using namespace std;

const int N = 1e8 + 20;
int n, m1, m2, a[N], b[N], suma, sumb, maxa, maxb, ans, mina = N, minb = N;
int flag[N];

/*struct node
{
	int come, leave;
};
struct node a[N];
struct node b[N];
*/

inline int read()
{
	int I = 0, AK = 1; char IOI = getchar();
	while(IOI > '9' || IOI < '0') { if(IOI == '-') AK = -1; IOI = getchar(); }
	while(IOI <= '9' && IOI >= '0') { I = I * 10 + IOI - 48; IOI = getchar(); }
	return I * AK;
}


int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
    n = read();
    m1 = read();
    m2 = read();
    int x, y;
    for(long long i = 0 ; i < m1 ; i ++) 
    {
    	x = read();
    	y = read();
    	a[x] = y;
    	maxa = max(maxa, x);
    	mina = min(mina, x);
	}
	for(long long i = 0 ; i < m2 ; i ++)
	{
        x = read();
    	y = read();
    	b[x] = y; 
    	maxb = max(maxb, x);
    	minb = min(minb, x);
	}
	if(n >= m1 + m2) printf("%d", m1 + m2);
	else
	{
	  	for(int i = 0 ; i <= n ; i ++)
	{
		int zhaia = i;
		int zhaib = n - i;
		memset(flag, 0, sizeof(flag));
		suma = 0;
		if(zhaia > 0)
		{
			for(int j = 1 ; j <= zhaia ; j ++)
			{
			//	cout << "##" << j <<  "##" << endl;
				for(int q = mina ; q <= maxa ; q ++)
				{
					if(a[q] && flag[q] == 0)
					{
						suma ++;
						flag[q] = 1;
				//		cout << q << " " << a[q] << endl;
						for(int z = a[q] + 1 ; z <= maxa ; z++)
						{
							if(a[z] && flag[z] == 0)
							{
					//			cout << z << "  " << a[z] << endl;
								suma ++;
								flag[z] = 1;
								z = max(z, a[z]);
							}
						}
						break;
						j ++;
					}
				}
			}
		}
		
	//	cout << i << " a***a " << suma << endl;
		
		memset(flag, 0, sizeof(flag));
		sumb = 0;
		
		if(zhaib > 0)
		{
			for(int j = 1 ; j <= zhaib ; j ++)
			{
			//	cout << "##" << j <<  "##" << endl;
				for(int q = minb ; q <= maxb ; q ++)
				{
					if(b[q] && flag[q] == 0)
					{
						sumb ++;
						flag[q] = 1;
					//	cout << q << " " << a[q] << endl;
						for(int z = b[q] + 1 ; z <= maxb ; z++)
						{
							if(b[z] && flag[z] == 0)
							{
					//			cout << z << "  " << a[z] << endl;
								sumb ++;
								flag[z] = 1;
								z = max(z, b[z]);
							}
						}
						break;
						j ++;
					}
				}
			}
		}
	//	cout << i << " b***b " << sumb << endl;
	ans = max(ans, suma + sumb);
	}	
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
