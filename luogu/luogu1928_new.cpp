#include<iostream>
#include<stack>
using namespace std;
string jieya(string s);
int main(){
	string s;
	cin>>s;
	int count=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='[')
			count++;
	}
	while(count!=0)
	{
		int left=0;
		int right=0;
		while(s[right]!=']'){
			if(s[right]=='[')
				left=right;
			right++;
		}
		count--;
		s.replace(left,right-left+1,jieya(s.substr(left,right-left+1)));
	}
	cout<<s;
	return 0;
}
string jieya(string s){
	string answer;
	string temp;
	string temp2;
	int count=0;
	for(int i=1;i<s.size()-1;i++){
		temp+=s[i];
	}
	if(temp[1]>='0'&&temp[1]<='9')
	{	
		count+=(temp[0]-'0')*10;
		count+=temp[1]-'0';
		temp2=temp.substr(2);
	}
	else{
		count+=temp[0]-'0';
		temp2=temp.substr(1);
	}
	while(count--){
		answer+=temp2;
	}
	return answer;
}
