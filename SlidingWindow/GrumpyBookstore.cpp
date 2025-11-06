#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bruteForce(vector<int> customers, vector<int> grumpy, int minutes) {
    int n = customers.size();
    int maxExtraSatisfied = 0;
    int baseSatisfied = 0;
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0)
            baseSatisfied += customers[i];
    }
    for (int i = 0; i + minutes <= n; i++) {
        int extra = 0;
        for (int j = i; j < i + minutes; j++) {
            if (grumpy[j] == 1)
                extra += customers[j];
        }
        maxExtraSatisfied = max(maxExtraSatisfied, extra);
    }
    return baseSatisfied + maxExtraSatisfied;
}

int optimalApproach(vector<int> customers, vector<int> grumpy, int minutes) {
    int n = customers.size();
    int baseSatisfied = 0;
    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0)
            baseSatisfied += customers[i];
    }
    int extra = 0, maxExtra = 0;
    for (int i = 0; i < minutes; i++) {
        if (grumpy[i] == 1)
            extra += customers[i];
    }
    maxExtra = extra;
    for (int i = minutes; i < n; i++) {
        if (grumpy[i] == 1)
            extra += customers[i];
        if (grumpy[i - minutes] == 1)
            extra -= customers[i - minutes];
        maxExtra = max(maxExtra, extra);
    }
    return baseSatisfied + maxExtra;
}

int main() {
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    cout << "Brute Force Result: " << bruteForce(customers, grumpy, minutes) << endl;
    cout << "Optimal Result: " << optimalApproach(customers, grumpy, minutes) << endl;
    return 0;
}
