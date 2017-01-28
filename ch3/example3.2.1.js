// 例题3.2.1，10进制转换8进制
var stack = [];
function conversion (N) {
	while (N) {
		stack.push(N % 8);
		N = Math.floor(N / 8);
		// floor向下取整，ceil向上取整，round四舍五入
	}
	while (stack.length !== 0) {
		console.log(stack.pop());
	}
}
conversion(1348);