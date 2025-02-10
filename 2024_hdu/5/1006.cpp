#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) &-(x))
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

struct node {
	int a,b,c;
	auto operator <=> (const node & b)const =default;
};
map<node,int>mp;

int sg(int a,int b,int c) {
	if (a == 1 && b == 1 && c == 1) return 0;
	//if (a == 0 || b == 0 || c == 0) return 0;
	if (mp[{a,b,c}]) return mp[{a,b,c}];
	set<int>s;
	int num1 = 0;
	for (int i = 1;i < b;i++) {
		s.insert(sg(a,i,b - i));
	}
	for (int i = 1;i < c;i++) {
		s.insert(sg(a,i,c - i));
	}
	//s.insert(num1);
	num1 = 0;
	for (int i = 1;i < a;i++) {
		s.insert(sg(i,b,a - i));
	}
	for (int i = 1;i < c;i++) {
		s.insert(sg(i,b,c - i));
	}
	//s.insert(num1);
	num1 = 0;
	for (int i = 1;i < a;i++) {
		s.insert(sg(i,a - i,c));
	}
	for (int i = 1;i < b;i++) {
		s.insert(sg(b - i,i,c));
	}
	//s.insert(num1);
	int now = 0;
	while (s.count(now)) now++;
	return mp[{a,b,c}] = now;
}

void solve(){
	// for (int i = 1;i <= 10;i++) {
	// 	for (int j = i;j <= 10;j++) {
	// 		for (int k = j;k <= 20;k++) {
	// 			sg(i,j,k);
	// 			int ans = sg(i,j,k);
	// 			if(ans == 0 and (i%2 == 0 or j%2==0 or k%2 == 0))dbg(i,j,k,ans);
	// 		}
	// 	}
	// }
	// int a,b,c;cin >> a >> b >> c;
	// if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1) {
	// 	cout << "NO" << '\n';
	// }
	// else if (a == b && b == c) {
	// 	cout << "NO" << '\n';
	// } else if(a % 4 == 2 and b % 4 == 2 and c % 4 == 2) std::cout << "NO\n";
	// else cout << "YES" << '\n';
	// dbg(sg(2, 2, 8));
	for(int i = 2; i <= 20; i += 2){
		for(int j = i; j <= 20; j += 2){
			for(int k = j; k <= 50; k += 2){
				int ans = sg(i, j, k);
				if(ans == 0)dbg(i,j,k, ans);
			}
		}
	}
	// int a, b, c; cin >> a >> b >> c;
	// if(lowbit(a) == lowbit(b) && lowbit(b) == lowbit(c)){
	// 	cout << "NO\n";
	// }else cout << "YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}