//rolling hash calculates hash value

#include<bits/stdc++.h>
using namespace std;
#define d 256
#define q INT_MAX
int createhash(string& s,int start,int end){
	int hash=0;
	for(int i=start;i<=end;i++){
		hash+=(s[i]-'a'+1)*pow(q,i);
	}
	return hash;
}
bool checkequal(string& text,string& pat,int start1,int end1,int start2,int end2){
	if(end1-start1!=end2-start2){
		return 0;
	}
	while(start1<=end1&&start2<=end2){
		if(text[start1]!=pat[start2]){
			return 0;
		}
		start1++;
		start2++;
	}
	return 1;
}
int recalculate(int oldhash,int previndex,int newindex,string& text,int m){
	int newhash=oldhash-(text[previndex]-'a'+1);
	newhash=newhash/q;
	newhash=newhash+pow(q,m-1)*(text[newindex]-'a'+1);
	return newhash;
}
void rabinkarp(string& txt,string& pat){
	int n=txt.size();
	int m=pat.size();
int t=createhash(txt,0,m-1);
int p=createhash(pat,0,m-1);
for(int i=0;i<=n-m;i++){
	if(t==p){
	   if(checkequal(txt,pat,i,i+m-1,0,m-1)){
	   	cout<<"pattern found at index"<<i<<endl;
	   }
	   	
	}
	if(i<n-m){
		t=recalculate(t,i,i+m-1,txt,m);
	}
}
}


void rabinkarp2(string& text,string& pat){
	int n=text.size();
	int m=pat.size();
	int h=1;
	int t=0,p=0;
	for(int i=0;i<m-1;i++){
		h=(h*d)%q;
	}
	for(int i=0;i<m;i++){
		t=(t*d+text[i])%q;
		p=(p*d+pat[i])%q;
	}
	for(int i=0;i<=n-m;i++){
		if(t==p){
			int j;
			for(j=0;j<m;j++){
				if(text[i+j]!=pat[j]){
					break;
				}
			}
			if(j==m){
				cout<<"pattern found at index"<<i<<endl;
			}
		}
		if(i<n-m){
			t=(d*(t-text[i]*h)+text[i+m])%q;
			if(t<0)t=t+q;
		}
	}
}
int main(){
	string text,pat;
	getline(cin,text);
	getline(cin,pat);
	rabinkarp(text,pat);
	rabinkarp2(text,pat);
	return 0;
}