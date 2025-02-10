#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=15;
bool vis[30];
int cnt[30];
struct node{
	char fi;
	int se;
}res[maxn];
bool cmp1 (node a,node b){
	if(cnt[a.fi-'a']==cnt[b.fi-'a'])return a.fi<b.fi;
	else return cnt[a.fi-'a']<cnt[b.fi-'a'];
}
bool cmp2(node a,node b){
	return a.se<b.se;
}
void solve(){
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<n;i++)cnt[s[i]-'a']++,vis[s[i]-'a']=1;//首先要让改动的最小那么首先要是质因子
	int ans=1,last=n;
	for(int i=1;i*i<=n;i++){//先找到置换的最小的质因子
		if(n%i==0){
			int cnt1=0,cnt2=0;
			for(int j=0;j<=26;j++){
				if(vis[j]){
					cnt1+=abs(i-cnt[j]);
					cnt2+=abs((n/i)-cnt[j]);
				}
			}
			if(i!=1)cnt1/=2,cnt2/=2;
			if(last>cnt1)ans=i,last=cnt1;
			if(last>cnt2)ans=n/i,last=cnt2;
		}
	}
	int op=0;
	for(int i=1;i<=n;i++)res[i].fi=s[i-1],res[i].se=i;
	sort(res+1,res+1+n,cmp1);
	int pos=n;
	for(int i=n;i>=1;i--){
		char c=res[i].fi;
		if(cnt[c-'a']>ans){
			pos=i-1;
			while(cnt[res[pos].fi-'a']>=ans)pos--;
			if(pos){
				res[i].fi=res[pos].fi;
				op++;
				cnt[c-'a']--;
				cnt[res[pos].fi-'a']++;
			}else{
				int h=0;
				op++;
				while(vis[h])h++;
				res[i].fi=h+'a';
				cnt[c-'a']--;
				cnt[h]++;
				vis[h]=1;
			}
			
		}
		else {
			pos=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[res[i].fi-'a']==ans)break;
		while(cnt[res[pos].fi-'a']>=ans)pos--;
		cnt[res[i].fi-'a']--;
		res[i].fi=res[pos].fi;
		cnt[res[pos].fi-'a']++;
		op++;
	}
	sort(res+1,res+1+n,cmp2);
	cout<<op<<'\n';
	for(int i=1;i<=n;i++)cout<<res[i].fi;
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
