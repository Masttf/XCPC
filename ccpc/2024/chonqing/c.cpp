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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for(auto x : a){
    	if(x == '#')cnt1++;
    }
    for(auto x : b){
    	if(x == '#')cnt2++;
    }
    if(cnt1 == n && cnt2 == n){
    	cout << "Yes\n";
    	cout << a << '\n';
    	for(int i = 1; i <= 6; i++){
    		cout << b << '\n';
    	}
    	return ;
    }
    if(cnt1 == n || cnt2 == n){
    	cout << "No\n";
    	return ;
    }
    vector<string> ans;
    ans.push_back(a);
    int pa = -1, pb = -1;
    for(int i = 0; i < n; i++){
    	if(a[i] == '#'){
    		if(i && a[i - 1] == '.')pa = i;
    		if(i + 1 < n && a[i + 1] == '.')pa = i;
    	}
    }
    for(int i = 0; i < n; i++){
    	if(b[i] == '#'){
    		if(i && b[i - 1] == '.')pb = i;
    		if(i + 1 < n && b[i + 1] == '.')pb = i;
    	}
    }
    string res = "";
    for(auto x : a){
    	if(x == '#')res += '.';
    	else res += '#';
    }
    ans.push_back(res);
    res = "";
    for(int i = 0; i < n; i++){
    	if(i == pa)res += '#';
    	else res += '.';
    }
    ans.push_back(res);

    string res2 = "";
    for(int i = 0; i < n; i++){
    	if(i == pb)res2 += '#';
    	else res2 += '.';
    }
    if(abs(pa - pb) == 1){
    	ans.push_back(res);
    }else{
    	string res3 = "";
	    for(int i = 0; i < n; i++){
	    	if(res[i] == '.' && res2[i] == '.')res3 += '#';
	    	else res3 += '.';
	    }
	    ans.push_back(res3);
    }
    
    ans.push_back(res2);
    res = "";
    for(auto x : b){
    	if(x == '#')res += '.';
    	else res += '#';
    }
    ans.push_back(res);
    ans.push_back(b);
    cout << "Yes\n";
    for(auto x : ans){
    	cout << x << '\n';
    }
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