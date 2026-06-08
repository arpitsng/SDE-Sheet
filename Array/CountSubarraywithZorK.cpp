//-------------optimal-----------

class Solution {
public:
    long long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, long long> freq;
        freq[0] = 1;

        int prefixXor = 0;
        long long cnt = 0;

        for (int x : arr) {
            prefixXor ^= x;

            int target = prefixXor ^ k; //required

            if (freq.count(target))
                cnt += freq[target];

            freq[prefixXor]++;
        }

        return cnt;
    }
};