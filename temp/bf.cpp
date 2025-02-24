#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
	system("ge.exe > ge.in");
	system("test.exe < ge.in > test.out");
	system("ans.exe < ge.in > ans.out");
	system("fc test.out ans.out");
    // system("test.exe < match3.in > test.ans");
    // system("fc match3.ans test.ans");
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}