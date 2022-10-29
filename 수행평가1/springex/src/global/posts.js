import {atom} from "recoil"

export const posts = atom({
    key:'posts',
    default:[
        {
        id:1,
        title:"하이",
        author:"박병관",
        time:"2022년 10월 29일 16시 42분",
        views:"100"
    },
]
})




