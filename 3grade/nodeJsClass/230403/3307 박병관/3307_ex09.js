/**
 * 다음 코드는 일부 기능은 정상 동작하지만 arr.length를 사용할 수 없는 문제점이 있다.
 * 주어진 코드의 마지막 줄 console.log(obj.arr.length); 가 3으로 정상 출력되도록
 * for 문 이전의 코드를 수정하라.
 * 단, 객체나 property의 이름. for문과 출력문은 수정하지 않는다.
 */

const obj = {
  arr: [],
};
obj.arr[0] = 0;
obj.arr[1] = 1;
obj.arr[2] = 2;

// 이 코드는 예상했던 출력이 나오지만
for (let i = 0; i < 3; i++) console.log(obj.arr[i]);

// 이 부분이 정상 출력되지 않는다.
// 위의 for 문도 동작하고
// 다음 출력이 3 이 나오도록 for 문 앞의 코드를 수정하라.
console.log(obj.arr.length);
