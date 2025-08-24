#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        for (long long k=1; k<=n; k*=10) {
            long long higher  = n / (k * 10);
            long long current = (n / k) % 10;
            long long lower   = n % k;

            if (current == 0) {
                count += higher * k;
            } else if (current == 1) {
                count += higher * k + lower + 1;
            } else {
                count += (higher + 1) * k;
            }
        }

        return (int)count;
    }
};

