import React, { useContext } from "react";
import * as S from "./SignUp.style";
import SignForm from "../signForm/SignForm";

import CustomInput from "../../../common/input/CustomInput";
import { useState } from "react";
import CustomButton from "../../../common/submitButton/CustomSubmitButton";

import customAxios from "../../../util/customAxios"

import { ModeSetterContext } from "../Sign";

const SignUp = () => {
  const modeSetter = useContext(ModeSetterContext)

  const [nickName,setNickName] = useState("")
  const [password,setPassword] = useState("");
  const [passwordCheck,setPasswordCheck] = useState("");

  // 요소들의 유효성
  const [nickState,setNickState] = useState(false)
  const [passwordState,setPasswordState] = useState(false);
  const [passwordCheckState,setPasswordCheckState] = useState(false);


  function onSubmitF(){
    // 유효성 겁사 후 요소들 state 변경

    // customAxios.post("signup",{
    //   nickName,
    //   id,
    //   password
    // })

    console.log({
      nickName,
      password,
      passwordCheck
    })
  }

  function otherF(){
    modeSetter("signIn")
  }

  return (
    <>
      <SignForm mode="signUp" text="회원가입" onSubmitF={onSubmitF} otherText="로그인 하기" otherF={otherF}>
        <S.InputWrapper>
        <CustomInput 
        placeholder="아이디" 
        setter={setNickName} 
        somthingWrong={nickState}
        wrongMessage="아이디 형식에 맞지 않습니다"
        />
        <CustomInput 
        placeholder="비밀번호" 
        type="password" 
        setter={setPassword} 
        somthingWrong={passwordState || passwordCheckState}
        wrongMessage="비밀번호 형식에 맞지 않습니다"/>
        <CustomInput
          placeholder="비밀번호 확인"
          type="password"
          setter={setPasswordCheck}
          somthingWrong={passwordCheckState}
          wrongMessage="비밀번호가 일치하지 않습니다"/>
        </S.InputWrapper>
      </SignForm>
    </>
  );
};

export default SignUp;
