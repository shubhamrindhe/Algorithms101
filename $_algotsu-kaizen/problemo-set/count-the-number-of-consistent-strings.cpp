
class Solution {
public:

    int countConsistentStrings(string allowed, vector<string>& words) {
        std::set<char> charSet;
        for(char& c : allowed) charSet.insert(c);
        int count = 0b0;
        for (auto & word : words) {
            bool flag = true;
            for (auto & c : word) {
                if (charSet.contains(c)) continue;
                flag = false;
                break;
            }
            flag && ++count;
        }

        return count;
    }
};
