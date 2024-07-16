#include <iostream>
#include <vector>
#include <list>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::string getDirections(TreeNode* root, int startValue, int destValue) {
        DepthFirstSearch(root, startValue);
        std::string pathFromStart = m_history;
        m_history.clear();

        DepthFirstSearch(root, destValue);

        int i = 0;
        while (i < pathFromStart.size() && i < m_history.size() && pathFromStart.at(i) == m_history.at(i)) {
            i++;
        }

        std::string finalPath(pathFromStart.size() - i, 'U');
        finalPath += m_history.substr(i);

        return finalPath;
    }

private:

    void BreadthFirstTraverse(TreeNode* root) {
        std::cout << "INITIATING BREADTH FIRST SEARCH" << std::endl;
        std::list<TreeNode*> q;
        q.push_back(root);
        while (q.size() > 0) {
            TreeNode* node = q.front();
            q.pop_front();

            if (node == nullptr) {
                continue;
            }

            q.push_back(node->left);
            q.push_back(node->right);
        }
    }

    bool DepthFirstSearch(TreeNode* node, int target) {
        if (node == nullptr)
            return false;

        if (node->val == target) {
            std::cout << std::endl << "Found " << target << std::endl;
            return true;
        }

        m_history += "L";
        if (DepthFirstSearch(node->left, target)) {
            return true;
        }
        m_history.pop_back();

        m_history += "R";
        if (DepthFirstSearch(node->right, target)) {
            return true;
        }
        m_history.pop_back();

        return false;
    }

private:
    std::string m_history;
};

// Probably memory leak happening here!!!
TreeNode* GenerateTree(TreeNode* node, const std::vector<int>& values, int childIndex) {
    if ((childIndex >= values.size()) || (values[childIndex] == NULL)) {
        std::cout << "null -> ";
        return nullptr;
    }

    // Current Node related stuff 
    node = new TreeNode(values[childIndex], nullptr, nullptr);

    // Left Child
    node->left = GenerateTree(node->left, values, 2 * childIndex + 1);

    // Right Child
    node->right = GenerateTree(node->right, values, 2 * childIndex + 2);

    return node;
}




int main() {
    std::vector<int> tree = { 1, NULL, 10, 12, 13, 4, 6, NULL, 15, NULL, NULL, 5, 11, NULL, 2, 14, 7, NULL, 8, NULL, NULL, NULL, 9, 3 };
    TreeNode* root = GenerateTree(nullptr, tree, 0);

    Solution s;
    int start = 6, dest = 15;

    std::string direction = s.getDirections(root, start, dest);
    std::cout << direction;
    std::cin.get();
}