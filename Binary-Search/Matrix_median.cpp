class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();

        int low = mat[0][0];
        int high = mat[0][m - 1];

        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m - 1]);
        }

        int need = (n * m + 1) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int cnt = countLessThan(mat, mid);

            if (cnt < need)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }

    int countLessThan(vector<vector<int>> &mat, int val) {
        int cnt = 0;

        for (auto &row : mat)
            cnt += upper_bound(row.begin(), row.end(), val) - row.begin();

        return cnt;
    }
};