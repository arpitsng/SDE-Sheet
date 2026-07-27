//------------stack solution------------------
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> next(n), prev(n); //stores the index of nextSmall and prevSmall elements
        nextSmaller(h, next);
        prevSmaller(h, prev);

        int maxi = 0;
        for(int i=0; i<n; i++){
            if(next[i] == -1) next[i] = n;
            int length = next[i] - prev[i] - 1;
            int breadth = h[i];

            maxi = max(maxi, length * breadth);
        }

        return maxi;
    }

    void nextSmaller(vector<int>& h, vector<int> &next){
        stack<int> st;
        st.push(-1);

        int n = next.size();
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && h[st.top()] >= h[i]) st.pop();

            next[i] = st.top();
            st.push(i);
        }
    }

    void prevSmaller(vector<int>& h, vector<int> &prev){
        stack<int> st;
        st.push(-1);

        int n = prev.size();
        for(int i=0; i<n; i++){
            while(st.top() != -1 && h[st.top()] >= h[i]) st.pop();

            prev[i] = st.top();
            st.push(i);
        }
    }
};