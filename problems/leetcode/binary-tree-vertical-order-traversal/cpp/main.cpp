#include <vector>
#include <unordered_map>

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
    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> result;
        std::unordered_map<int, std::vector<int>> byDist;
        int minDist = 0, maxDist = 0;
        std::vector<std::pair<TreeNode*, int>> queue{{root, 0}}, next_queue;
        while (queue.size() > 0) {
            for (auto [node, dist] : queue) {
                minDist = std::min(minDist, dist);
                maxDist = std::max(maxDist, dist);
                byDist[dist].push_back(node->val);
                if (node->left != nullptr) {
                    next_queue.emplace_back(node->left, dist-1);
                }
                if (node->right != nullptr) {
                    next_queue.emplace_back(node->right, dist+1);
                }
            }
            std::swap(queue, next_queue);
            next_queue.clear();
        }
        for (int dist = minDist; dist <= maxDist; dist++) {
            result.emplace_back();
            auto &nodes = result.back();
            for (auto node : byDist[dist]) {
                nodes.push_back(node);
            }
        }
        return result;
    }
};
