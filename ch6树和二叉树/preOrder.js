var tree = require('./tree.json');
// 先序遍历二叉树，使用递归
// 先遍历根节点，再遍历左子树，再遍历右子树
function preOrder(tree) {
	if (!tree) {
		return;
	}
	console.log(tree.value);
	preOrder(tree.left);
	preOrder(tree.right);
}
preOrder(tree);