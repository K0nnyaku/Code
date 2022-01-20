#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 20 + 10;
const string IAM = " am guilty.";
const string IAMNOT = " am not guilty.";
const string HEIS = " is guilty.";
const string HEISNOT = " is not guilty.";

struct Man {
	int gtis;
	int gtisnt;
	int date;

	Man(int _gtis = 0, int  _gtisnt = 0, int _date = 0) 
	{
		gtis = _gtis; gtisnt = _gtisnt; date = _date;
	}

	void Test();
}A[MAXN];

unordered_map<string, int> Bk;
int Ans[MAXN];
int n, m, p, iNdex;

bool Check(int);

int main() 
{
	freopen("In.in", "r", stdin);

	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++) 
	{
		string T;
		cin >> T;
		Bk[T] = i;

		cout << T << Bk[T] << endl;
	}

	for(int i = 1; i <= p; i++) 
	{
		string P, Name;
		int pos;
		cin >> Name; Name.pop_back();
		pos = Bk[Name];

		cin >> P;

		if(P[0] == 'I' && P.size() == 1) 
		{
			getline(cin, P);
			if(P == IAM) A[pos].gtis = (1 << pos);
			else if(P == IAMNOT) A[pos].gtisnt ^= (1 << pos);
			continue;
		}

		if(Bk[P]) 
		{
			string T;
			getline(cin, T);
			if(T == HEIS) A[pos].gtis = (1 << Bk[P]);
			else if(T == HEISNOT) A[pos].gtisnt ^= (1 << Bk[P]);
			continue;
		}

		if(P == "Today") 
		{
			cin >> P;
			if(P == "is") 
			{
				cin >> P;
				if(P == " Monday.") A[pos].date = 1;
				else if(P == " Tuesday.") A[pos].date = 2;
				else if(P == " Wednesday.") A[pos].date = 3;
				else if(P == "Thursday.") A[pos].date = 4;
				else if(P == "Friday.") A[pos].date = 5;
				else if(P ==  "Saturday.") A[pos].date = 6;
				else if(P == "Sunday.") A[pos].date = 7;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		A[i].Test();
	}

	for(int i = 1; i <= n; i++) 
	{
		for(int j = 1; j <= 7; j++)
		{
			int lier = 0, rub = 0;
			for(int v = 1; v <= n; v++) 
			{
				if(A[v].date == 0 && A[v].gtis == 0) 
				{
					if((A[v].gtisnt >> i) & 1) lier++;
					else rub++;
				}
				else 
				{
					if(A[v].date != j && (A[v].gtis != 0 && ((A[v].gtis >> i) ^ 1))) 
					{
						lier++;
						continue;
					}
				}
			}
			if((lier == m || (lier < m && lier + rub >= m)) && Ans[iNdex-1] != i) Ans[iNdex++] = i; 
		}
	}

	for(int i = 0; i < iNdex; i++) 
		printf("%d\n", Ans[i]);

	if(iNdex > 1) printf("Cannot Determine");
	else if(iNdex == 1) printf("%d", Ans[0]);
	else printf("Impossible");

	return 0;
}

void Man::Test() {
	printf("\n");
	printf("gtis = %d\n", gtis);
	printf("gtisnt = %d\n", gtisnt);
	cout << "date = " << date << endl;
}

















