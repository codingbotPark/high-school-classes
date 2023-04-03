/**
 * 주어진 배열 arr과 배열의 내장 함수를 이용해 다음 기능을 구현하라.
 * 1. arr의 값 중 1 이상인 값만 골라 positive 배열에 저장.
 * 2. positive 배열의 모든 값을 console.log로 출력
 *
 * 배열의 내장 함수가 아닌 다른 반복분은 사용하지 않는다.
 */

const arr = [-3, -2, -1, 0, 1, 2, 3];

const position = arr.filter((i) => i >= 1)
position.forEach((i) => {console.log(i)})