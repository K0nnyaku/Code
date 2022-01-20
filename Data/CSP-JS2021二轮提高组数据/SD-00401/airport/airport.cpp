#include<cstdio>
#include<algorithm>
#include<cstring>
using std::sort;
using std::max;
int n,m1,m2,num[200000],past=-1,his=-1;
bool wrong,can[100000],did[100000];
struct plane{
	int a;
	int b;
	int inter;
}p[100000];
struct event{
	bool v;
	int t;
	int inter;
}e[200000];
bool check(int x1){
	int used1=0,used2=0,no1=0,no2=0,x2=n-x1;
	memset(can,0,sizeof(can));
	int cantem=0;
	for(int i=0;i<2*(m1+m2);i++){
		if(!e[num[i]].v){
			if(!e[num[i]].inter){
				if(used1<x1){
					used1++;
					can[num[i]]=1;
					cantem++;
				}
				else no1++;
			}
			else{
				if(used2<x2){
					cantem++;
					used2++;
					can[num[i]]=1;
				}
				else no2++;
			}
		}
		else{
			if(!e[num[i]].inter){
				if(can[num[i]-m1-m2])used1--;
			}
			else if(can[num[i]-m1-m2])used2--;
		}
	}
	if(cantem<past){
		wrong=1;
		return no1<no2;
	}
	past=cantem;
	return no1<no2;
}
int cal(int l,int r){
	int ans=0;
	int orimid=(l+r)>>1;
	if(did[orimid]){
		return his;
	}
	did[orimid]=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
		ans=0;
		for(int i=0;i<2*(m1+m2);i++)if(can[i])ans++;
		his=max(ans,his);
		if(wrong==1){
			break;
		}
	}
	if(wrong==1){
		wrong=0;
		if(l<=orimid)cal(r+1,n+1);
		else cal(0,r);
	}
	else{
		return his;
	}
}
bool cmp(int a,int b){
	return e[a].t<e[b].t;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		scanf("%d",&p[i].a);
		scanf("%d",&p[i].b);
	}
	for(int i=m1;i<m1+m2;i++){
		scanf("%d",&p[i].a);
		scanf("%d",&p[i].b);
		p[i].inter=1;
	}
	for(int i=0;i<m1+m2;i++){
		e[i].t=p[i].a;
		e[i].inter=p[i].inter;
		e[m1+m2+i].inter=p[i].inter;
		e[m1+m2+i].t=p[i].b;
		e[m1+m2+i].v=1;
		num[i]=i;
		num[m1+m2+i]=m1+m2+i;
	}
	sort(num,num+2*(m1+m2),cmp);
	printf("%d",cal(0,n+1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
