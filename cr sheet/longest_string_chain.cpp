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
bool cmp(string& s1,string& s2){
	return s1.size()<s2.size();
}
bool compare(string s1,string s2){
	if(s1.size()+1!=s2.size())return false;
	int first=0;
	int second=0;
	while(first<s2.size()){
		if(second<s1.size()&&s1[second]==s2[first]){
			first++;
			second++;
		}
		else{
			first++;
		}
	}
	if(second==s1.size())return true;
	return false;
}
void longest_string_chain(vector<string>& v,int n){
	sort(v.begin(),v.end(),cmp);
	vector<int> hash(n);
	for(int i=0;i<n;i++){
		hash[i]=i;
	}
	vector<int> dp(n,1);
	int maxi=1;
	int last_ind=-1;
	for(int ind=0;ind<n;ind++){
		for(int prev=0;prev<ind;prev++){
			if(compare(v[prev],v[ind])&&dp[ind]<dp[prev]+1){
				dp[ind]=dp[prev]+1;
				hash[ind]=prev;
			}
		}
		if(dp[ind]>maxi){
			maxi=dp[ind];
			last_ind=ind;
		}
	}
	cout<<maxi<<endl;
	vector<string> temp;
	temp.push_back(v[last_ind]);
	while(hash[last_ind]!=last_ind){
		last_ind=hash[last_ind];
		temp.push_back(v[last_ind]);
	}
	reverse(temp.begin(),temp.end());
	for(auto &x:temp){
		cout<<x<<" ";
	}
	cout<<endl;
}
void solve(){
	int n;
	cin>>n;
	vector<string> values(n);
	// getline(cin);
	cin.ignore(1,'\n');
	for(int i=0;i<n;i++){
		
		getline(cin,values[i]);
	}
	longest_string_chain(values,n);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}