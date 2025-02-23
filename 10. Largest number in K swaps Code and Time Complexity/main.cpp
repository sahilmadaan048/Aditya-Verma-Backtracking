/*

we will discuss the time complexity iof the code here



the process we used is called horixontak drifting

*/

// correction the max element we need to find is 

// if we dont want to keepo the maxstr variable to keep record of the current max



#include <bits/stdc++.h>
using namespace std;

void generateGreatestAfterKSwaps(string& s, int n, int k, int start, string& maxStr) {
    // Base condition: If no swaps left or we have reached the last character
    if (k == 0 || start == n - 1) {
        return;
    }

    // Find the maximum character from the remaining substring (for pruning)
    char maxChar = *max_element(s.begin() + start, s.end());

    // If the current character is already the maximum, no need to swap
    if (s[start] == maxChar) {
        generateGreatestAfterKSwaps(s, n, k, start + 1, maxStr);
        return;
    }

    // Try swapping with larger characters ahead
    for (int i = start + 1; i < n; i++) {
        if (s[i] == maxChar) { // Swap only with maxChar to optimize
            swap(s[i], s[start]); // Swap to form a larger number
            if (s > maxStr) {
                maxStr = s; // Update max string if a larger one is found
            }
            generateGreatestAfterKSwaps(s, n, k - 1, start + 1, maxStr); // Recur with k-1 swaps
            swap(s[i], s[start]); // Backtrack
        }
    }
}

void solve() {
    string s = "1234567";
    int k = 4;
    string maxStr = s;
    int n = s.size();
    
    generateGreatestAfterKSwaps(s, n, k, 0, maxStr);
    cout << maxStr << endl;
}

int main() {
    solve();
    return 0;
}



/*

char max = *max_element(str.begin()+start,str.end())


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
                generateGreatestAfterKSwaps(s, n, k - 1, start + 1, maxStr); // Recur with k-1 swaps
                swap(s[i], s[start]); // Backtrack
            }
            generateGreatestAfterKSwaps(s, n, k , start + 1, maxStr); // Recur with k-1 swaps
        }
    }


    here we do not make a unordered set to eliminate the duplicated recursive tree sinnve

    even if in case of duplicate characters like in  1 2 4 4  only the leaf nodes of both the recursive tree will have same values
    
    but there is no gurantee that we will be able to reach the leaf node, since it 

    depends on the value of k given n the problem, hemce no such extra steps are needed 

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


*/