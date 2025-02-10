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
	int n;cin>>n;
	map<string,int>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		string temp="";
		for(auto x:s){
			if(x=='-')continue;
			else if(x>='A'&&x<='Z'){
				if(x>='A'&&x<='C')temp+='2';
				else if(x>='D'&&x<='F')temp+='3';
				else if(x>='G'&&x<='I')temp+='4';
				else if(x>='J'&&x<='L')temp+='5';
				else if(x>='M'&&x<='O')temp+='6';
				else if(x>='P'&&x<='S')temp+='7';
				else if(x>='T'&&x<='V')temp+='8';
				else temp+='9';
			}else temp+=x;
		}
		m[temp]++;
	}
	int ok=0;
	vector<pair<string,int>>res;
	for(auto [x,y]:m){
		if(y>1){
			res.push_back({x,y});
		}
	}
	if(res.empty())cout<<"No duplicates.";
	else{
		for(int j=0;j<res.size();j++){
			auto[x,y]=res[j];
			for(int i=0;i<7;i++){
				cout<<x[i];
				if(i==2)cout<<'-';
			}
			cout<<" "<<y;
			if(j!=res.size()-1)cout<<'\n';
		}
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