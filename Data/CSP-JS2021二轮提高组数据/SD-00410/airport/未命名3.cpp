#include<bits/stdc++.h>
using namespace std;
int pushplane(int let,int wai[],int wao[],int ans,int time,int hvi[]) {
	if(let>=0&&let>=wai[time]) {
		let-=wai[time];
		ans+=wai[time];
		hvi[time]=wao[time];
		let+=hvi[time];
		
	} else if(let>=0&&let<wai[time]) {
		
		ans+=let;
		hvi[time]=let;
		let=0;let+=hvi[time];
	}
	return ans;
}
int main() {
    freopen("airport1.in","r",stdin);
    freopen("airport1.out","w",stdout);
	int n,nei,wai,ans=0,likx=0,ase=0,maxt;
	cin>>n>>nei>>wai;
	int np[100005]={0},no[100005]={0},wp[100005]={0},wo[100005]={0},waii[5005]= {0},waio[5005]= {0},waoo[5005]= {0},waoi[5005]= {0},hvi[5005]= {0};
	for(int i=1; i<=nei; i++) {
		cin>>np[i]>>no[i];
		waii[np[i]]++;
		waio[no[i]]++;
		maxt=max(maxt,np[i]);
	}
	for(int i=1; i<=wai; i++) {
		cin>>wp[i]>>wo[i];
		waoi[wp[i]]++;
		waoo[wo[i]]++;
		maxt=max(maxt,wp[i]);
	}
	for(int i=0; i<=n; i++) {
		int leto=n-i;
		int leti=i;
		for(int time=1; time<=maxt; time++) {
			ase+=pushplane(leti,waii,waio,ans,time,hvi);
			ase+=pushplane(leto,waoi,waoo,ans,time,hvi);
		}
		likx=max(likx,ase);
		cout<<ase<<endl;
	}
	cout<<likx<<endl;
	return 0;
}

