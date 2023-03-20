const arr = [1,2,3]

// 문자열로 바뀐다
for(let i in arr){
    console.log(i+0)
}

for (let i of arr){
    console.log(i+0)
}