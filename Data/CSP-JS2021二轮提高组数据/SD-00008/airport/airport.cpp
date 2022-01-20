#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

	const int MAXN = 1e6+10;
	int n, m1, m2, max1, max2;	int ans = 0, counter;
	vector <pair<int, pair<int, int > > > vec1;
	vector <pair<int, pair<int, int > > > vec2;
	vector <pair<int, int> > num1;
	vector <pair<int, int> > num2;
	bool mode1[MAXN], mode2[MAXN];
	bool mode;
	//vector <pair<int到达时间, pair<int归去时间, int编号> > > vec;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m1 >> m2;

	if(n >= m1 + m2){
		cout << m1+m2 << endl;
		return 0;
	}

	for(int i = 1; i <= m1 ; i++)
	{
		int a, b;
		cin >> a >> b;
		vec1.push_back(make_pair(a, make_pair(b, i)));
	}

	for(int i = 1; i <= m2 ; i++)
	{
		int a, b;
		cin >> a >> b;
		vec2.push_back(make_pair(a, make_pair(b, i)));
	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	/*Judge m1 MAX*/
	while(true){
		counter = 1;
		max1++;
		for(vector <pair<int, pair<int, int > > >::iterator it = vec1.begin(); it != vec1.end(); ++it)
		{

			if(mode1[(*it).second.second] == true) {continue;}
			//cout << max1 << " " << (*it).second.second.first << endl;
			mode = 1;
			int cometime = (*it).first;
			int leavetime = (*it).second.first;
			//cout << max1 << " " << (*it).second.second.first << " " << cometime << " " << leavetime << " " << endl;
			//cout << (*it).second.second.second << endl;
			mode1[(*it).second.second] = true;
			//cout << (*it).second.second.second << endl;
			while(true)
			{
				++it;
				if(it == vec1.end()) {goto labels;}
				if(mode1[(*it).second.second] == true) {
				//cout << (*it).second.second.first << endl;
				//cout << 123546 << endl;
				continue;}
				if((*it).first > leavetime){
					//cout << 123546 << endl;
					--it;
					counter++;
					break;
				}
			}
		}
		labels:
		if(mode == 0) {max1--;break;}
		mode = 0;
		num1.push_back(make_pair(max1, counter));
		/*if(it == vec1.begin()) num1.push_back(make_pair(max1, counter));
		else num1.push_back(make_pair(max1, counter + (*(it-1)).second);*/
	}
	mode = 0;
	/*Judge m2 MAX NEW*/
	while(true){
		counter = 1;
		max2++;
		for(vector <pair<int, pair<int, int > > >::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{

			if(mode2[(*it).second.second] == true) {continue;}
			//cout << max2 << " " << (*it).second.second.first << endl;
			mode = 1;
			int cometime = (*it).first;
			int leavetime = (*it).second.first;
			//cout << max2 << " " << (*it).second.second.first << " " << cometime << " " << leavetime << " " << endl;
			//cout << (*it).second.second.second << endl;
			mode2[(*it).second.second] = true;
			//cout << (*it).second.second.second << endl;
			while(true)
			{
				++it;
				if(it == vec2.end()) {goto label2;}
				if(mode2[(*it).second.second] == true) {
				//cout << (*it).second.second.first << endl;
				//cout << 123546 << endl;
				continue;}
				if((*it).first > leavetime){
					//cout << 123546 << endl;
					--it;
					counter++;
					break;
				}
			}
		}
		label2:
		if(mode == 0) {max2--;break;}
		mode = 0;
		num2.push_back(make_pair(max2, counter));
		/*if(it == vec2.begin()) num2.push_back(make_pair(max2, counter));
		else num2.push_back(make_pair(max2, counter + (*(it-1)).second);*/
	}
	mode = 0;
	//cout << max1 << endl;
	//cout << max2 << endl;
	//return 2;
	/*Judge m2 MAX
	while(true){
		int counter = 1;
		max2++;
		for(vector <pair<int, pair<int, int > > >::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			if(mode2[(*it).second.second] == true) {continue;}
			mode = 1;
			int cometime = (*it).first;
			int leavetime = (*it).second.first;
			mode2[(*it).second.second] == true;
			while(true)
			{
				++it;
				if(it == vec2.end()) goto label;
				if(mode2[(*it).second.second] == true) continue;
				if((*it).second.first > leavetime){
					--it;
					break;
					counter++;
				}
			}
		}
		label:
		if(mode == 0) {max2--;break;}
		mode = 0;
		num2.push_back(make_pair(max2, counter));
	}*/
	//return 1;
	if(max1+max2 <= n){
		cout << m1+m2 << endl;
		return 0;
	}

	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());

	/*for(vector <pair<int, int> >::iterator it = num1.begin(); it != num1.end(); ++it)
	{		
		cout << (*it).first << " " << (*it).second << endl;
	}*/

	/*for(vector <pair<int, int> >::iterator it = num2.begin(); it != num2.end(); ++it)
	{		
		cout << (*it).first << " " << (*it).second << endl;
	}*/

	/*vector <pair<int, int> >::iterator it1 = num1.begin();
	vector <pair<int, int> >::iterator it2 = num2.begin();*/
	int numof1 = 0;
	int numof2 = 0;
	
	for(vector <pair<int, int> >::iterator it1 = num1.begin(); it1!=num1.end(); ++it1)
	{
		numof1 += (*it1).second;
		if((*it1).first == n) ans = max(ans, numof1);
		//cout << numof1 << endl;
		numof2 = 0;
		for(vector <pair<int, int> >::iterator it2 = num2.begin(); it2!=num2.end(); ++it2){
			numof2 += (*it2).second;
			if((*it2).first == n) ans = max(ans, numof2);
			//cout << numof2 << endl;
			if((*it1).first + (*it2).first == n){
				ans = max(ans, numof1+numof2);
				//cout << numof1 << " " << numof2 << " " << ans << endl;
				//ans = max(ans, (*it1).second+(*it2).second);
				//cout << ans << " " <<  (*it1).first << " " << (*it2).first << " " << (*it2).second << " " << (*it1).second << endl;
			}if((*it1).first + (*it2).first > n) break;
		}
	}
	/**/
	//ans = max(ans, max(numof1, numof2));
	/*mode = 0;
	int ans = 0;

	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());

	vector <pair<int, int> >::iterator it1 = num1.end();
	vector <pair<int, int> >::iterator it2 = num2.begin();

	while(true)
	{
		if((*it1).first == n - max2) break;
		else --it1;
	}

	for(; it1!=num1.end(); it1++, it2--)
	{
		ans = max(ans, (*it1).second+(*it2).second);
	}*/

	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

