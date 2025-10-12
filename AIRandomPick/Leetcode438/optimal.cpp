class Solution {
private:
    bool isAnagram(const vector<int>& pFreq, const vector<int>& windowFreq) {
        for (int i = 0; i < 26; i++)
            if (pFreq[i] != windowFreq[i]) return false;
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> anagramIndices;
        int n = s.length();
        int anagramSize = p.length();

        if (anagramSize > n) return anagramIndices;

         vector<int> pFreq(26, 0);
        for (char c : p) pFreq[c - 'a']++;

        vector<int> windowFreq(26, 0);
        for (int i = 0; i < anagramSize; i++) windowFreq[s[i] - 'a']++;

        if(isAnagram(pFreq,windowFreq)) anagramIndices.push_back(0);

       for (int start = 1; start <= n - anagramSize; start++) {
            windowFreq[s[start - 1] - 'a']--;
            windowFreq[s[start + anagramSize - 1] - 'a']++;
            if (isAnagram(pFreq, windowFreq)) anagramIndices.push_back(start);
        }

        return anagramIndices;
    }
};
