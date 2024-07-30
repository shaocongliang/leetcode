class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        std::map<char, int> m1, m2;
        for (std::size_t i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) a++;
            else {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        for (const std::pair<char, int> &p : m2) {
            if (m1.find(p.first) != m1.end()) {
                b += std::min(p.second, m1[p.first]);
            }
        }
        return std::to_string(a) + "A" + std::to_string(b) + "B";
    }
};
