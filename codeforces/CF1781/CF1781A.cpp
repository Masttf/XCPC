#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int w,d,h;cin>>w>>d>>h;
	int a,b,f,g;cin>>a>>b>>f>>g;
	int t1=a,t2=b,t3=abs(w-a),t4=abs(d-b);
	int ans1=t1+h+f+abs(g-b);
	int ans2=t2+h+g+abs(f-a);
	int ans3=t3+h+abs(g-b)+abs(w-f);
	int ans4=t4+h+abs(f-a)+abs(g-d);
	cout<<min(ans1,min(ans2,min(ans3,ans4)))<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
