// 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
// 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
// 重复第二步，直到所有元素均排序完毕。
function selectionSort(arr) {
	var len = arr.length;
	var minIndex;
	for (var i = 0; i < len - 1; i++) {
		minIndex = i;
		// 找到最小的数
		for (var j = i + 1; j < len; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		[arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
	}
	return arr;
}
console.log(selectionSort([3, 7, 1, 4, 9, 2]));