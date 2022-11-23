import React from "react";
import * as S from "./SignUp.style";

import CustomInput from "../../../common/input/CustomInput";
import { useState } from "react";
import CustomButton from "../../../common/button/CustomButton";

const SignUp = () => {
  const [id, setId] = useState("");

  return (
    <S.Wrapper>
      <S.ImgWrapper>
        <h1>똑서</h1>
        <h3>회원가입 하기</h3>
      </S.ImgWrapper>
      <S.InputWrapper>
        <CustomInput placeholder="닉네임" setter={setId} />
        <CustomInput placeholder="비밀번호" type="password" setter={setId} />
        <CustomInput
          placeholder="비밀번호 확인"
          type="password"
          setter={setId}
        />
      </S.InputWrapper>
      <S.ButtonWrapper>
        <CustomButton placeholder="제출" />
      </S.ButtonWrapper>
    </S.Wrapper>
  );
};

export default SignUp;
