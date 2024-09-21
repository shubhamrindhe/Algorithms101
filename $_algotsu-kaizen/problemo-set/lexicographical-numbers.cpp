
class Solution {

    vector<int> generate(int i, int n) {
        if (i > n) return { };
        vector<int> result = { i };
        vector<int> next = generate(i * 10, n);
        result.insert(result.end(), next.begin(), next.end());

        if (i % 10 < 9) {
            vector<int> nextNumbers = generate(i + 1, n);
            result.insert(result.end(), nextNumbers.begin(), nextNumbers.end());
        }

        return result;
    }

public:
    vector<int> lexicalOrder(int n) {
        return generate(1, n);
    }
};
