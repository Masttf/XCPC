#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int pt[20];
void init(){
	pt[0]=1;
	for(int i=1;i<=17;i++)pt[i]=pt[i-1]*10;
	return ;
}
int toint(string a,int l,int r){
	int res=0;
	for(int i=l;i<=r;i++){
		res=res*10+a[i]-'0';
	}
	return res;
}
int js(int xx){
	string res=to_string(xx);
	int ans=0;
	int f=0;
	if(s[0]=='0')f=1;
	int len1=s.size(),len2=res.size();
	int x=toint(s,0,len1-1);
	for(int i=len1-1;i<len2;i++){
		int temp=toint(res,i-len1+1,i);
		int l=toint(res,0,i-len1);
		int r=toint(res,i+1,len2-1);
		if(x<temp){// 从0到l都可以选,然后右边每位0-9
			ans+=(l+1-f)*pt[len2-i-1];
		}else if(x==temp){//0到l-1,然后加上最大位为l
			ans+=(l-f)*pt[len2-i-1]+r+1;
		}else ans+=(l-f)*pt[len2-i-1];
	}
	return ans;
}
void solve(){
	cin>>s;
	int l,r;cin>>l>>r;
	int ans=js(r)-js(l-1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
