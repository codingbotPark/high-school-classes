import React from 'react';
import * as D from "./DropDownButton.style"

const DropDownButtons = ({
    clickOutSide,
}) => {
    return (
        <D.Wrapper onBlur={clickOutSide}>
            
        </D.Wrapper>
    );
};

export default DropDownButtons;