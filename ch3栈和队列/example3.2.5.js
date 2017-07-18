// 例题3.2.5，表达式求值
const symbols = {
	'*': 3,
	'/': 3,
	'+': 2,
	'-': 2,
	'(': 1,
	')': 4,
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
				} else if (symbols[arr[i]] <= symbols[symbolstack[symbolstack.length - 1]]) {
					// 如果栈顶符号优先级高，则拿出栈顶符号进行运算
					right = numstack.pop();
					left = numstack.pop();
					numstack.push(operation(left, right, symbolstack.pop()));
					// 此步进行运算但是并不读符号，因为我们已经把数字推入操作数栈
					// i-- 则下次还是读这个符号，直到清空栈里的操作数只剩下一个'#'
					// 此刻操作数栈优先级低，就不会走这个else if了
					i--;
				}
			}
		}
	}
	console.log(symbolstack);
	console.log(numstack);
	// var i = 0;
	// while (arr[i] !== '#') {
	// 	if (/\d/.test(arr[i])) {
	// 		numstack.push(parseInt(arr[i], 10));
	// 		i++;
	// 	} else {
	// 		if (symbols[arr[i]] > symbols[symbolstack[symbolstack.length - 1]]) {
	// 			// 如果栈顶符号优先级低，则入栈
	// 			symbolstack.push(arr[i]);
	// 			i++;
	// 		} else if ((symbols[arr[i]] === ')') && (symbolstack[symbolstack.length - 1] === '(')) {
	// 			// 如果栈顶是'('并且读到了')'，则脱括号
	// 			symbolstack.pop();
	// 			i++;
	// 		} else if (symbols[arr[i]] <= symbols[symbolstack[symbolstack.length - 1]]) {
	// 			// 如果栈顶符号优先级高，则拿出栈顶符号进行运算
	// 			right = numstack.pop();
	// 			left = numstack.pop();
	// 			numstack.push(operation(left, right, symbolstack.pop()));
	// 			symbolstack.push(arr[i]);
	// 			i++;
	// 		}
	// 	}
	// }
	// console.log(numstack);
}
evaluation('1+3+3+2*3/4+3+3+3/2#');