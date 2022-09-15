// https://practice.geeksforgeeks.org/problems/power-of-2-and-subsequences0759/1

class Solution{   
public:
    
    // this will check if the number is a power of two or not
    // bit manipulation
    bool isPower2 (long long n){
        
        if (n == 1) return true;
        if (n == 0) return false;
        if (n & (n - 1)) return false;
        return true;
    }

    long long numberOfSubsequences(int N, long long A[]){
        
        // count will have total elements in A which are in power of two
        long long count = 0;
        for (int i = 0; i < N; i++){
            if (isPower2(A[i])) 
                count++;
        }
        
        // compute ans = 2^count - 1; this is the no. of subseq which can be formed by count elements
        long long ans = 1;
        // naive approach to find power, better approach can be used
        while (count--){
            ans = (ans * 2) % 1000000007;
        }
        return ans - 1;
    }
};
