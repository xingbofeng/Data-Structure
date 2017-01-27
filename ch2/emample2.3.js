// 例题2.3，线性表的插入算法
var list = [12, 13, 21, 24, 28, 30, 42, 77];
function insert(item, list, location) {
	if ((location >= list.length) || (location < 0)) {
		return false;
	}
	var result = [];
	for (var i = 0; i <= list.length; i++) {
		if (i === location) {
			result.push(item);
		} else if (i < location) {
			result.push(list[i]);
		} else {
			result.push(list[i - 1]);
		}
	}
	return result;
}
console.log(insert(1, list, 3));