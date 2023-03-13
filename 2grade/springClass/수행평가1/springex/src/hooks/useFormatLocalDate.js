// useFormatLocalDate를 사용하면 formatLocalDate라는 함수를 선언하는 꼴이 된다
const useFormatLocalDate = () => function formatLocalDate(localDate){
    if (localDate){
    const splitedDate = localDate.split("T")
    const frontOne = splitedDate[0].split("-")
    const backOne = splitedDate[1].split(":")
    return `${frontOne[0]}년${frontOne[1]}월${frontOne[2]}일 ${backOne[0]}시${backOne[1]}분`
    }
}

export default useFormatLocalDate