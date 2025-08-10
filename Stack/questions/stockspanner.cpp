#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> stocks; // {price, index}
    int index;

public:
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;

        // Pop all previous prices <= current price
        while (!stocks.empty() && stocks.top().first <= price) {
            stocks.pop();
        }

        int ans = index - (stocks.empty() ? -1 : stocks.top().second);
        stocks.push({price, index});

        return ans;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int p : prices) {
        cout << "Price: " << p 
             << " -> Span: " << obj->next(p) << "\n";
    }

    delete obj;
    return 0;
}
