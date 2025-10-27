#include <bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> sample(n, true);

        sample[0] = sample[1] = false;

        int limit = static_cast<int>(sqrt(n));
        for (int i=2; i<limit; ++i) {
            if (sample[i]) {
                for (int j=i*i; j<n; j+=i) {
                    sample[j] = false;
                }
            }
        }

        return std::count(sample.begin(), sample.end(), true);
    }
                
};
