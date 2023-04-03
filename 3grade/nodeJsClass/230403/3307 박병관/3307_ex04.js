/**
 * 0~9 사이의 난수를 생성하는 코드는 다음과 같다.
 * Math.floor(Math.random()*10);
 *
 * 위 코드를 이용하여 6이상의 수가 나올 때 까지 난수를 생성하고
 * 최초 발생한 6 이상의 수를 출력하는 코드를 작성하라.
 * 함수는 사용하지 않으며 반복문을 사용해서 구현한다.
 */


while(true){
    const randomNum = Math.floor(Math.random()*10);
    // console.log(randomNum)
    if (randomNum >= 6){
        console.log(randomNum)
        break;
    }
}