// 例题3.2.5，表达式求值
const symbols = {
	'*': 4,
	'/': 3,
	'+': 3,
	'-': 2,
	'(': 1,
	')': 6,
	'#': 0,
};
// 运算的函数
function operation(a, b, symbol) {
	if (symbol === '*') {
		return (a * b);
	} else if (symbol === '/') {
		return (a / b);
	} else if (symbol === '+') {
		return (a + b);
	} else if (symbol === '-') {
		return (a - b);
	}
}

function evaluation(str) {
	var arr = str.split('');
	var left, right;
	let numstack = [];
	// numstack用于寄存操作数
	let symbolstack = [];
	// symbolstack用于寄存运算符
	symbolstack.push('#');
	for (let i = 0; i < arr.length; i++) {
		if (/\d/.test(arr[i])) {
			numstack.push(parseInt(arr[i], 10));
		} else {
			if (symbolstack.length === 1) {
				symbolstack.push(arr[i]);
			} else {
				if (symbols[arr[i]] > symbols[symbolstack[symbolstack.length - 1]]) {
					// 如果栈顶符号优先级低，则入栈
					symbolstack.push(arr[i]);
				} else if ((symbols[arr[i]] === ')') && (symbolstack[symbolstack.length - 1] === '(')) {
					// 如果栈顶是'('并且读到了')'，则脱括号
					symbolstack.pop();
				} else if (symbols[arr[i]] < symbols[symbolstack[symbolstack.length - 1]]) {
					// 如果栈顶符号优先级高，则拿出栈顶符号进行运算
					right = numstack.pop();
					left = numstack.pop();
					numstack.push(operation(left, right, symbolstack.pop()));
					symbolstack.push(arr[i]);
				}
			}
		}
	}
	console.log(numstack);
	console.log(symbolstack);
}
evaluation('1+2*3/4#');