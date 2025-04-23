/*
Given a String S, Find all possible Palindromic partitions of the given String.
 

Example 1:

Input:
S = "geeks"
Output:
g e e k s
g ee k s
Explanation:
All possible palindromic partitions
are printed.

*/

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

bool check(string& s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void palindromicPartitioning(int start, vector<string>& temp, vector<vector<string>>& ans, string &s, int n){
    if(start == n) {
        ans.push_back(temp);
        return;
    }

    for(int ind = start; ind < n; ind++){
        if(check(s, start, ind)){
            temp.push_back(s.substr(start, ind - start + 1));
            palindromicPartitioning(ind+1, temp, ans, s, n);
            temp.pop_back();
        }
    }
    return;
}

void solve(){
    // string s = "geeks";
    string s = "nitin";
    int sz = s.size();
    vector<vector<string>> ans;
    vector<string> temp;
    palindromicPartitioning(0, temp, ans, s, sz);
    for(auto &partition : ans) {
        cout << partition << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}