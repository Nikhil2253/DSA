class Solution {
private:
    bool isAnagram(string p, string check) {
        if (p.size() != check.size()) return false;

        vector<int> freq(26, 0);
        for (char c : p) freq[c - 'a']++;
        for (char c : check) freq[c - 'a']--;

        for (int f : freq) {
            if (f != 0) return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagramIndices;
        int n = s.length();
        int anagramSize = p.length();

        if (anagramSize > n) return anagramIndices;

        int start = 0, end = n - 1;

        while (start + anagramSize - 1 <= end) {
            string sub = s.substr(start, anagramSize);
            if (isAnagram(p, sub)) {
                anagramIndices.push_back(start);
            }
            start++;
        }

        return anagramIndices;
    }
};
