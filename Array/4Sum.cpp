//----------------optimal----------------
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        } 

        for(int i=0; i<n; i++){
            int val = arr[i];
            int need = target - arr[i];

            if(mp.find(need) != mp.end() && mp[need] != i){
                return {i, mp[need]};
            }
        }

        return {-1, -1};
    }
};