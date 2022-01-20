#include<bits/stdc++.h>  //我只要40分！！！！！！ 
//////////////////////////////AAAAAAAAAAAAAAAAAAAAFFFFFFFFFFFFFFFFFFFFFOOOOOOOOOOOOOOOOOOOOOOO
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0)
#define re register
const int maxn=1e5+10;
int n,m1,m2,ans;
int F1[maxn],F2[maxn];
void fre()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
}
struct note
{
	int l,r;
}A1[maxn],A2[maxn];
bool cmp(note a,note b)
{
	return a.l<b.l;
}
int main()
{
	fre(); 
	IO;
	cin>>n>>m1>>m2;
	for(re int i=1;i<=m1;i++) cin>>A1[i].l>>A1[i].r;
	for(re int i=1;i<=m2;i++) cin>>A2[i].l>>A2[i].r;
	sort(A1+1,A1+1+m1,cmp);  sort(A2+1,A2+1+m2,cmp);
//	for(re int i=1;i<=m1;i++) printf("%d %d\n",A1[i].l,A1[i].r);
	for(re int i=0;i<=n;i++)
	{
		int t1=0,t2=0,sum=0; 
		int tot1=0,tot2=0;
		int s1=1,s2=1;
		F1[s1]=A1[1].r,F2[s2]=A2[1].r;
		int tim;
		
		for(int j=1;j<=m1;j++)
		{
			tim=A1[j].l;
			if(tim>F1[s1])
			{
				t1--;
				s1++;
			}
			if(t1>=i||t1<0) continue;
			else
			{
				t1++;
				tot1++;
				F1[tot1]=A1[j].r;
				sum++;
			}
		}
	//	cout<<sum<<"\n";
		for(int j=1;j<=m2;j++)
		{
			tim=A2[j].l;
			if(tim>F2[s2])
			{
				t2--;
				s2++;
			}
			if(t2>=n-i||t2<0) continue;
			else
			{
				t2++;
				tot2++;
				F2[tot2]=A2[j].r;
				sum++;
			}	
		}
	//	cout<<sum<<"\n";
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
} 
/*
21!9-324@emb
 */
/*li 1
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
///////////////////          7
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
////////////                4
