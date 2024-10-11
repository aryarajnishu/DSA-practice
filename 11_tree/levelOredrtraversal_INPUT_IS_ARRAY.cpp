#include <vector>
#include <queue>
#include <cmath> // for pow
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildPerfectTree(vector<int>& nums) {
        return buildTree(nums, 0);
    }

private:
    TreeNode* buildTree(vector<int>& nums, int index) {
        if (index >= nums.size()) // Base case: no more elements in the array
            return nullptr;

        // Create the current node
        TreeNode* root = new TreeNode(nums[index]);

        // Calculate the indices of left and right children
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;

        // Recursively build left and right subtrees
        root->left = buildTree(nums, leftChildIndex);
        root->right = buildTree(nums, rightChildIndex);

        return root;
    }
};

// Example usage:
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = solution.buildPerfectTree(nums);
    // Now you can use the root of the tree for further operations
    return 0;
}
