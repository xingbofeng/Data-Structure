// 从数列中挑出一个元素，称为 “基准”（pivot）;
// 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
// 在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作;
// 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序;
function quickSort(arr) {
	if (arr.length <= 1) {
		return arr;
	}
	var centerIndex = Math.ceil(arr.length / 2);
	var left = [],
		right = [];
	// 找到中间值，并且把中间值从数组中删掉。
	var center = arr.splice(centerIndex, 1);
	for (var i = 0; i < arr.length; i++) {
		if (arr[i] <= center) {
			left.push(arr[i]);
		} else {
			right.push(arr[i]);
		}
	}
	return quickSort(left).concat(center, quickSort(right));
}
console.log(quickSort([3, 7, 1, 4, 9, 2]));