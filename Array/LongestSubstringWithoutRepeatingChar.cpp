//------------optimal------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        unordered_map<char, int> freq;
        int left = 0, maxi = 1;

        for(int right=0; right < n; right++){
            freq[s[right]]++;  //keep expanding stop when encounter repeating

            while(freq[s[right]] > 1){ //shring when repeating char
                freq[s[left]]--;
                left++;
            }

            maxi = max(maxi, right-left+1);
        }

        return maxi;
    }
};