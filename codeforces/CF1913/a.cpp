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
	string s;cin>>s;
	string temp="";
	temp+=s[0];
	int n=s.size();
	int p=-1;
	for(int i=1;i<n;i++){
		if(s[i]!='0'){
			p=i;
			break;
		}else temp+='0';
	}
	string res="";
	for(int i=p;i<n;i++)res+=s[i];
	//dbg(temp,res);
	if(p==-1){
		cout<<-1<<'\n';
		return ;
	}
	if(temp.size()>res.size()||(temp.size()==res.size()&&temp>=res)){
		cout<<-1<<'\n';
	}else cout<<temp<<' '<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}