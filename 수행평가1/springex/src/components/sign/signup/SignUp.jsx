import React from 'react';
import * as S from "./SignUp.style"

import CustomInput from '../../../common/input/CustomInput';
import { useState } from 'react';

const SignUp = () => {
    const [id,setId] = useState("");

    return (
        <S.Wrapper>
            <S.ImgWrapper>

            </S.ImgWrapper>
            <S.InputWrapper>
            <CustomInput 
            placeholder="닉네임"
            setter={setId}/>
            <CustomInput 
            placeholder="비밀번호"
            type="password"
            setter={setId}/>
            <CustomInput 
            placeholder="비밀번호 확인"
            type="password"
            setter={setId}/>
            </S.InputWrapper>
            <S.ButtonWrapper>
                
            </S.ButtonWrapper>
        </S.Wrapper>
    );
};

export default SignUp;