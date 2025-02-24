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
int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getLimit(int year, int month){
	if(month != 2) return a[month];
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return 29;
	else return 28;
}
void solve(){
    int year = 1901;
    int month = 1;
    int day = 1;
    int now = 1;
    int ans = 0;
    while(year <= 2024){
    	if(now == 0 && day % 10 == 1)ans++;
    	day++;
    	now++;
    	now %= 7;
    	if(day > getLimit(year, month)){
    		day = 1;
    		month++;
    		if(month == 13){
    			month = 1;
    			year++;
    		}
    	}
    	// dbg(year);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}