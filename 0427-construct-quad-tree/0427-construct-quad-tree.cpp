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
    Node* zero = new Node(false, true);
    Node* one = new Node(true, true);
    Node * create(vector<vector<int>> & grid, int x,int y ,int n){
        if(n==1)
        return grid[x][y]==1?one:zero;

        int mid=n/2;
        Node*topleft= create(grid,x,y,mid);
        Node * topright= create(grid,x,y+mid,mid);
        Node* botleft= create(grid,x+mid,y,mid);
        Node* botright= create(grid,x+mid,y+mid,mid);
        if(topleft==topright && botleft==botright && topleft==botleft){
            return topleft;
        }
        return new Node(false,false, topleft,topright,botleft,botright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return create(grid,0,0,grid.size());
    }
};