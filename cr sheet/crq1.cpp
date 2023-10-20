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
bool satisfy(string& str,int len){
	int i=0;
	int j=len-1;
	int n=str.size();
	while(j<n){
		string s=str.substr(i,len);
		// cout<<"/////\n"<<s<<"///\n";
		if(s.find('1')!=string::npos&&s.find('2')!=string::npos&&s.find('3')!=string::npos){
			return true;
		}
		i++;
		j++;
	}
	return false;
}
void solve(){
	string str;
	cin>>str;
	// cout<<str<<endl;
	int low=3;
	int high=str.size();
	int res=0;
	while(low<=high){
		int mid=(low+high)>>1;
		if(satisfy(str,mid)){
			high=mid-1;
			res=mid;
		}
		else{
			low=mid+1;
		}
	}
	cout<< res<<"\n";
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}