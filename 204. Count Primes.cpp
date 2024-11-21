## Problem Statement ##
## 204. Count Primes
## https://leetcode.com/problems/count-primes/
## https://www.geeksforgeeks.org/sieve-of-eratosthenes/

############################################### Code begins here ##############################################################

// class Solution {

// public:
//      static const int size = 5000001; // Constant size of the array
//      std::vector<bool> arr;

//      Solution() : arr(size, true) {
//         arr[0] = arr[1] = false;
//         for (int i = 2; i * i < size; ++i) {
//             if (arr[i]) {
//                 for (int j = i * i; j < size; j += i)
//                     arr[j] = false;     
//             }
//         }
//     }

//     int countPrimes(int n) {
//         if(n==0 || n==1) return 0;
//         int ans=0;
//         for(int i=2;i<n;i++){
//             if(arr[i]==true) ans++;
//         }
//         return ans;
//     }//fn ends here
// };

class Solution {
  public: int countPrimes(int n) {
    if (n <= 2) return 0;
    vector < bool > is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < n; ++p) {
      if (is_prime[p]) {
        for (int multiple = p * p; multiple < n; multiple += p) {
          is_prime[multiple] = false;
        }
      }
    }
    return count(is_prime.begin(), is_prime.end(), true);
  }
};
