import React from "react";
import * as S from "./SignUp.style";
import SignForm from "../SignForm";

import CustomInput from "../../../common/input/CustomInput";
import { useState } from "react";
import CustomButton from "../../../common/submitButton/CustomSubmitButton";

const SignUp = () => {
  const [id, setId] = useState("");
  const [password,setPassword] = useState("");

  return (
    <>
      <SignForm text="회원가입" >
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
