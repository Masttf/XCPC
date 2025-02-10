#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	int sum=0;
	int cnt=1;
	for(int i=0;i<len-1;i++){
		if(s[i]!='-'){
			sum+=(s[i]-'0')*cnt;
			cnt++;
		}
	}
	int ans=sum%11;
	string res;
	if(ans==10)
		res="X";
	else
		res=to_string(ans);
	if(res[0]==s[len-1])
		cout<<"Right";
	else
	{
		s.erase(len-1);
		cout<<s<<res;
	}
	return 0;
}
