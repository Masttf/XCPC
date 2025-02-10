#include<bits/stdc++.h>
#define int long long
using namespace std;
int k=22183;
int kk=0;
void solve(){
	string s1,s2;cin>>s1>>s2;
	int len=s1.size();
	s1=" "+s1;
	s2=" "+s2;
	int t,q;cin>>t>>q;
	queue<pair<int,int>>p;
	int cnt=0;
	for(int i=1;i<=len;i++){
		if(s1[i]!=s2[i])cnt++;
	}
	for(int i=1;i<=q;i++){
		int ty;cin>>ty;
		if(!p.empty()&&p.front().second==i){
			int rt=p.front().first;p.pop();
			if(s1[rt]!=s2[rt])cnt++;
		}
		if(ty==1){
			int x;cin>>x;
			p.push({x,i+t});
			if(s1[x]!=s2[x])cnt--;
		}else if(ty==2){
			int t1,p1,t2,p2;cin>>t1>>p1>>t2>>p2;
			int c1=0;
			if(s1[p1]!=s2[p1])c1++;
			if(s1[p2]!=s2[p2])c1++;
			if(t1==2&&t2==1)swap(s2[p1],s1[p2]);
			else if(t1==2&&t2==2)swap(s2[p1],s2[p2]);
			else if(t1==1&&t2==1)swap(s1[p1],s1[p2]); //  1 1	
			else swap(s1[p1],s2[p2]);// 1 2
			int c2=0;
			if(s1[p1]!=s2[p1])c2++;
			if(s1[p2]!=s2[p2])c2++;
			cnt+=c2-c1;
		}else{
			kk++;
			if(kk==k){
				cout<<s1<<' '<<s2;
			}
			if(cnt==0)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
