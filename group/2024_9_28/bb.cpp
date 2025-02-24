#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}

char a[10][10];
int n, m;

void print() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}

bool isTwo11(int index, int op) {
	int cnt = 0;
	if(op == 1) {
		for(int i = 2; i <= m; ++i) {
			if(a[index][i] == '1' and a[index][i - 1] == '1') ++cnt;
		}
	}else {
		for(int i = 2; i <= n; ++i) {
			if(a[i][index] == '1' and a[i - 1][index] == '1') ++cnt;
		}
	} 
	return cnt >= 2;
}

bool isContainAdd(int index, int op) {
	if(op == 1) {
		for(int i = 1; i <= m; ++i) if(a[index][i] == '+') return true;
	} else {
		for(int i = 1; i <= n; ++i) if(a[i][index] == '+') return true;
	} 
	return false;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
	    for(int j = 1; j <= m; ++j) {
    		if(i == 1 or j == 1 or i == n or j == m) a[i][j] = '1';
    		else if(i % 2 == 0 and j % 2 == 0) a[i][j] = '*';
    		else if(i % 2 == 1 and j % 2 == 1) a[i][j] = '*';
    		else a[i][j] = '1';
	    }
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] != '*') continue;
			if(isTwo11(i, 1) and isTwo11(j, 2)) a[i][j] = '+';
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] != '*') continue;
			if(isTwo11(i, 1) and !isContainAdd(i, 1)) a[i][j] = '+';
			if(isTwo11(j, 2) and !isContainAdd(j, 2)) a[i][j] = '+';
		}
	}
	print();
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}