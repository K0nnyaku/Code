#include<bits/stdc++.h>

using namespace std;
int n,m1,m2,ansa[100001],ansb[100001],ans=0;
struct node {
	int x,y;
} a[100001],b[100001];
bool cmp(node i,node j) {
	return i.x<j.x;
}
/*
void kkkk(node a[],int m1,int ansa[]){
	int j=1,k=1;
	for(k=1;;k++) {
		if(k>1)ansa[k]=ansa[k-1];
		if(k==1)ansa[k]=1;
		for(int i=1;;) {
			for(j=i; j<=m1; j++) {
				if(a[i].y<a[j].x) {
					a[i].x=a[i].y=0x3f3f3f3f;
					i=j;
					ansa[k]++;
					break;
				}
			}
			if(j==m1){
				j=1;
				break;
			}
		}
		sort(a+1,a+n+1,cmp);
		if(a[1].x==0x3f3f3f3f)break;
	}
	for(int i=k+1;i<=n;i++){
		ansa[i]=ansa[k];
	}
}*/
int main() {

	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1; i<=m2; i++) {
		cin>>b[i].x>>b[i].y;
	}
	if(n>=m1+m2) {
		cout<<m1+m2<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
//	kkkk(a,m1,ansa);
//	kkkk(b,m2,ansb);
	int ans=0;
	for(int L=0; L<=n; L++) {
		memset(ansa,0,sizeof(ansa));
		memset(ansb,0,sizeof(ansb));
		int R=n-L;
		int ans1=0,ans2=0,min1[2]= {0x3f3f3f3f},min2[2]= {0x3f3f3f3f};
		int p=L;
		ans1+=p;
		if(p>=m1)ans1=m1;
		else if(p==0)ans1=0;
		else {
			bool f=1;
			for(int i=1; i<=p; i++)ansa[i]++;
			while(p<=m1) {
				if(f) {
					for(int j=1; j<=p; j++) {
						if(ansa[j])
							if(min1[0]>a[j].y) {
								min1[0]=a[j].y;
								min1[1]=j;
							}
					}
				}

				if(a[p+1].x>min1[0])ans1++,p++,ansa[p]++,ansa[min1[1]]=0,f=1;
				else p++,f=0;
			}
		}
		ans2+=R;
		if(R>=m2)ans2=m2;
		else if(R==0)ans2=0;
		else {
			bool f=1;
			for(int i=1; i<=R; i++)ansb[i]++;
			while(R<=m2) {
				if(f) {
					for(int j=1; j<=R; j++) {
						if(ansb[j])
							if(min2[0]>b[j].y) {
								min2[0]=b[j].y;
								min2[1]=j;
							}
					}
				}

				if(b[R+1].x>min2[0])ans2++,R++,ansb[R]++,ansb[min2[1]]=0,f=1;
				else R++,f=0;
			}
		}

		ans=max(ans,ans1+ans2);
	}
	cout<<ans<<endl;




	fclose(stdin);
	fclose(stdout);
	return 0;
}

