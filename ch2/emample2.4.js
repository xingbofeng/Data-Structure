// 例题2.4，线性表的删除算法
var list = [12, 13, 21, 24, 28, 30, 42, 77];
function deleteItem(item, list, location) {
	if ((location >= list.length) || (location < 0)) {
		return false;
	}
	var result = [];
	for (var i = 0; i < list.length; i++) {
		if (i !== location) {
			result.push(list[i]);
		}
	}
	return result;
}
console.log(deleteItem(1, list, 3));