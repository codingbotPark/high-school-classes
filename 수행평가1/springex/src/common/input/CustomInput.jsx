import React, { useEffect } from 'react';
import { useState } from 'react';
import * as C from "./CustomInput.style"

const CustomInput = ({
    placeholder,
    type="text",
    setter,
}) => {
    const [filled,setFilled] = useState(false)

    function changeHandle(e){
        setter(e.target.value)
        setFilled(e.target.value.length > 0)
    }

    return (
        <C.Wrapper>
            <C.PlaceHolder isFill={filled} >{placeholder}</C.PlaceHolder>
            <C.Input isFill={filled} onChange={(e) => changeHandle(e)} type={type} />
        </C.Wrapper>
    );
};

export default CustomInput;