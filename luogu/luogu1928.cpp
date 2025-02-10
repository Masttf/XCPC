#include<iostream>
#include<stack>
using namespace std;
string jieya(string s,int m);
int main(){
	string s;
	cin>>s;
	cout<<jieya(s,0);
	return 0;
}
//定义输入字符串和[的开始位置返回解压后的正确字符串
string jieya(string s,int m){
	int start=m+1;
	string answer;
	string temp;
	string temp2;
	for(int i=start;i<s.size();i++){
		if(s[i]=='['){
			int h=i;
			while(s[h]!=']'){
				h++;
			}
			s.replace(i,h-i+1,jieya(s,i));
		}
	}
	while(s[start]!=']'){
		temp+=s[start];
		start++;
	}
	int count=temp[0]-'0';
	temp2=temp.substr(1);
	while(count--){
		answer+=temp2;
	}
	return answer;
}
