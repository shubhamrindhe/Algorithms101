class Solution {

public:

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        vector<int> prexor;

        int x_or = 0b0;
        for (auto e : arr) {
            x_or ^= e;
            prexor.push_back(x_or);
        }

        for (auto querie : queries) {
            int l = querie[0];
            int r = querie[1];
            result.push_back( (l > 0 ? prexor[l - 1] : 0 ) ^ prexor[r] );
        }

        return result;
    }
};
