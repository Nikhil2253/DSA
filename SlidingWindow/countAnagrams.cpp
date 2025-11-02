#include <iostream>
#include <vector>
using namespace std;

int getIndex(char character)
{
   character = toupper(character);
   return (character - 'A');
}

bool check(vector<int> freq, string pattern)
{
   vector<int> pfreq(26, 0);
   int k = pattern.length();

   for (int i = 0; i < k; i++)
   {
      int index = getIndex(pattern[i]);
      pfreq[index]++;
   }

   for (int i = 0; i < freq.size(); i++)
   {
      if (freq[i] != pfreq[i])
         return false;
   }
   return true;
}

vector<int> bruteForce(string text, string pattern)
{
   vector<int> ans;
   vector<int> freq(26, 0);
   int k = pattern.length();
   int n = text.length();

   for (int i = 0; i < k; i++)
   {
      int index = getIndex(pattern[i]);
      freq[index]++;
   }

   for (int i = 0; i <= n - k; i++)
   {
      if (check(freq, text.substr(i, k)))
      {
         ans.push_back(i);
      }
   }

   return ans;
}

bool allZero(const vector<int>& counter) {
    for (int val : counter) {
        if (val != 0) return false;
    }
    return true;
}

vector<int> optimalApproach(string text, string pattern) {
    vector<int> ans;
    int k = pattern.length();
    int n = text.length();

    if (n < k) return ans;

    vector<int> counter(26, 0);
    for (char c : pattern) counter[getIndex(c)]++;

    int i = 0;
    for (int j = 0; j < n; j++) {
        counter[getIndex(text[j])]--;
        if (j - i + 1 > k) {
            counter[getIndex(text[i])]++;
            i++;
        }
        if (j - i + 1 == k && allZero(counter)) ans.push_back(i);
    }

    return ans;
}

int main()
{
   string text = "cbaebabacdabc";
   string pattern = "abc";

   vector<int> result = bruteForce(text, pattern);

   cout << "Anagram indices: ";
   for (int idx : result)
   {
      cout << idx << " ";
   }
   cout << endl;

   vector<int> resultOptimal = optimalApproach(text, pattern);

   cout << "Anagram indices: ";
   for (int idx : resultOptimal)
   {
      cout << idx << " ";
   }
   cout << endl;

   return 0;
}
