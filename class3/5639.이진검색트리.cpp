#include <iostream>
#include <map>

using namespace std;

typedef struct node {
    int n;
    struct node *left;
    struct node *right;
}   node;

node *new_node(int n) {
    node *tmp = new node;
    tmp->n = n;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}

void recv(node *root)
{
    if (root->left)
        recv(root->left);
    if (root->right)
        recv(root->right);
    cout << root->n << "\n";
}


int main()
{
    int n; cin >> n;
    node *root = new_node(n);
    while (cin >> n) {
        node *tmp = root;
        while (1) {
            if (n < tmp->n) {
                if (tmp->left == nullptr) {
                    tmp->left = new_node(n);
                    break;
                }
                else
                    tmp = tmp->left;
            }
            else if (n > tmp->n) {
                if (tmp->right == nullptr) {
                    tmp->right = new_node(n);
                    break;
                }
                else
                    tmp = tmp->right;
            }
        }
    }
    recv(root);
}