import React from 'react';
import { useContext } from 'react';
import { useState } from 'react';
import SignForm from '../signForm/SignForm';
import * as S from "./SignIn.style"

import {ModeSetterContext} from "../Sign"
import CustomInput from '../../../common/input/CustomInput';

const SignIn = () => {
    const modeSetter = useContext(ModeSetterContext)

    const [id,setId] = useState("");
    const [password,setPassword] = useState("");

    function onSubmit(){
        console.log("로그인")
    }

    /** 로그인이 아니면 회원가입 */
    function otherF(){
        modeSetter("signUp")
    }

    return (
        <SignForm
            text="로그인"
            onSubmitF={onSubmit}
            otherText="회원가입 하기"
            otherF={otherF}
        >
            <S.InputWrapper>
            <CustomInput
            placeholder="아이디"
            setter={setId}
            />
            <CustomInput
            placeholder="비밀번호"
            type="password"
            setter={setPassword}
            />
            </S.InputWrapper>
        </SignForm>
    );
};

export default SignIn;