// https://www.youtube.com/watch?v=VCSmyaEXu_M&list=PL_z_8CaSLPWdbOTog8Jxk9XOjzUs3egMP&index=17

/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []


*/


// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbG9RR0xyaTFWZ2tGdnlpNnpBSjJvYmVNUlFZUXxBQ3Jtc0trYXE2bGxGQllFTkkzbGYzVFc2ZUF2Vk9waVdGaWhockdndmQ3dWdnbDFvMnBlUWxFT1J4TURXZU1mdjRtNk9qQU5jamI5QnZaZVdvWVBRdlJhN0xRQnNUSzRXaE42SzJIanVaZ2NjTThfYmkyME81SQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fletter-combinations-of-a-phone-number%2Fdescription&v=VCSmyaEXu_M

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

unordered_map<char, string> mpp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "xyz"}};

void letterCombinations(int start, string&temp, string&s, vector<string>& ans, int n) {
    if(start == n and temp.size() == n) {
        ans.push_back(temp);
        return;
    }
    //use the map to figure iut all possible strings
    for(int ind = start; ind<n; ind++) {
        //for every ind iterate through the mapped string
        for(auto ch: mpp[s[ind]]) {
            temp += ch;
            letterCombinations(ind+1, temp, s, ans, n);
            temp.erase(temp.end()-1);
        }
    }
    return;
}

void solve(){
    string s = "23";
    int n = s.size();
    string temp = "";
    vector<string> ans;
    letterCombinations(0, temp, s, ans, n);
    cout << ans.size() << endl;
    cout << ans << endl;
    // for(auto str: ans) cout << str << endl;
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