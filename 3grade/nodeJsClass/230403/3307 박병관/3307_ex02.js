/**
 * 0~9 사이의 난수를 생성하는 코드는 다음과 같다.
 * Math.floor(Math.random()*10);
 *
 * 위 코드를 이용하여 0~9 사이의 난수를 생성하고
 * 그 수가 짝수이면 "짝수", 홀수이면 "홀수" 라 출력하라.
 */

const randomNum = Math.floor(Math.random()*10);
console.log(randomNum)
if (randomNum % 2 === 0){
    console.log("짝수")
} else {
    console.log("홀수")
}