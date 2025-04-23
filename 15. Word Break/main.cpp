// https://www.youtube.com/watch?v=_xX2k8Yel38&list=PL_z_8CaSLPWdbOTog8Jxk9XOjzUs3egMP&index=15&pp=iAQB


/*

Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary

*/


// https://www.geeksforgeeks.org/problems/word-break-part-23249/1

#include "bits/stdc++.h"
// #define int long long
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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

set<string> st;
vector<vector<string>> ans;
bool flag = true;

bool check(string &s) {
    return st.count(s);
}

void wordBreak(int start, int n, string& s, vector<string>& partition) {
    if(start == n) {
        ans.push_back(partition);
        return;
    }

    for(int ind = start; ind < n; ind++) {
        string str = s.substr(start, ind - start + 1);
        if(check(str)) {
            partition.push_back(str);
            wordBreak(ind + 1, n, s, partition);
            partition.pop_back();
        }else {
            flag = false;
        }
    }
    return;
}

void solve(){
    string s = "catsanddog";
    int n = s.length();
    vector<string> dict = {"cats", "cat", "sand", "and", "dog"};
    vector<string> partition;

    // do word partitioning, just the check function changes here
    for(auto &str: dict) st.insert(str);

    wordBreak(0, n, s, partition);
    if(!flag) cout << "FALSE" << endl;
    else cout << "FALSE" << endl;
    cout << ans.size() << endl;
    for(auto &part: ans) {
        for(string &word : part) cout << word << " ";
        nl;
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
