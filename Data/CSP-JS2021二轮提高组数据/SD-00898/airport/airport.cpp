#include<iostream>
#include<cstdio>
using namespace std;
struct M{
	int begin;
	int end;
};
M ar[10000];
M ar1[10000];

void Sort(M ar[],int l, int r){
	if(l>=r)return;
	int i=l,j=r; M key=ar[l];
	while(i<j){
		while(i<j && ar[j].begin>key.begin){
			j--;
		}
		ar[i]=ar[j];
		while(i<j && ar[i].begin<key.begin){
			i++;
		}
		ar[j]=ar[i];
	}
	ar[i]=key;
	Sort(ar,l,i-1);
	Sort(ar,i+1,r);
	return;
}
int DFS(M ar[],int m,int n){
	int maxx=0;
	int k=m;
	ar[k].begin==-1;
	for(int i=m+1;i<=n;i++){
		if(ar[i].begin>ar[k].end){
			maxx++;
			k=i;
			ar[i].begin=-1;
		}
	}
	return maxx+1;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>ar[i].begin>>ar[i].end;
	}
	Sort(ar,0,m1-1);
	
	for(int i=0;i<m2;i++){
		cin>>ar1[i].begin>>ar1[i].end;
	}
	Sort(ar1,0,m2-1);
	int sum=0;
	

	int v1=DFS(ar,0,m1-1);
	int v2=DFS(ar,0,m2-1);
	
	while(n>0){
		if(v1>v2){
		    sum+=v1;
			for(int i=0;i<m1;i++){
				if(ar[i].begin!=-1){
				  v1=DFS(ar,i,m1-1);
				  break;
			    }
			}
		}
		else{
			sum+=v2;
			for(int i=0;i<m2;i++){
				if(ar1[i].begin!=-1){
				  v2=DFS(ar1,i,m2-1);
				  break;
			    }
			}
		}
		n--;
	}
	
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
int ar1[10000];
int ar2[10000];
int ar3[1000];
int ar4[1000];
int used[1000];
int used1[1000];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;

    int max1=0,max2=0;
    
	for(int i=0;i<m1;i++){
		int b=0,e=0;
		cin>>b>>e;
	    cout<<b<<e<<endl;
		max1>e?max1=max1:max1=e;
		if(ar1[b-1]>=ar1[b]+1)used[ar1[b]+1]++;
		for(int j=b;j<=e;j++)ar1[j]++;
		for(int i=0;i<=max1;i++)cout<<ar1[i]<<' ';
	}
	
	for(int i=0;i<m2;i++){
		int b,e;
		cin>>b>>e;
		max2>e?max2=max2:max2=e;
		if(ar2[b-1]>=ar2[b]+1)used[ar2[b]+1]++;
		
		for(int j=b;j<=e;j++)ar2[j]++;
	}
	int maxx1=0,maxx2=0;
	for(int i=0;i<max1;i++){
		maxx1>ar1[i]?maxx1=maxx1:maxx1=ar1[i];
	}
	for(int i=0;i<max2;i++){
		maxx2>ar2[i]?maxx2=maxx2:maxx2=ar2[i];
	}
	
	int flag=0,total=0;
	for(int i=maxx1;i>0;i--){
		ar3[total]=1;
		for(int j=0;j<max1;j++){
			if(ar1[j]==i){
				flag=1;
				ar1[j]--;
			}
			else if(ar1[j]!=i && flag==1){
				ar3[total]++;
				flag=0;
			}
		}
		ar3[total]!=used[i];
		total++;
	}
	int total1=0;
	for(int i=maxx2;i>0;i--){
		ar4[total]=1;
		for(int j=0;j<max2;j++){
			if(ar2[j]==i){
				flag=1;
				ar2[j]--;
			}
			else if(ar2[j]!=i && flag==1){
				ar4[total1]++;
				flag=0;
			}
		}
		ar4[total1]+=used[i];
		total1++;
	}
	cout<<endl;
	
//	for(int i=total;i>=0;i--)cout<<ar3[i]<<' ';
	/*
	total--;
	total1--;
	
	int sum=0,mmax=0;
	while(total!=0 or total1!=0){
		if(n==0)break;
		ar3[total]>ar4[total1]?sum+=ar3[total],total--:sum+=ar4[total1],total1--;
		n--;
	}
	while(total!=0 ){
		if(n==0)break;
		sum+=ar3[total];total--;
		n--;
	}
	while(total1!=0 ){
		if(n==0)break;
		sum+=ar4[total1];total1--;
		n--;
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
