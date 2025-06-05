
class Solution {
public:
    int parent[26];

    void init() {
        for (int i = 0; i < 26; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rootX < rootY)
            parent[rootY] = rootX;
        else
            parent[rootX] = rootY;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        init();

        for (int i = 0; i < s1.length(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (char c : baseStr) {
            int root = find(c - 'a');
            result += (char)(root + 'a');
        }

        return result;
    }
};