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
constexpr bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
constexpr int findPrime(int n) {
    while (!isprime(n)) n++;
    return n;
}
int MOD_1,MOD_2;
int base_1 = 131; 
int base_2 = 231;
void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	vector<int>p(n+10),p2(n+10);
	vector<int>f(n+10),f2(n+10);
	vector<int>f3(n+10),f4(n+10);
	f[0]=f2[0]=p[0]=p2[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=(f[i-1]*base_1+s[i]-'a')%MOD_1;
		f2[i]=(f2[i-1]*base_2+s[i]-'a')%MOD_2;
		p[i]=p[i-1]*base_1%MOD_1;
		p2[i]=p2[i-1]*base_2%MOD_2;
	}
	f3[n+1]=f4[n+1]=1;
	for(int i=n;i>=1;i--){
		f3[i]=(f3[i+1]*base_1+s[i]-'a')%MOD_1;
		f4[i]=(f4[i+1]*base_2+s[i]-'a')%MOD_2;
	}
	auto get = [&](int t,int l,int r)->pair<int,int>{
		if(t==1){
			int d1=(f[r]-f[l-1]*p[r-l+1]%MOD_1)%MOD_1;
			int d2=(f2[r]-f2[l-1]*p2[r-l+1]%MOD_2)%MOD_2;
			return {d1,d2};
		}else{
			int d1=(f3[l]-f3[r+1]*p[r-l+1]%MOD_1)%MOD_1;
			int d2=(f4[l]-f4[r+1]*p2[r-l+1]%MOD_2)%MOD_2;
			return {d1,d2};
		}
	};
	vector pre(30,vector<int>(n+1));
	vector pre2(30,vector<int>(n+1));
	vector pre3(30,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			pre[j][i]=pre[j][i-1];
			pre2[j][i]=pre2[j][i-1];
			pre3[j][i]=pre3[j][i-1];
		}
		pre[s[i]-'a'][i]++;
		if(i%2==1)pre3[s[i]-'a'][i]++;
		else pre2[s[i]-'a'][i]++;
	}
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		int ok=0;
		int ok1=0,ok2=0;
		int dd=((r-l+1)+1)/2;
		int len1=0,len2=0;
		if(l%2==1)len1=dd,len2=r-l+1-dd;
		else len1=r-l+1-dd,len2=dd;
		for(int j=0;j<26;j++){
			if(pre[j][r]-pre[j][l-1]==r-l+1)ok=1;
			if(pre2[j][r]-pre2[j][l-1]==len2)ok1=1;
			if(pre3[j][r]-pre3[j][l-1]==len1)ok2=1;
		}
		if(ok){
			cout<<0<<'\n';
		}else if(ok1&&ok2){
			//dbg("das");
			int len=r-l+1;
			len-=len%2;
			int ans=(len+2)*(len/2)/2;
			cout<<ans<<'\n';
		}else{
			int len=r-l+1;
			if(get(1,l,r)==get(2,l,r))len--;
			int ans=(len+2)*(len-1)/2;
			cout<<ans<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::mt19937 rnd(time(0));
    MOD_1 = findPrime(rnd() % 900000000 + 100000000);
    MOD_2 = findPrime(rnd() % 900000000 + 100000000);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}