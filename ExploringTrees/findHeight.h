#ifndef FINDHEIGHT_H
#define FINDHEIGHT_H

using namespace std;

class FindHeight{
    int height = 0;
    int left, right, ans;
    public:
    int find(Node* root){
        if(root == NULL){
            return height;
        }
        left = find(root->left);
        right = find(root->right);
        ans = max(left, right) + 1;
        return ans;
    }
};

#endif