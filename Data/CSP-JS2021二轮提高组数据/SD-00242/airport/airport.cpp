#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cfenv>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

const int N(100005);

struct Node {
	long long arrive, leave;
	Node() =  default;
	Node(const long long &a, const long long &b) : arrive(a), leave(b) {}
};

Node a1[N], a2[N];
long long n, m1, m2, inheap1[N], inheap2[N], dfn1[N], dfn2[N];

bool cmp(const Node &a, const Node &b) {
	return a.arrive < b.arrive;
}

template<typename T>
T read(); 
long long check(const long long &num) {
	std::priority_queue<long long, std::vector<long long>, std::greater<long long> > heap1, heap2;
	int cnt1(0), cnt2(0), ans1(0), ans2(0);
	if(num)
	for (int i(1); i <= m1; ++i) {
		if(heap1.empty()) heap1.push(a1[i].leave), ++ans1, ++cnt1;
		else if (heap1.top() < a1[i].arrive) heap1.pop(), heap1.push(a1[i].leave), ++ans1;
		else if (cnt1 < num) heap1.push(a1[i].leave), ++cnt1, ++ans1;
	}
	if(num ^ n)
	for (int i(1); i <= m2; ++i) {
		if(heap2.empty()) heap2.push(a2[i].leave), ++ans2, ++cnt2;
		else if(heap2.top() < a2[i].arrive) heap2.pop(), heap2.push(a2[i].leave), ++ans2;
		else if (cnt2 < (n - num)) heap2.push(a2[i].leave), ++cnt2, ++ans2;
	}
	return ans1 + ans2;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read<long long>(), m1 = read<long long>(), m2 = read<long long>();
	for (int i(1); i <= m1; ++i)
		a1[i].arrive = read<long long>(), a1[i].leave = read<long long>();
	for (int i(1); i <= m1; ++i)
		a2[i].arrive = read<long long>(), a2[i].leave = read<long long>();
	std::sort(a1 + 1, a1 + 1 + m1, cmp);
	std::sort(a2 + 1, a2 + 1 + m2, cmp);
	long long cnt1(0), cnt2(0); 
	/*for (int i(1); i <= std::max(m1, m2); ++i) {
		if (i == 1) {
			dfn1[i] = ++cnt1;
			dfn2[i] = ++cnt2;
			heap1.push(std::make_pair(a1[i].leave, dfn1[i]));
			heap2.push(std::make_pair(a2[i].leave, dfn1[i]));
			++inheap1[dfn1[i]];
			++inheap2[dfn2[i]];
		}
		else {
			if(heap1.top().first < a1[i].arrive){
				dfn1[i] = heap1.top().second;
				heap1.pop();
				heap1.push(std::make_pair(a1[i].leave, dfn1[i]));
				++inheap1[dfn1[i]];
			}
			else{
				dfn1[i] = ++ cnt1;
				heap1.push(std::make_pair(a1[i].leave, dfn1[i]));
				++inheap1[dfn1[i]];
			}
			if(heap2.top().first < a2[i].arrive){
				dfn2[i] = heap2.top().second;
				heap2.pop();
				heap2.push(std::make_pair(a2[i].leave, dfn2[i]));
				++inheap2[dfn2[i]];
			}
			else{
				dfn2[i] = ++ cnt2;
				heap2.push(std::make_pair(a2[i].leave, dfn2[i]));
				++inheap2[dfn2[i]];
			}
		}
	}
	for (register int i(2);i <= n; ++i)
		inheap1[i] += inheap1[i-1];
	for (register int i(2);i <= n; ++i)
		inheap2[i] += inheap2[i-1];
	*/
	long long maxn(0);
	for (register int i(0);i <= n; ++i)
		//maxn = std::max(maxn, inheap1[i] + inheap2[n - i]);
		maxn = std::max(maxn, check(i));
	printf("%d", maxn);
	fclose(stdin), fclose(stdout);
	return 0;
}


template<typename T>
T read() {
	T x(0), f(1);
	char ch;
	while (!isdigit(ch = getchar())) {
		f = 1;
		if(ch == '-') f = -1;
	}
	x = ch & 15;
	while (isdigit(ch = getchar())) x = (x << 1) + (x << 3) + (ch & 15);
	return x * f;
}

