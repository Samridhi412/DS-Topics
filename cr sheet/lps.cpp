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
int lps(string s){
	int maxlen=1;
	int start=0;
	int n=s.size();
	int** dp=new int*[n];
	for(int i=0;i<n;i++){
		dp[i]=new int[n];
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
	int index=-1;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			if(index==-1){
			maxlen=2;
			start=i;
			index=i;
		}
			dp[i][i+1]=1;
		}
	}
	index=-1;
	for(int i=3;i<=n;i++){
		int index=-1;
		for(int j=0;j<=n-i;j++){
			int k=j+i-1;
			if(s[j]==s[k]&&dp[j+1][k-1]==1){
				if(index==-1){
				maxlen=i;
				start=j;
				index=j;
			}
				dp[j][k]=1;
			}
		}
	}
	cout<<s.substr(start,maxlen)<<endl;
	return maxlen;
}
int lcs(string s,string t){
	int n=s.size();
	int m=t.size();
	int** ans=new int*[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=new int[m+1];
		for(int j=0;j<=m;j++){
			ans[i][j]=-1;
		}
	}
	for(int i=0;i<=m;i++){
		ans[0][i]=0;
	}
	for(int j=0;j<=n;j++){
		ans[j][0]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				ans[i][j]=1+ans[i-1][j-1];
			}
			else{
				ans[i][j]=max(ans[i-1][j-1],max(ans[i-1][j],ans[i][j-1]));
			}
		}
	}
	int i=n,j=m;
	while(i>0&&j>0){
		if(s[i-1]==t[j-1]){
			cout<<s[i-1];
			i--;
			j--;
		}
		else{
			if(ans[i][j]==ans[i-1][j]){
				i--;
			}
			else if(ans[i][j]==ans[i][j-1]){
				j--;
			}
			else{
				i--;
				j--;
			}
			
		}
	}
	cout<<endl;
	return ans[n][m];
}
int lcs1(string s,string t){
	int n=s.size();
	int m=t.size();
	int** ans=new int*[n+1];
	for(int i=0;i<=n;i++){
		ans[i]=new int[m+1];
		for(int j=0;j<=m;j++){
			ans[i][j]=0;
		}
	}
	for(int i=0;i<=m;i++){
		ans[0][i]=0;
	}
	for(int i=0;i<=n;i++){
		ans[i][0]=0;
	}
	int maxlen=1;
	int u,v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				ans[i][j]=1+ans[i-1][j-1];
				// maxlen=max(maxlen,ans[i][j]);
				if(ans[i][j]>maxlen){
				u=i;
				v=j;
				maxlen=ans[i][j];
			}
			}
		}
	}
	int x=u,y=v;
	while(x>0&&y>0&&ans[x][y]!=0){
		cout<<s[x-1];
		x--;
		y--;
	}
	cout<<endl;
	return maxlen;
}
void solve(){
	string text;
	cin>>text;
	string prev=text;
	reverse(text.begin(),text.end());
	cout<<lcs1(prev,text)<<endl;
	cout<<lps(text)<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}