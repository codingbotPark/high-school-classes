import React, { useEffect } from 'react';
import { useState } from 'react';
import MoreInfo from '../moreInfo/MoreInfo';
import * as C from "./CustomInput.style"

const CustomInput = ({
    placeholder,
    type="text",
    setter,
    somthingWrong=false,
    wrongMessage=""
}) => {
    const [filled,setFilled] = useState(false)

    function changeHandle(e){
        setter(e.target.value)
        setFilled(e.target.value.length > 0)
    }

    return (
        <C.Wrapper>
            <C.PlaceHolder 
            isFill={filled} 
            somthingWrong={somthingWrong}
            >
                {placeholder}
                {somthingWrong && 
                <C.InfoHolder>
                <MoreInfo width={15} infoText={wrongMessage} />
                </C.InfoHolder>
                }
                </C.PlaceHolder>
            <C.Input 
            isFill={filled} 
            onChange={(e) => changeHandle(e)} 
            type={type} 
            somthingWrong={somthingWrong}
            />
        </C.Wrapper>
    );
};

export default CustomInput;