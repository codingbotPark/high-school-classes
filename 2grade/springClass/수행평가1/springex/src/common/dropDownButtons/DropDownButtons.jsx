import React, { useEffect } from 'react';
import * as D from "./DropDownButton.style"

import useClickOutSide from '../../hooks/outSideClick/useClickOutSide';

/** 부모 태그가 position relative여야 함 */
const DropDownButtons = ({
    setter,
    children,
    top,
    right,
    bottom,
    left,
}) => {
    // outsideClick 설정
    const [el,clickOutSide] = useClickOutSide(setter);
    useEffect(() =>{
        document.addEventListener('mousedown',clickOutSide);
        return () => {
            document.removeEventListener('mousedown',clickOutSide);
        }
    },[clickOutSide])

    return (
        <D.Wrapper 
        ref={el}
        top={top}
        right={right}
        bottom={bottom}
        left={left}
        >
            {children}
        </D.Wrapper>
    );
};

export default DropDownButtons;