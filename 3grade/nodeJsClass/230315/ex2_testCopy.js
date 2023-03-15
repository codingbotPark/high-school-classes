const arr = [1,2,3]
console.log(arr)
const arr1 = arr
arr1.pop()
console.log(arr)
console.log(arr1)


const arr2 = arr1.slice()
const arr3 = arr.slice()
console.log(arr2)
console.log(arr3)
