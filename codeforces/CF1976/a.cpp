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
    int n;cin>>n;
    string s;cin>>s;
    int ok=1;
    for(int i=0;i<n;i++){
    	if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')))ok=0;
    	else{
    		if(s[i]>='a'&&s[i]<='z'){
    			if(i!=n-1){
    				if(s[i+1]>='a'&&s[i+1]<='z')continue;
    				else ok=0;
    			}
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	if(s[i]>='a'&&s[i]<='z'){
    		for(int j=0;j<i;j++){
    			if(s[j]>='a'&&s[j]<='z'){
    				if(s[j]>s[i])ok=0;
    			}
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		for(int j=0;j<i;j++){
    			if(s[j]>='0'&&s[j]<='9'){
    				if(s[j]>s[i])ok=0;
    			}
    		}
    	}
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}