#include<bits/stdc++.h>
#define int long long
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
void solve(){
	vector<string>a(10);
	for(int i = 1; i <= 9; i++){
		cin >> a[i];
		a[i] =' '+a[i];
	}
	int x = -1, y= -1;
	for(int i = 1; i <= 9; i++){
		int ok = 0;
		for(int j = 1; j <= 9; j++){
			if(a[i][j] == '8' && i != 1 && i != 9 && j != 1 && j != 9){
				x =i;
				y =j;
				ok =1;
				break;
			}
		}
		if(ok)break;
	}
	for(int i = 1;i <= 9; i++){
		for(int j = 1; j<= 9; j++){
			if(i==x && j==y)cout<<8;
			else cout << '*';
		}
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}