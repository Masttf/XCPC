#include<bits/stdc++.h>
using namespace std;
string res[25];
bool cmp(string x,string y){
	return x+y>y+x;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	sort(res+1,res+1+n,cmp);
	for(auto i=1;i<=n;i++){
		cout<<res[i];
	}
	return 0;
}
