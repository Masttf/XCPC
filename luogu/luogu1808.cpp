#include<bits/stdc++.h>
using namespace std;
string s;
vector<string>res;
bool cmp(string x,string y){
	return x<y;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		sort(s.begin(),s.end());
		res.push_back(s);
	}
	sort(res.begin(),res.end(),cmp);
	int fast=0;
	int slow=0;
	while(fast<n){
		if(res[fast]!=res[slow]){
			slow++;
			res[slow]=res[fast];
		}
		fast++;
	}
	cout<<slow+1;
	return 0;
}
