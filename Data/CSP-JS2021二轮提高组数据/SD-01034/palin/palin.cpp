#include<stdio.h>

int n,m;
int a[1000002],p[500002][2];
char ans[1000002];

inline int solve(int n,int m,int *a,int *b)
{
	int h1=1,t1=n,h2=1,t2=m;
	static char ans1[100002],ans2[100002];
	int cnt1=0,cnt2=0;
	while(h1<=t1||h2<=t2)
	{
		if(h1<t1&&a[h1]==a[t1]) h1++,t1--,ans1[++cnt1]='L',ans2[++cnt2]='L';
		else if(h1<=t1&&h2<=t2&&a[h1]==b[t2]) h1++,t2--,ans1[++cnt1]='L',ans2[++cnt2]='R';
		else if(h1<=t1&&h2<=t2&&b[h2]==a[t1]) h2++,t1--,ans1[++cnt1]='R',ans2[++cnt2]='L';
		else if(h2<t2&&b[h2]==b[t2]) h2++,t2--,ans1[++cnt1]='R',ans2[++cnt2]='R';
		else return -1;
	}
	for(int i=1;i<=cnt1;i++) ans[i]=ans1[i];
	for(int i=1;i<=cnt2;i++) ans[i+cnt1]=ans2[cnt2-i+1];
	return 0;
}

int temp1[1000002],temp2[1000002];
int cnt1,cnt2;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) p[i][0]=p[i][1]=0;
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]),p[a[i]][0]?(p[a[i]][1]=i):(p[a[i]][0]=i);
		cnt1=cnt2=0;
		for(int i=2;i<p[a[1]][1];i++) temp1[++cnt1]=a[i];
		for(int i=2*n;i>=p[a[1]][1]+1;i--) temp2[++cnt2]=a[i];
		if(solve(cnt1,cnt2,temp1,temp2)!=-1){ printf("L%sL\n",ans+1);continue; }
		cnt1=cnt2=0;
		for(int i=1;i<p[a[2*n]][0];i++) temp1[++cnt1]=a[i];
		for(int i=2*n-1;i>=p[a[2*n]][0]+1;i--) temp2[++cnt2]=a[i];
		if(solve(cnt1,cnt2,temp1,temp2)!=-1){ printf("R%sL\n",ans+1);continue; }
		printf("-1\n");
	}
	return 0;
}
