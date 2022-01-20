#include<bits/stdc++.h>
using namespace std;
int nl[100010]={0},wl[100010]={0};
struct hb{
	int jz,cz;
}gn[100010],gw[100010];

bool cmp(struct hb a,struct hb b){
	return a.jz<b.jz;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m_1,m_2;
	scanf("%d%d%d",&n,&m_1,&m_2);
	
	for(int i=1;i<=m_1;i++){
		scanf("%d%d",&gn[i].jz,&gn[i].cz);
	}
    sort(gn+1,gn+1+m_1,cmp);
	
	for(int i=1;i<=m_2;i++){
		scanf("%d%d",&gw[i].jz,&gw[i].cz);
	}
	sort(gw+1,gw+1+m_2,cmp);
	
	int ans=0;
	for(int i=0;i<=n;i++){
		int sum=0;
		int nls=i,wls=n-i;
		int q=1,h=0;
		for(int j=1;j<=m_1;j++){
			if(i==0)break;
			if(h-q+1<nls){
				sum++;
				nl[++h]=gn[j].cz;
			}
			else{
				sort(nl+q,nl+h+1);
				while(h>=q&&nl[q]<=gn[j].jz){
					q++;
				}
				if(h-q+1<nls){
				    sum++;
				    nl[++h]=gn[j].cz;
		    	}
			}
		}
		q=1,h=0;
		for(int j=1;j<=m_2;j++){
			if(wls==0)break;
			if(h-q+1<wls){
				sum++;
				wl[++h]=gw[j].cz;
			}
			else{
				sort(wl+q,wl+h+1);
				while(h>=q&&wl[q]<=gw[j].jz){
					q++;
				}
				if(h-q+1<wls){
				    sum++;
				    wl[++h]=gw[j].cz;
		    	}
			}
		}
		//cout<<i<<sum<<endl;
		ans=max(sum,ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
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
9 10*/
