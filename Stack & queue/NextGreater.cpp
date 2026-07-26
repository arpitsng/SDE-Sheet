//-------------stack based solution for next greater element----------------
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; //num : next greater element
        stack<int> st;
        st.push(-1);
        int n = nums2.size();
        for(int i=n-1; i>=0; i--){
            int num = nums2[i];
            while(st.top() != -1 && st.top() < num){
                st.pop();
            }

            mp[num] = st.top();
            st.push(num);
        }

        vector<int> ans;
        for(auto num: nums1){
            ans.push_back(mp[num]);
        }

        return ans;
    }
};