// 例题3.2.3，行编辑程序
function edit(str) {
	let result = [];
	let arr = str.split('');
	// 遍历arr数组
	for (let i = 0; i < arr.length; i++) {
		if (arr[i] === '#') {
			// 如果是退格符则出栈
			result.pop();
		} else if (arr[i] === '@') {
			// 如果是退行符则清空栈
			result = [];
		} else {
			// 如果是其他符号则入栈
			result.push(arr[i]);
		}
	}
	return result.join('');
}
// 初始化输入
var string = 'whli##ilr#e(s#*s)\noutcha@putchar(*s=#++)';
var output = string.split('\n').map((value, index ,array) => {
	return edit(value);
}).join('\n');
console.log(output);