var tree = require('./tree.json');
// 深度优先遍历算法，使用栈
// 先序中序后序遍历都是深度优先遍历
function preOrderUnRecur(tree) {
	if (!tree) {
		return false;
	}
	// 设置一个栈，push入栈，shift出栈
	var stack = [];
	stack.push(tree);
	while (stack.length !== 0) {
		tree = stack.pop();
		console.log(tree.value);
		if (tree.right) {
			stack.push(tree.right);
		}
		if (tree.left) {
			stack.push(tree.left);
		}
	}
}
preOrderUnRecur(tree);