// https://www.youtube.com/watch?v=UYF5Lzp9jH8&list=PL_z_8CaSLPWdbOTog8Jxk9XOjzUs3egMP&index=18


/*

The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number.

Examples :

Input: 1
Output: [1]
Explaination: Only one queen can be placed 
in the single cell available.
Input: 4
Output: [2 4 1 3 ] [3 1 4 2 ]
Explaination: These are the 2 possible solutions.

*/

// https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

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

const int n = 4; 
vector<vector<int>> ans;
vector<vector<int>> board(n, vector<int>(5));

bool checker(int r, int c) {
    //chek column
    for(int i=0; i<r; i++) {
        if(board[i][c]) return false;
    }
    //check upper left diagobal
    for(int i=r-1, j=c-1; i>=0 and j>=0; i--,j--) {
        if(board[i][j] == 1) return false;
    }
    //check for upper left diagonal
    for(int i=r-1, j=c+1; i>=0 and j<n; i--,j++) {
        if(board[i][j] == 1) return false;
    }
    return true;
}

void NQueens(int row, vector<int>& temp) {
    //base case
    if(row == n) {
        ans.push_back(temp);
        return;
    }

    //trvaerse through all these columns
    for(int c = 0; c<n; c++) {
        if(checker(row, c)) {
            board[row][c] = 1;
            temp.push_back(c+1);
            NQueens(row+1, temp);
            temp.pop_back(); //backtrack
            board[row][c] = 0; //backtrack
        }
    }
}

void solve(){
    int n = 5;
    vector<int> temp;
    NQueens(0, temp);
    cout << ans.size() << endl;
    for(auto vec: ans) cout << vec << endl;
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

/*

we will do the column by column traversal


*/