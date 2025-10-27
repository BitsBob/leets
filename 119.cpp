#include <bits/stdc++.h>
using namespace std;

// c(n, k) = n! / (k!(n-k)!)

class Solution {
public:
    int factorial(int n) {
        if (n == 0 || n == 1)
            return 1;
        return n * factorial(n - 1);
    };

    vector<int> getRow(int rowIndex) {
        vector<int> line = {1};
        for (int i=1; i<rowIndex+1; ++i) {
            line.push_back(factorial(rowIndex) / (factorial(i)*factorial(rowIndex-i)));
        }

        return line;
    }
};