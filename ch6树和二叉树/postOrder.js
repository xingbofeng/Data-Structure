var tree = require('./tree.json');
// 后序遍历二叉树，使用递归
// 先遍历左子树，再遍历右子树，再遍历根节点
function postOrder(tree) {
	if (!tree) {
		return;
	}
	postOrder(tree.left);
	postOrder(tree.right);
	console.log(tree.value);
}
postOrder(tree);