#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;cin>>s;
	string res="^";
	int len=s.size();
	for(int i=0;i<len;i++){
		res+="#";
		res+=s[i];
	}
	res+="#&";
	int n=res.size();
	vector<int>p(n);
	int c=0,r=0;
	for(int i=1;i<n-1;i++){
		int i_mirro=2*c-i;
		if(i<r){
			p[i]=min(r-i,p[i_mirro]);
		}else p[i]=0;
		while(res[i+p[i]+1]==res[i-p[i]-1])p[i]++;
		if(i+p[i]>r){
			c=i;
			r=i+p[i];
		}
	}
	int maxlen=0;
	int posi=0;
	for(int i=1;i<n-1;i++){
		if(p[i]>maxlen){
			maxlen=p[i];
			posi=i;
		}
	}
	int start=(posi-maxlen)/2;
	cout<<s.substr(start,start+maxlen);
	return 0;
}
