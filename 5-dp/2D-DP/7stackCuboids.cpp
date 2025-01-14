/*
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
*/


bool check(vector<int> &curr, vector<int> &base) {
    return base[0] >= curr[0] && base[1] >= curr[1] && base[2] >= curr[2];
}

int longestSubsequence(int n, vector<vector<int>> &a) {
    vector<int> next(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--) {
        vector<int> crr(n + 1, 0);
        for (int prev = curr - 1; prev >= -1; prev--) {
            int inc = 0;
            if (prev == -1 || check(a[prev], a[curr])) {
                inc = a[curr][2] + next[curr + 1];
            }
            int exc = next[prev + 1];

            crr[prev + 1] = max(inc, exc);
        }
        next = crr;
    }
    return next[0];
}

class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return longestSubsequence(cuboids.size(), cuboids);
    }
};