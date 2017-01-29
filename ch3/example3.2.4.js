// 例题3.2.4，迷宫问题的求解
// 初始化迷宫，1代表墙，0代表路。
var mymaze = [
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
	[1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
	[1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
	[1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
	[1, 0, 1, 1, 1, 0, 0, 1, 0, 1],
	[1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
	[1, 0, 1, 0, 0, 0, 1, 0, 1, 1],
	[1, 0, 1, 1, 1, 1, 0, 0, 1, 1],
	[1, 1, 1, 0, 0, 0, 1, 0, 1, 1],
	[1, 1, 1, 0, 0, 0, 0, 0, 0, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
];
var step = 0;
var startLocation = {
	col: 1,
	row: 1,
	flag: 1,
};
var endLocation = {
	col: 8,
	row: 8,
}

function goRight(location) {
	return {
		col: location.col,
		row: ++(location.row),
		flag: 1,
	}
}

function goLeft(location) {
	return {
		col: location.col,
		row: --(location.row),
		flag: 3,
	}
}

function goTop(location) {
	return {
		col: --(location.col),
		row: location.row,
		flag: 4,
	}
}

function goBottom(location) {
	return {
		col: ++(location.col),
		row: location.row,
		flag: 2,
	}
}

function go(location) {
	if (location.flag === 1) {
		return goRight(location);
	} else if (location.flag === 2) {
		return goBottom(location);
	} else if (location.flag === 3) {
		return goLeft(location);
	} else if (location.flag === 4) {
		return goTop(location);
	}
}

function maze(startLocation, endLocation) {
	let stack = [];
	// 若开始位置是墙，则抛出错误
	if (mymaze[startLocation.col][startLocation.row] === 1) {
		return false;
	}
	// location代表当前位置
	let location = startLocation;
	do {
		// 如果当前位置可通过，则把当前位置推入栈
		if (mymaze[location.col][location.row] === 0) {
			stack.push(location);
			mymaze[location.col][location.row] = step;
			if ((endLocation.col === location.col) && (endLocation.row === location.row)) {
				// 如果当前位置是结束位置，则返回true
				return true;
			}
			// 否则把当前位置的右边方块为新的当前位置
			location = goRight(location);
			console.log(location);
			step++;
		} else {
			// 否则为当前位置不能通过的情况
			if (stack.length !== 0) {
				// 当前位置出栈
				stack.pop();
				step--;
				while ((location.flag === 4) && (stack.length !== 0)) {
					// 留下不能再通过的标记，并且退回一步
					mymaze[location.col][location.row] = 1;
					stack.pop();
					step--;
				}
				if (location.flag < 4) {
					location.flag++;
					step++;
					stack.push(location);
					location = go(location);
				}
			}
		}
	} while (stack.length !== 0);
	return false;
}
console.log(maze(startLocation, endLocation));