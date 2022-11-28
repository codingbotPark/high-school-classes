import React, { useState, useEffect } from "react";
import * as S from "./SignForm.style";
import CustomButton from "../../../common/submitButton/CustomSubmitButton";

const SignForm = ({ children, text, onSubmitF, otherText, otherF }) => {
  const [disable, setDisable] = useState(false);

  async function onSubmit(e) {
    e.preventDefault();
    setDisable(true);
    await new Promise((r) =>
    setTimeout((r) => {
      onSubmitF();
      setDisable(false);
    }, 1000)
    );
  }

  return (
    <S.Wrapper
      onSubmit={onSubmit}
    >
      <S.ImgWrapper>
        <h1>똑서</h1>
        <h3>{text}</h3>
      </S.ImgWrapper>
      <S.InputWrapper>
        {children}
        <S.OtherWay onClick={otherF}>{otherText}</S.OtherWay>
      </S.InputWrapper>
      <S.ButtonWrapper>
        <CustomButton type="submit" text={text} disable={disable} />
      </S.ButtonWrapper>
    </S.Wrapper>
  );
};

export default SignForm;
