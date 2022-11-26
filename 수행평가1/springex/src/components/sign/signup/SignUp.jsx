import React, { useContext } from "react";
import * as S from "./SignUp.style";
import SignForm from "../signForm/SignForm";

import CustomInput from "../../../common/input/CustomInput";
import { useState } from "react";
import CustomButton from "../../../common/submitButton/CustomSubmitButton";

import api from "../../../util/customAxios"

import { ModeSetterContext } from "../Sign";

const SignUp = () => {
  const modeSetter = useContext(ModeSetterContext)

  const [id, setId] = useState("");
  const [password,setPassword] = useState("");

  function onSubmitF(){
    console.log("회원가입")
  }

  function otherF(){
    modeSetter("signIn")
  }

  return (
    <>
      <SignForm mode="signUp" text="회원가입 하기" onSubmitF={onSubmitF} otherText="로그인 하기" otherF={otherF}>
        <S.InputWrapper>
        <CustomInput placeholder="닉네임" setter={setId} />
        <CustomInput placeholder="비밀번호" type="password" setter={setId} />
        <CustomInput
          placeholder="비밀번호 확인"
          type="password"
          setter={setId}
        />
        </S.InputWrapper>
      </SignForm>
    </>
  );
};

export default SignUp;
