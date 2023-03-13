outer:
for (let i = 0;i<100;i++){
    for (let j = 0 ;j<100;j++){
        if (j == 5){break outer}
        console.log(j)
    }
}