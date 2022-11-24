import React from 'react';
import * as C from "./CustomSubmitButton.style"

const CustomSubmitButton = ({text}) => {
    return (
        <C.Wrapper>
            {text}
        </C.Wrapper>
    );
};

export default CustomSubmitButton;