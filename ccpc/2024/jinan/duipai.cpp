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
    do{
        system("ge.exe > ge.txt");
        system("i.exe < ge.txt > wa.txt");
        system("bf.exe < ge.txt > ac.txt");
    }while(!system("fc wa.txt ac.txt"));
	
    // system("ii.exe < ge.txt > wa.txt");
    // system("i.exe < ge.txt > wa.txt");
    // system("fc wa.txt ac.txt");
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}