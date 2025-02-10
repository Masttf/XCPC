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
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]%=2;
	}
	vector<int>temp;
	for(int i=0;i<n;i++)temp.push_back(a[i]);
	int nw=1;
	while(1){
		if(temp.empty())break;
		if(temp.size()==1){
			nw++;
			break;
		}
		int sz=temp.size();
		int ok=0;
		vector<int>res;
		for(int i=0;i<sz;i++){
			if(temp[i]==temp[(i+1)%sz]){
				for(int j=0;j<sz;j++){
					if(j==i)continue;
					res.push_back(temp[j]);
				}
				temp=res;
				nw++;
				ok=1;
				break;
			}
		}
		// for(auto x:temp)cout<<x<<' ';
		// cout<<'\n';
		if(!ok)break;
	}
	if(nw%2==1)cout<<"zn\n";
	else cout<<"qcjj\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}