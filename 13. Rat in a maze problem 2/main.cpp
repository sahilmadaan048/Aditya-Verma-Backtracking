// https://www.youtube.com/watch?v=4Wc_QCxr_WQ&list=PL_z_8CaSLPWdbOTog8Jxk9XOjzUs3egMP&index=13&pp=iAQB

/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR

*/

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

int dx[4]  = {1, 0, 0, -1};  // D, R, L, U
int dy[4]  = {0, 1, -1, 0};
char dir[4] = {'D', 'R', 'L', 'U'};

bool checkInBounds(int i, int j, int n, int m){
    return i>=0 and i<n and j>=0 and j<m;
}

void ratInAMaze(string& s, vector<string>& ans, int n, int m, int startx, int starty, vector<string>& maze, vector<vector<bool>> &vis) {
    vis[startx][starty] = true;
    if(maze[startx][starty] == '0') {
        return;
    }

    //base case is also that if the startx == n-1 and starty == m-1
    //we should just p[ut the modified  path string into the ans]
    if(startx == n-1 and starty == m-1) {
        ans.push_back(s);
        vis[startx][starty] = false;  //ye kaam kharab kar raha tha 
        return;
    }

    //lets do the actual work now
    //for every node, there would be 4 choices of neighbprs
    for(int i=0; i<4; i++) {
        int nx = startx + dx[i];
        int ny = starty + dy[i];

        //check bounds for the neighbor
        if(checkInBounds(nx, ny, n, m) and maze[nx][ny] == '1' and !vis[nx][ny]) {
            // now 4 cases -> D, R, L, U
            s.push_back(dir[i]);
            ratInAMaze(s, ans, n, m, nx, ny, maze, vis);
            s.pop_back();    
        } 
    }
    vis[startx][starty] = false;
}   

void solve(){
    vector<string> mat = {"1000", "1101", "1100", "0111"};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<string> ans;
    string s = "";

    if (mat[0][0] == '1')  // must check if starting point is valid
        ratInAMaze(s, ans, n, m, 0, 0, mat, vis);
    
    srt(ans);  // as required, to print paths in sorted order
    cout << ans.size() << endl;
    for(auto str: ans) cout << str << endl;
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
    TC => no of nodes * tc of each node
    no of nodes, at every node => 2 choices, either right or down
    4^(n*m)
    also tc of each node => o(1)

*/