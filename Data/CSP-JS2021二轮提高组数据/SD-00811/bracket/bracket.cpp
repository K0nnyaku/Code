#include<bits/stdc++.h>
using namespace std;
//��
int n, maxk;
char s[505];
int ans;
int dp[505][505][505];  // �ŵ��˵�iλ��ǰ����j��δ�պϵ������ţ�k��*�ķ����� 
//����ά��¼�Ǻ�����û�бպϹ� 
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> maxk;
	cin >> s + 1;
	dp[0][0][0] = 1;
	for(int i = 0; i <= n; i ++)
	{
		for(int j = 0; j <= n; j ++)
		{
			for(int k = 0; k <= n; k ++)
			{
				
				if(s[i + 1] == '(' || s[i + 1] == '?')
				{ 
					dp[i + 1][j + 1][0] += dp[i][j][k]; 
				}
				if(s[i + 1] == ')' || s[i + 1] == '?')
				{
					if(j - 1 >= 0)
					{
						dp[i + 1][j - 1][0] += dp[i][j][k];
					}
				}
				if(s[i + 1] == '*' || s[i + 1] == '?')
				{
					
					if(k + 1 <= maxk)
					{
						dp[i + 1][j][k + 1] += dp[i][j][k] + dp[i][j][k];
						//if(i + 1 == 6 && j  == 1 && k + 1 == 0) cout << i << " " <<j  <<" " << k << " " << dp[i][j][k] << endl;
						//if(i + 1 == 5) cout << i << " " <<j  <<" " << k << " " << dp[i][j][k] << endl;
					}
				}
			}
		}
	}
//	for(int i = 0; i <= maxk; i ++)
//	{
//		ans += dp[n][0][i];
//	}
	cout << dp[n][0][0] << endl;
	return 0;
}
