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
bool isprime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int findPrime(int n) {
    while (!isprime(n)) {
        n++;
    }
    return n;
}
const int Max=1e18;
void solve(){
	int n;cin>>n;
	string a,b;cin>>a>>b;
	a=' '+a;
	b=' '+b;
    string ans="";
    int ok=n;
    for(int i=1;i<n;i++){
    	if(a[i+1]=='0')continue;
    	if(b[i]=='1')continue;
    	ok=i;
    	break;
    }
    for(int i=1;i<=ok;i++)ans+=a[i];
    for(int i=ok;i<=n;i++)ans+=b[i];
    cout<<ans<<'\n';
	int cnt=1;
	for(int i=ok;i>=1;i--){
		if(a[i]==b[i-1]){
			cnt++;
		}else break;
	}
    cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}