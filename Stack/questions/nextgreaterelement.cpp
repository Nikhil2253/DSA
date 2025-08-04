#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Intuitive: TC: O(N^2), SC: O(N)
vector<int> NextGreateElementIntuition(vector<int> arr)
{
    int n = arr.size();
    vector<int> nge(n, -1); // initialize all with -1

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                nge[i] = arr[j];
                break;
            }
        }
    }

    return nge;
}

// Optimal: Monotonic Stack | TC: O(N), SC: O(N)
vector<int> NextGreaterElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    return nge;
}

void printVector(const vector<int> &vec)
{
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {42, 17, 63, 5, 88, 21, 74, 30, 91, 10};

    vector<int> ngeI = NextGreateElementIntuition(arr);
    vector<int> ngeO = NextGreaterElement(arr);

    cout << "Intuitive Way: ";
    printVector(ngeI);

    cout << "Optimal Way: ";
    printVector(ngeO);

    return 0;
}
