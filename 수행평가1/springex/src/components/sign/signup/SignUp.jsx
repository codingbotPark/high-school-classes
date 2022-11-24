import React from "react";
import * as S from "./SignUp.style";
import SignForm from "../SignForm";

import CustomInput from "../../../common/input/CustomInput";
import { useState } from "react";
import CustomButton from "../../../common/submitButton/CustomSubmitButton";

import api from "../../../util/customAxios"

const SignUp = () => {
  const [id, setId] = useState("");
  const [password,setPassword] = useState("");

  function onSubmitF(){
    // api.post()
    console.log("회원가입")
  }

  return (
    <>
      <SignForm mode="signUp" text="회원가입 하기" onSubmitF={onSubmitF} >
        <CustomInput placeholder="닉네임" setter={setId} />
        <CustomInput placeholder="비밀번호" type="password" setter={setId} />
        <CustomInput
          placeholder="비밀번호 확인"
          type="password"
          setter={setId}
        />
      </SignForm>
    </>
  );
};

export default SignUp;
