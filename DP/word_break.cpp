#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
// #define mp make_pair
#define pb push_back
#define endl "\n"
unordered_map<string,bool> mp;
unordered_set<string> vect;
bool word_break(string s,unordered_set<string>& st){
	if(s.empty())return true;
	else if(mp.count(s))return mp[s];
	for(int i=0;i<s.size();i++){
		if(st.count(s.substr(0,i+1))){
			 if(word_break(s.substr(i+1),st)){
			 	return mp[s]=true;
			 }
		}
	}
	return mp[s]=false;
}
void word_breakII(string s,string res,vector<string>& v){
	if(s.empty()){
		res.pop_back();
		v.push_back(res);
		return;
	}
	for(int i=0;i<s.size();i++){
		string prefix=s.substr(0,i+1);
		if(vect.count(prefix)){
			res=res+prefix+" ";
			word_breakII(s.substr(i+1),res,v);
		}
	}
	return;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin.ignore();
	getline(cin,str);
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		vect.insert(s);
	}
	mp.clear();
	vect.clear();
	word_break(str,vect);
	return 0;
}