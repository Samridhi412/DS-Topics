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
void solve(){
	string s,alpha;
	getline(cin,s);
	getline(cin,alpha);
	int k;
	cin>>k;
	int n=s.size();
	map<char,int> mp;
	for(int i=0;i<alpha.size();i++){
		// cout<<alpha[i]<<" ";
		mp[97+i]=alpha[i]-48;
	}
	map<string,int> mpp;
	int** dp=new int*[n];
	for(int i=0;i<n;i++){
		dp[i]=new int[n];
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		if(mp[s[i]]==0){
			dp[i][i]=1;
		}
		if(dp[i][i]<=k){
				mpp[s.substr(i,1)]++;
			}
	}
	for(int i=0;i<n-1;i++){
		dp[i][i+1]=(mp[s[i]]==0)+(mp[s[i+1]]==0);
		if(dp[i][i+1]<=k){
			mpp[s.substr(i,2)]++;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int q=j+i-1;
			dp[j][q]=dp[j+1][q-1]+(mp[s[j]]==0)+(mp[s[q]]==0);
			if(dp[j][q]<=k){
				mpp[s.substr(j,i)]++;
			}
		}
	}
	cout<<mpp.size();
	// for(auto &x:mpp){
	// 	cout<<x.first<<" ";
	// }
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	// cout<<endl;
	// }
	// cout<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}