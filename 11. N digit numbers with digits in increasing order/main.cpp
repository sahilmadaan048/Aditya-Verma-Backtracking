// https://www.youtube.com/watch?v=xlKrk3ZO3iM&list=PL_z_8CaSLPWdbOTog8Jxk9XOjzUs3egMP&index=12

/*

Input:
N = 1
Output:
0 1 2 3 4 5 6 7 8 9
Explanation:
Single digit numbers are considered to be 
strictly increasing order.


*/

#include "bits/stdc++.h"
#define ll long long
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

//lets use a vector
void solve(int n, vector<int>& temp, vector<int>& res) {
    if(n == 0) {
        //push the number in temp vector to the res vector
        int num = 0;
        for(int i=0; i<temp.size(); i++) {
            num = num*10 + temp[i];
        }
        res.push_back(num);
        return;
    }

    //now we have to do some backltracking for all the elements
    int sz = temp.size();
    //agar vector ka size 0 hai fark hi nahi padta kuch bhi daldo 
    for(int i=1; i<=9; i++) {
        if(sz == 0 or  i > temp[sz-1]) {
            temp.push_back(i);
            //now backltrack
            solve(n-1, temp, res);
            temp.pop_back();
        } 
    }
    return;
}

vector<int> increasingArray(int n){
    vector<int> ans;
    if(n == 1) {
        for(int i=0; i<=9; i++) ans.push_back(i);
        return ans;
    }
    vector<int> temp;
    solve(n, temp, ans);
    return ans;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vector<int> ans = increasingArray(n);        
        for(auto num: ans) cout << num << endl;
    }
    return 0;
}


/*

TC => choices 1 to 9 for each digit => 9^noofdigits = 9^n
    no of nodes = 9^n
    tc of each node = o(10) = o(1)

*/