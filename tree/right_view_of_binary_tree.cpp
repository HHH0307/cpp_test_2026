#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 返回右视图（BFS 版本）
vector<int> right_side_view_bfs(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) res.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

// 返回右视图（DFS 右优先）
vector<int> right_side_view_dfs(TreeNode* root) {
    vector<int> res;
    int maxDepth = -1;
    function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) {
        if (!node) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res.push_back(node->val);
        }
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    };
    dfs(root, 0);
    return res;
}

// 释放二叉树内存
void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

static void print_vec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' ';
        cout << v[i];
    }
    cout << '\n';
}

int main() {
    // 构造示例树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> expected = {1, 3, 4};

    vector<int> bfs = right_side_view_bfs(root);
    cout << "BFS right view: "; print_vec(bfs);

    vector<int> dfs = right_side_view_dfs(root);
    cout << "DFS right view: "; print_vec(dfs);

    bool ok = (bfs == expected) && (dfs == expected);
    cout << (ok ? "TEST PASSED" : "TEST FAILED") << '\n';

    free_tree(root);
    return ok ? 0 : 1;
}