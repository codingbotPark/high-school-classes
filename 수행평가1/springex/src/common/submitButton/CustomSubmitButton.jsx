import React from 'react';
import * as C from "./CustomSubmitButton.style"

const CustomSubmitButton = ({text,disable}) => {
    return (
        <C.Wrapper disable={disable}>
            {text}
        </C.Wrapper>
    );
};

export default CustomSubmitButton;