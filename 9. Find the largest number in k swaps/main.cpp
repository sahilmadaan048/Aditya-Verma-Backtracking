/*

Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5

no of swaps ins limited

can be done by backtracking

base condiiton hits in either of the two cases
    either k becomes 0  now we cant do any further swaps
    start node reaches the end of the string



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

void generateGreatestAfterKSwaps(string& s,int n, int k, int start, string& maxStr){

    //base condition
    if(k == 0 || start == n-1) {
        return ;
    }

    //else case we will do swaps for index i=start+1 to n only if the value of s[i]>s[start]

    // Try swapping with larger characters ahead
    for (int i = start + 1; i < n; i++) {
        if (s[i] > s[start]) {
            swap(s[i], s[start]); // Swap to form a larger number
            if (s > maxStr) {
                maxStr = s; // Update max string if a larger one is found
            }
            generateGreatestAfterKSwaps(s, n, k - 1, start + 1, maxStr); // Recur with k-1 swaps
            swap(s[i], s[start]); // Backtrack
        }
    }


    /*
    here we do not make a unordered set to eliminate the duplicated recursive tree sinnve

    even if in case of duplicate characters like in  1 2 4 4  only the leaf nodes of both the recursive tree will have same values
    
    but there is no gurantee that we will be able to reach the leaf node, since it 

    depends on the value of k given n the problem, hemce no such extra steps are needed 
    */
}

void solve(){
    string s = "1234567";
    int k = 4;
    string maxstr = s;
    int start = 0;
    int n = s.size();
    generateGreatestAfterKSwaps(s, n, k, start, maxstr);
    cout<<maxstr<<endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--) 
    {
        solve();
    }
    return 0;
}

    