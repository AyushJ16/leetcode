/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf==true && quadTree2->isLeaf==true) {
            return new Node(quadTree1->val || quadTree2->val, true);
        }
        else if(quadTree1->isLeaf==1) {
            if(quadTree1->val==1) {
                return new Node(1, true);
            }
            else {
                return quadTree2;
            }
        } 
        else if(quadTree2->isLeaf==true) {
            if(quadTree2->val==1) {
                return new Node(1, true);
            }
            else {
                return quadTree1;
            }
        }
        else {
            
            Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            
            bool all_are_leaves = topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf;
            bool same_vals = topLeft->val==topRight->val && topRight->val==bottomLeft->val && bottomLeft->val==bottomRight->val;
            
            if(all_are_leaves && same_vals) {
                return new Node(1, true);
            }
            else {
                return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
            }
        }


    }
};