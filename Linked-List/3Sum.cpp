//--------------------optimal------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for(int i=0; i<n-2; i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;
            int low = i+1, high = n-1;
            while(low < high){
                int sum = arr[i] + arr[low] + arr[high];

                if(sum == 0){
                    ans.push_back({arr[i], arr[low], arr[high]});
                    while(low < high && arr[low] == arr[low+1])low++;
                    while(low < high && arr[high] == arr[high-1])high--;

                    low++;
                    high--;
                }

                else if(sum > 0) high--;
                else low++;
            }
        }

        return ans;
    }
};