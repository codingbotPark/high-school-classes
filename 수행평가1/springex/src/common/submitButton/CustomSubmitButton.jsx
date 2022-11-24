import React from 'react';
import * as C from "./CustomSubmitButton.style"

const CustomSubmitButton = ({text}) => {
    return (
        <C.Wrapper type="submit" placeholder={text}>
        </C.Wrapper>
    );
};

export default CustomSubmitButton;