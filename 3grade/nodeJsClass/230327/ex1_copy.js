const fs = require('fs').promises;

fs.copyFile('readme4.txt','writeme4.txt')
.then(() => {
    console.log("복사완료")
})
.catch((err) => {
    console.error(err);
})