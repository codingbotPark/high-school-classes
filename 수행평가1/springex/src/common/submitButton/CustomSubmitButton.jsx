import React from 'react';
import * as C from "./CustomSubmitButton.style"

const CustomSubmitButton = ({
    text,
    disable=false,
    type="button"
}) => {
    return (
        <C.Wrapper type={type} disabled={disable}>
            {text}
        </C.Wrapper>
    );
};

export default CustomSubmitButton;