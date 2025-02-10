#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>m;
int n,q;
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int a,b,c,k=-1;
		cin>>a;
		if(a==1)cin>>b>>c>>k;
		else cin>>b>>c;
		pair<int,int>temp=make_pair(b,c);
		if(k!=-1){
			m[temp]=k;
		}
		else cout<<m[temp]<<'\n';
	}
	return 0;
}
