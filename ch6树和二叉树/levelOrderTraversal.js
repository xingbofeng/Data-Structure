var tree = require('./tree.json');
// 广度优先遍历算法，使用队列
function levelOrderTraversal(tree) {
	if (!tree) {
		return false;
	}
	// 设置一个队列，push入队，shift出队
	var que = [];
	que.push(tree);
	while(que.length !== 0) {
		tree = que.shift();
		console.log(tree.value);
		if (tree.left) {
			que.push(tree.left);
		}
		if (tree.right) {
			que.push(tree.right);
		}
	}
}
levelOrderTraversal(tree);