var tree = require('./tree.json');
// 中序遍历二叉树，使用递归
// 先遍历左子树，再遍历根节点，再遍历右子树
function inOrder(tree) {
	if (!tree) {
		return;
	}
	inOrder(tree.left);
	console.log(tree.value);
	inOrder(tree.right);
}
inOrder(tree);