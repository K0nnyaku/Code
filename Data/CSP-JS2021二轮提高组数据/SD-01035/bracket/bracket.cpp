#include <cstdio>

FILE *fpi = fopen("bracket.in" , "rb");
FILE *fpo = fopen("bracket.out", "wb");

bool pfx[500], hsc[500];
int p_stk, k, ans;

char s[500], sym[3] = {'*', '(', ')'};
int pos[500], n_pos;

bool check()
{
	int ct, stat = 0; p_stk = 0;

	for (bool &i : pfx)
	{
		i = false;
	}

	for (bool &i : hsc)
	{
		i = false;
	}

	for (int i = 0; s[i]; ++i)
	{ 
		switch (s[i])
		{
		case ('('):

			hsc[p_stk] = true;
			++p_stk, stat = 0;
			break;

		case (')'):

			if (stat == 1 && pfx[p_stk] && hsc[p_stk])
			{
				// puts("syntax err *");
				return false;
			}

			if (p_stk == 0)
			{
				// puts("syntax err )");
				return false;
			}

			pfx[p_stk] = false;
			hsc[p_stk] = false;
			--p_stk,  stat = 2;
			break;

		case ('*'):

			for (ct = 1; s[i + 1] && s[i + 1] == '*'; ++i, ++ct) { }

			if (ct > k)
			{
				// printf("syntax err ** %d\n", ct);
				return false;
			}

			if (stat == 0)
			{
				pfx[p_stk] = true;
			}

			stat = 1;
			break;

		default: return false;
		}
	}

	return p_stk == 0 && stat != 1 && !pfx[0];
}

void dfs(int x)
{
	for (char c : sym)
	{
		s[pos[x]] = c;

		if (x + 1 == n_pos)
		{
			if (check())
			{
				++ans;
			}
		}
		else
		{
			dfs(x + 1);
		}
	}
}

int main()
{
	int n;
	fscanf(fpi, "%d%d", &n, &k);
	fscanf(fpi, "%s", s);

	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '?')
		{
			pos[n_pos++] = i;
		}
	}

	dfs(0);

	fprintf(fpo, "%d", ans);
	return (fclose(fpi), fclose(fpo), 0);
}

