#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
    public:
        // Encodes tree to a single string
        string serialize(TreeNode* root) {
            string code = encodeHelper(root);
            
            return code;
        }
        
        string encodeHelper(TreeNode* root) {
            if (root == nullptr) {
                return " nil";
            }
            
            return " " + to_string(root->val) + encodeHelper(root->left) + encodeHelper(root->right);
        }

        // Decodes encoded data to tree
        TreeNode* deserialize(string data) {
            stringstream datastream(data);
    
            TreeNode* root = decodeHelper(datastream);
            
            return root;
        }
        
        TreeNode* decodeHelper(stringstream& datastream) {
            string val;
            datastream >> val;
            
            if (val == "nil") {
                return nullptr;
            }
            
            TreeNode* node = new TreeNode(stoi(val));
            node->left = decodeHelper(datastream);
            node->right = decodeHelper(datastream);
            
            return node;
        }
};

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);

    cout << root->val << " ";

    inOrderTraversal(root->right);
}



int main() {
  
  Codec* ser = new Codec();
  Codec* deser = new Codec();
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  string tree = ser->serialize(root);
  TreeNode* ans = deser->deserialize(tree);
  inOrderTraversal(ans);
  
}
