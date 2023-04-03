/**
 * 다음에서 지시한 내용으로 객체 user 의 코드를 완성하라.
 * name 이라는 문자열 property를 추가하라. 값은 'user'이다.
 * getRole 이라는 함수를 추가하라. 파라미터는 받지 않으며 'user'를 반환한다.
 */

// 이 객체를 완성하라.
const user = {
  id: 123,
  name:"user",
  getRole(){
    return "user"
  }
};

// 코드를 완성했다면 아래 코드가 각각 user를 출력해야 한다.
console.log(user.name);
console.log(user.getRole());
