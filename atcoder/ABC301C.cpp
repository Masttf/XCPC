#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1[30],c2[30];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s1,s2;cin>>s1>>s2;
	int sz=s1.size();
	for(int i=0;i<sz;i++){
		if(s1[i]=='@')c1[29]++;
		else c1[s1[i]-'a']++;
		if(s2[i]=='@')c2[29]++;
		else c2[s2[i]-'a']++;
	}
	int d1=c1[29];
	int d2=c2[29];
	int flag=1;
	for(int i=0;i<=26;i++){
		if(c1[i]!=c2[i]){
			if(i=='a'-'a'||i=='t'-'a'||i=='c'-'a'||i=='o'-'a'||i=='d'-'a'||i=='e'-'a'||i=='r'-'a'){
				if(c1[i]>c2[i])d2-=c1[i]-c2[i];
				else d1-=c2[i]-c1[i];
			}else flag=0;
		}
	}
	if(flag&&d1==d2&&d1>=0)cout<<"Yes";
	else cout<<"No";
	return 0;
}
