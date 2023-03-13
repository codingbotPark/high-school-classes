import React from 'react';
import * as M from "./MoreInfo.style"
import basicInfoImg from "../../assets/moreInfo/moreInfo.svg"
import { useState } from 'react';

const MoreInfo = ({
    width="auto",
    height="auto",
    img=basicInfoImg,
    infoText
}) => {
    // css의 display를 이용하지 않고, state를 사용함,
    // 준혁이형 같으면 의미상 state를 사용할거같다 함
    const [isHover,setIsHover] = useState(false)

    return (
        <M.Wrapper onMouseOver={() => setIsHover(true)} onMouseLeave={() => setIsHover(false)} >
            {isHover && <M.InfoHolder>{infoText}</M.InfoHolder>}
            <img width={width} src={img} />
        </M.Wrapper>
    );
};

export default MoreInfo;