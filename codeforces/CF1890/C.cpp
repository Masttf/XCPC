#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')cnt--;
		else cnt++;
	}
	if(cnt!=0){
		cout<<"-1\n";
		return ;
	}
	int ok=1;
	for(int i=1;i<=n/2;i++){
		if(s[i]==s[n-i+1])ok=0;
	}
	if(ok){
		cout<<"0\n";
		return ;
	}
	
	
	
	vector<int>ans;
	for(int k=1;k<=301;k++){
		int ok=1;
		int p=-1;
		for(int i=1;i<=n;i++){
			if(s[i]==s[n-i+1]){
				ok=0,p=i;
				break;
			}
		}
		if(ok)break;
		//cout<<p<<endl;

		if(s[p]=='1'){
			//cout<<"1"<<' '<<s[p]<<endl;
			ans.push_back(p-1);
			//cout<<"y1 "<<p-1<<endl;
			string temp=" ";
			for(int i=1;i<=n;i++){
				if(i==p)temp+="01";
				temp+=s[i];
			}
			s=temp;
			n+=2;
		}else{
			ans.push_back(n-p+1);
			//cout<<"y2 "<<n-p+1<<'\n';
			string temp=" ";
			for(int i=1;i<=n;i++){
				temp+=s[i];
				if(i==n-p+1)temp+="01";
			}
			s=temp;
			n+=2;
		}
		//cout<<s<<endl;
	}
	if(ans.size()>300)cout<<-1<<'\n';
	else{
		cout<<ans.size()<<'\n';
		for(auto x:ans)cout<<x<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}