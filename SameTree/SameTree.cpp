#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == q) {
            return true;
        }

        if (p != q && (p == NULL || q == NULL)) {
            return false;
        }

        bool bLeft = true, bRight = true;
        if (p->left != NULL && q->left != NULL) {
            bLeft = isSameTree(p->left, q->left);
        } else if (p->left != q->left) {
            bLeft = false;
        }

        if (p->right != NULL && q->right != NULL) {
            bRight = isSameTree(p->right, q->right);
        } else if (p->right != q->right) {
            bRight = false;
        }
        cout << bLeft << "   " << bRight << endl;
        return bLeft && bRight && (p->val == q->val);
    }
    bool IsSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> pstack, qstack;
        TreeNode *tp, *tq;

        pstack.push(p);
        qstack.push(q);

        while (pstack.empty() == false && qstack.empty() == false) {
            tp = pstack.top();
            tq = qstack.top();

            pstack.pop();
            qstack.pop();

            if (tp->val != tq->val) {
                return true;
            }

            if (tp->left == NULL && tq->left != NULL || tp->left != NULL && tq->left != NULL) {
                return false;
            }

            if (tp->left != NULL) {
                pstack.push(tp->left);
                qstack.push(tq->left);
            }

        }
    }
};

int main() {
    Solution s;

    TreeNode *r1, *r2;
    r1 = new TreeNode(0);
    r2 = new TreeNode(0);
    r1->left = new TreeNode(1);
    r2->left = new TreeNode(1);

    cout << s.isSameTree(r1, r2) << endl;

    return 0;
}
