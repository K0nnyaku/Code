#include<bits/stdc++.h>
using namespace std;

int T, n, a;
bool pd;
char ans[1000005];
int cnt, now[100005];
deque <int> D;

bool check ()
{
	for (int i=1, j=n*2; i<=n; i++, j--)
		if (now[i]!=now[j])
			return 0;
	return 1;
}

void dfs (int pos)
{
	if (pos>2*n)
	{
		if (check ()==1)
			pd=1;
		return ;
	}
	
	//L 
	int num=D.front ();
	D.pop_front ();
	now[++cnt]=num;
	ans[cnt]='L';
	dfs (pos+1);
	--cnt;
	D.push_front (num);
	if (pd)
		return;
	
	//R
	num=D.back ();
	D.pop_back ();
	now[++cnt]=num;
	ans[cnt]='R';
	dfs (pos+1);
	--cnt;
	D.push_back (num);
	if (pd)
		return;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf ("%d", &T);
	while (T--)
	{
		D.clear (); cnt=0; pd=0;
		memset (now, 0, sizeof(now));
		
		scanf ("%d", &n);
		for (int i=1; i<=n*2; i++)
			scanf ("%d", &a),
			D.push_back (a);
		
		
		if (n<=10)
		{
			dfs (1);
			if (pd)
			{
				for (int i=1; i<=n*2; i++)
					printf ("%c", ans[i]);
				printf ("\n");
			}
			else
				printf ("-1");
		 }
		 else
		 	printf ("-1");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

