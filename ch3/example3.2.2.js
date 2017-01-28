function parentheses(str) {
	let arr = str.split('');
	let result = [];
	// 逐个读入括号
	for (let i = 0; i < arr.length; i++) {
		if (result.length === 0) {
			// 如果栈空，则入栈
			result.push(arr[i]);
		} else if ((arr[i] === '(') || (arr[i] === '[')) {
			// 如果匹配到左括号，则入栈
			result.push(arr[i]);
		} else if (arr[i] === ')') {
			// 如果匹配到右小括号，则查看栈顶
			if (result[result.length - 1] === '(') {
				// 若栈顶为左小括号，则栈顶出栈
				result.pop();
			} else {
				// 否则把右小括号入栈
				result.push(arr[i]);
			}
		} else if (arr[i] === ']') {
			// 如果匹配到左括号，则入栈
			if (result[result.length - 1] === '[') {
				// 若栈顶为左中括号，则栈顶出栈
				result.pop();
			} else {
				// 否则把右中括号入栈
				result.push(arr[i]);
			}
		}
	}
	// 最后判断栈是否为空，若为空，则匹配正确，否则匹配失败
	if (result.length === 0) {
		return true;
	} else {
		return false;
	}
}
console.log(parentheses('[()()]'));
console.log(parentheses('[()()]]]'));