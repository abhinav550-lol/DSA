#include <iostream>
#include <vector>
#include <climits>
using namespace std;


using ll = long long;
class SegmentTree {
public:
    vector<ll> nums;
    vector<ll> nodes;
    ll n;

    ll build(ll idx, ll l, ll r) {
        if (l == r) {
            nodes[idx] = nums[l];
            return nums[l];
        }

        ll mid = l + (r - l) / 2;
        ll leftBuild = build(2 * idx + 1, l, mid);
        ll rightBuild = build(2 * idx + 2, mid + 1, r);
        return nodes[idx] = max(leftBuild, rightBuild);
    }

    ll query(ll qStart, ll qEnd, ll l, ll r, ll idx) {
        if (r < qStart || l > qEnd) {
            return LLONG_MIN;
        }

        if (qStart <= l && qEnd >= r) {
            return nodes[idx];
        }

        ll mid = l + (r - l) / 2;
        ll left = query(qStart, qEnd, l, mid, 2 * idx + 1);
        ll right = query(qStart, qEnd, mid + 1, r, 2 * idx + 2);
        return max(left, right);
    }

    void update(ll pos, ll val, ll l, ll r, ll idx) {
        if (l == r) {
            nodes[idx] = val;
            nums[pos] = val;
            return;
        }

        ll mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, 2 * idx + 1);
        } else {
            update(pos, val, mid + 1, r, 2 * idx + 2);
        }

        nodes[idx] = max(nodes[2 * idx + 1], nodes[2 * idx + 2]);
    }

    SegmentTree(const vector<ll>& nums) {
        this->nums = nums;
        this->n = nums.size();
        nodes.resize(4 * n, 0);
        build(0, 0, n - 1);
    }
};
