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
void solve(){
    vector<string> a(4);
    for(int i = 1; i <= 3; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    vector<int> cnt(4);
    vector vis(5, vector<int>(5));
    // 下三子的要两个交叉
    int ok, need;
    for(int i = 1; i <= 3; i++){
    	ok = 1;
    	need = 3;
    	for(int j = 1; j <= 3; j++){
    		if(a[i][j] == 'O')ok = 0;
    		else if(a[i][j] == 'X')need--;
    	}
    	if(ok)cnt[need]++;
    	if(ok && need == 3){
    		for(int j = 1; j <= 3; j++){
				vis[i][j]++;
			}
    	}
    	ok = 1;
    	need = 3;
    	for(int j = 1; j <= 3; j++){
    		if(a[j][i] == 'O')ok = 0;
    		else if(a[j][i] == 'X')need--;
    	}
    	if(ok)cnt[need]++;
    	if(ok && need == 3){
    		for(int j = 1; j <= 3; j++){
				vis[j][i]++;
			}
    	}
    }
    ok = 1;
    need = 3;
    for(int i = 1; i <= 3; i++){
    	if(a[i][i] == 'O')ok = 0;
    	else if(a[i][i] == 'X')need--;
    }
    if(ok)cnt[need]++;
    if(ok && need == 3){
    	for(int i = 1; i <= 3; i++){
    		vis[i][i]++;
    	}
    }
    ok = 1;
    need = 3;
    for(int i = 1; i <= 3; i++){
    	if(a[i][4 - i] == 'O')ok = 0;
    	else if(a[i][4 - i] == 'X')need--;
    }
    if(ok)cnt[need]++;
    if(ok && need == 3){
    	for(int i = 1; i <= 3; i++){
    		vis[i][4 - i]++;
    	}
    }
    for(int i = 0; i <= 2; i++){
    	if(cnt[i]){
    		cout << "Yes\n";
    		return ;
    	}
    }
    for(int i = 1; i <= 3; i++){
    	for(int j = 1; j <= 3; j++){
    		if(vis[i][j] >= 2){
    			cout << "Yes\n";
    			return ;
    		}
    	}
    }
    cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
第一次走两步能赢就直接赢？
如果全空呢？
肯定是小L赢
也就是说要么直接下两个子
要么小一个子有至少两条可以连成3个子的
*/