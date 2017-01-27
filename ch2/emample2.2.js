// 例题2.2，合并线性表
var a = [3, 5, 8, 11];
var b = [2, 6, 8, 9, 11, 15, 20];
var c = [];
function merge(a, b) {
	var i = 0, j = 0;
	var k = 0;
	while((i < a.length) || (j < b.length)) {
		 if (a[i] <= b[j]) {
		 	c.push(a[i]);
		 	i++;
		 } else {
		 	c.push(b[j]);
		 	j++;
		 }
	}
}
merge(a, b);
console.log(c);