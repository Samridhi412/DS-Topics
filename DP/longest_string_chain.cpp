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
#define mp make_pair
#define pb push_back
#define endl "\n"
bool cmp(string s1,string s2){
	return s1.size()<s2.size();
}
bool compare(string& s1,string& s2){
	if(s1.size()!=s2.size()+1)return false;
	int ptr1=0;
	int ptr2=0;
	while(ptr1<s1.size()){
		if(s1[ptr1]==s2[ptr2]){
			ptr1++;
			ptr2++;
		}
		else {
			ptr1++;
		}
	}
	if(ptr1==s1.size()&&ptr2==s2.size())return true;
	return false;
}
void lsc(vector<string>& vect){
	int n=vect.size();
	vector<int> dp(n),hash(n);
	int lastindex=-1;
	int maxi=-1;
	for(int i=0;i<n;i++){
		hash[i]=i;
		for(int prev=0;prev<i;prev++){
			if(compare(vect[i],vect[prev])&&dp[i]<dp[prev]+1){
				dp[i]=dp[prev]+1;
				hash[i]=prev;
			}
		}
		if(dp[i]>maxi){
			maxi=dp[i];
			lastindex=i;
		}
	}
	cout<<maxi;
	vector<string> temp;
	while(lastindex!=hash[lastindex]){
		temp.push_back(vect[lastindex]);
		lastindex=hash[lastindex];
	}
	for(auto x:temp){
		cout<<x<<" ";
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin>>m;
	vector<string> vect(m);
	for(int i=0;i<m;i++){
		cin>>vect[i];
	}
	sort(vect.begin(),vect.end(),cmp);
	lsc(vect);
	return 0;
}