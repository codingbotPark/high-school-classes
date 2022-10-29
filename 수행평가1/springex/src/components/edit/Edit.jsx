import React from 'react';
import { useLocation } from 'react-router-dom';
import * as E from "./Edit.style"

const Edit = () => {
    const location = useLocation();
    console.log(location.state.post)

    return (
        <E.Wrapper>
            
        </E.Wrapper>
    );
};

export default Edit;