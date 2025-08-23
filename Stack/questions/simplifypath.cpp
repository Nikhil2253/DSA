#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<string> tokenize(string path, char delimiter)
    {
        vector<string> ans;
        string token = "";

        for (char c : path)
        {
            if (c == delimiter)
            {
                if (!token.empty() && token != ".")
                {
                    ans.push_back(token);
                }
                token = "";
            }
            else
            {
                token += c;
            }
        }

        // Add the last token if valid
        if (!token.empty() && token != ".")
        {
            ans.push_back(token);
        }

        return ans;
    }

public:
    string simplifyPath(string path)
    {
        vector<string> tokenizedPath = tokenize(path, '/');
        stack<string> st;

        for (string &dir : tokenizedPath)
        {
            if (dir == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else if (dir != "" && dir != ".")
            {
                st.push(dir);
            }
        }

        // Build result
        if (st.empty()) return "/";

        vector<string> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        string ans = "";
        for (string &dir : res)
        {
            ans += "/" + dir;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/home/") << endl;          // "/home"
    cout << s.simplifyPath("/../") << endl;            // "/"
    cout << s.simplifyPath("/home//foo/") << endl;     // "/home/foo"
    cout << s.simplifyPath("/a/./b/../../c/") << endl; // "/c"
    return 0;
}
