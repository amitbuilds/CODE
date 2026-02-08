#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

class Solution {
public:
    pair<bool,int> isBalancedFast(TreeNode* root) {
        if(root == nullptr) {
            return make_pair(true, 0);
        }

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.first = leftAns && rightAns && diff;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};
