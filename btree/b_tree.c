#define TREE_NODE_SIZE 5

/*
Implementation thoughts
A simple balancing algorithm can happen on every X inserts.
1. Look at the total number of rows
2. Order the rows (we should have this already with out link list leaf nodes)
3. (recursively?) rebuild the tree, either based on the tree node size, or based on the desired depth
*/

typedef struct {

} TreeNode;