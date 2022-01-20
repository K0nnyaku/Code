#include<bits/stdc++.h> 
#define ll long long

using namespace std;

const int N = 5e5 + 9;

bool bj = 0;
ll t, n;
ll zhun[N * 2], hou[N * 2], chu[N * 2];

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	cin >> t;
	
	for(ll o = 1; o <= t; o++)
	{
		memset(zhun, 0, sizeof(zhun));
		memset(chu, 0, sizeof(chu));
		cin >> n;bj = 0;
		for(ll i = 1; i <= 2 * n; i++)
		{
			cin >> zhun[i];
			chu[zhun[i]] ++;
			if(chu[zhun[i]] > 2)
			{
				bj = 1;
				cout << "-1";
				break;
			}
		}
		if(bj){
			continue;
		}
		for(ll i = 1; i <= 2 * n; i++)
		{
			if(chu[zhun[i]] <= 1)
			{
				cout << "-1";
				break;
			}
		}
		doit();
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
