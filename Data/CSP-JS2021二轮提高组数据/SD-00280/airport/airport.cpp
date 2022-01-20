//biao bai xtt! by szhlg
#include<cstdio>
#include<algorithm>
#include<queue>
#define fr first
#define se second
#define mp make_pair
using namespace std;
int kuaidu()
{
	int x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
void chu(int x)
{
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9) chu(x/10);
	putchar(x%10+'0');
}
const int maxn = 100005;
struct stu{
	int a,b;
}tc1[maxn],tc2[maxn],xtt[maxn];//3 ge xtt!
int n,mm1,mm2,f[maxn],g[maxn];
bool cmp(stu aa,stu ab)
{
	return aa.a < ab.a; 
}
priority_queue<pair<int,int> > q;
priority_queue<int> qq;
int ji[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = kuaidu(),mm1 = kuaidu(),mm2 = kuaidu();
	for(int i=1;i<=mm1;++i)
		tc1[i].a = kuaidu(),tc1[i].b = kuaidu();
	for(int i=1;i<=mm2;++i)
		tc2[i].a = kuaidu(),tc2[i].b = kuaidu();
	//f[i] biaoshi gei guonei i ge hui you duoshao ge ren 
/*	for(int i=1;i<=mm1;++i)
		xtt[i*2 - 1].a = tc1[i].a,xtt[i*2].a = tc1[i].b;
	for(int i=1;i<=mm1*2;++i) xtt[i].b = i;
	sort(xtt + 1,xtt + mm1 + mm1 + 1,cmp); 
	for(int i=1;i<=mm1*2;++i)
	{
		int xx = xtt[i].b;
		if(xx % 2 == 1) tc1[(xx+1)/2].a = i;
		else  tc1[xx/2].b = i;
	}*/
	sort(tc1 + 1,tc1 + mm1 + 1,cmp);
	int t = -1e8;
	for(int i=1;i<=n;++i) qq.push(-i); 
	for(int i=1;i<=mm1;++i)
	{
		t = tc1[i].a;
		while(!q.empty())
		{
			int xx = q.top().fr; xx = -xx;
			if(xx < t){
				int nn = q.top().se;
				nn = ji[nn];
				q.pop();
				if(nn > n) continue;
				qq.push(-nn);
			}
			else break;
		}
		if(!qq.empty())
		{
			int xx = qq.top(); xx = -xx;
			qq.pop();
			f[xx] ++; ji[i] = xx;
			q.push(mp(-tc1[i].b,i));
		}
	}
	for(int i=1;i<=n;++i) f[i] += f[i-1];
	
	while(!q.empty()) q.pop();
	while(!qq.empty()) qq.pop();
	for(int i=1;i<=100000;++i) ji[i] = 0;
	
	
	sort(tc2 + 1,tc2 + mm2 + 1,cmp);
	for(int i=1;i<=n;++i) qq.push(-i); 
	for(int i=1;i<=mm2;++i)
	{
		t = tc2[i].a;
		while(!q.empty())
		{
			int xx = q.top().fr; xx = -xx;
			if(xx < t){
				int nn = q.top().se;
				nn = ji[nn];
				q.pop();
				if(nn > n) continue;
				qq.push(-nn);
			}
			else break;
		}
		if(!qq.empty())
		{
			int xx = qq.top(); xx = -xx;
			qq.pop();
			g[xx] ++; ji[i] = xx;
			q.push(mp(-tc2[i].b,i));
		}
	}
	for(int i=1;i<=n;++i) g[i] += g[i-1];
	
	//for(int i=0;i<=n;++i) printf("%d %d\n",f[i],g[i]);
	
	int ans = 0;
	for(int i=0;i<=n;++i) ans = max(ans,f[i] + g[n-i]);
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

