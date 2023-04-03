/**
 * ex10-2.js 에 getName 함수를 정의하라.
 * 함수는 파라미터 없이 'user'를 반환한다.
 * getName 함수는 다른 모듈에서 불러 쓸 수 있도록 하라.
 *
 * ex10-2.js 모듈을 이 파일에서 불러
 * 다음과 같이 콘솔 출력할 수 있도록 코드를 완성하라.
 */

// ex10-2 모듈을 부르는 코드 작성
const getName = require("./3307_ex10-2")

// 다음 코드를 수정하지 말 것.
console.log(getName());
