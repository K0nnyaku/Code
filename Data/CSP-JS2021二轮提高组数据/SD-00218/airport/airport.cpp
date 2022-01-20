#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define LL long long
#define f1(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
struct node{
	int s,e,num,ju;
}a1[100009],a2[100009],b1[100009],b2[100009];
int d1[100009],d2[100009],ans1[100009],ans2[100009];
int n,m1,m2,ans=-1,sum;
bool flag,ju1[100009],ju2[100009];
int cnt=0;
int cmp(node a,node b){
	if(a.s>b.s)return 0;
	if(a.s<b.s)return 1;
	if(a.e<b.e)return 1;
	return 0;
}bool cmp2(node a,node b){
	return a.e<b.e;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	f1(i,1,m1)
		scanf("%d%d",&a1[i].s,&a1[i].e),a1[i].num=i,b1[i]=a1[i],b1[i].ju=0;
	f1(i,1,m2)
		scanf("%d%d",&a2[i].s,&a2[i].e),a2[i].num=i,b2[i]=a2[i],b2[i].ju=0;
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	sort(b1+1,b1+m1+1,cmp2);
	sort(b2+1,b2+m2+1,cmp2);
	f1(l,0,n){
		memset(ju1,0,sizeof(ju1));
		memset(ju2,0,sizeof(ju2));
		f1(i,1,m1)a1[i].ju=0;
		f1(i,1,m2)a2[i].ju=0;
		int s1=l,s2=n-l;
		sum=0;cnt=0;
		if(l!=0)f1(i,1,m1){
			if(i==1){
				cnt++;sum++;
				ju1[i]=1;
				a1[i].ju=1;
				continue;
			}else{
				f1(j,1,m1)
					if(i!=j&&ju1[j]==1&&a1[j].ju==1&&a1[i].s>a1[j].e)
						cnt--,a1[j].ju=0;
				if(cnt<s1){
					cnt++;
					sum++;
					a1[i].ju=1;
					ju1[i]=1;
				}
			}
		}
		cnt=0;
		if(l!=n)f1(i,1,m2){
			if(i==1){
				cnt++;sum++;
				ju2[i]=1;
				a2[i].ju=1;
				continue;
			}else{
				f1(j,1,m2)
					if(i!=j&&ju2[j]==1&&a2[j].ju==1&&a2[i].s>a2[j].e)
						cnt--,a2[j].ju=0;
				if(cnt<s2){
					cnt++;
					sum++;
					a2[i].ju=1;
					ju2[i]=1;
				}
			}
		}ans=max(sum,ans);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
