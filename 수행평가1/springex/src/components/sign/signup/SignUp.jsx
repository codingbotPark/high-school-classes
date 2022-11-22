import React from 'react';
import * as S from "./SignUp.style"

import CustomInput from '../../../common/input/CustomInput';
import { useState } from 'react';

const SignUp = () => {
    const [id,setId] = useState("");

    return (
        <S.Wrapper>
            <CustomInput
                placeholder="아이디"
                setter={setId}
            />
        </S.Wrapper>
    );
};

export default SignUp;