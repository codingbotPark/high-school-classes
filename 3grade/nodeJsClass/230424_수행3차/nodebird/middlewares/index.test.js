const {isLoggedIn, isNotLoggedIn} = require('./')

// req,res,next가 필요하다
// 이 미들웨어를 확인하려면 next함수가 실행되었는지를 확인해야한다
describe('isLoggedIn',()=>{
    const res = {
        status:jest.fn(() => res),
        send:jest.fn(),
        write:jest.fn(() => {})
    }
    const next = jest.fn();

    test('로그인되어 있으면 isLoggedIn이 next를 호출해야 함', () => {
        const req = { // 로그인 한 것을 모킹
            isAuthenticated:jest.fn(() => true),
        }
        isLoggedIn(req,res,next)
        expect(next).toBeCalledTimes(1);
    })
    test('로그인되어 있지 않으면 isLoggedIn이 next를 호출해야 함', () => {
        const req = { // 로그인 하지 않은 것을 모킹
           isAuthenticated:jest.fn(() => false),
        }
        isLoggedIn(req,res,next);
        // expect(res.status).toBeCallWith(403);
        // expect(res.send).toBeCalledWith('로그인 필요');
        expect(res.write).toBeCalledWith("<script>window.location=\"/\";alert('need login')</script>")
    })
})

describe('isNotLoggedIn', () => {
   const res = {
    redirect:jest.fn(() => {})

   }
   const next = jest.fn()

    test('로그인되어 있으면 isNotLoggedIn이 에러를 응답해야 함', () => {
        const req = {
            isAuthenticated:jest.fn(() => true)
        }
        isNotLoggedIn(req,res,next)

        expect(res.redirect)
        .toBeCalledWith(`/?error=${encodeURIComponent("로그인한 상태입니다")}`)
    })
    test('로그되어 있지 않으면 isNotLoggedIn이 next를 호출해야 함',() => {
        const req = {
            isAuthenticated:jest.fn(() => false),
        }
        isNotLoggedIn(req,res,next)
        expect(next).toBeCalledTimes(1)
    })
})