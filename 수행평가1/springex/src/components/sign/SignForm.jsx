import React from 'react';
import * as S from "./SignForm.style"
import CustomButton from '../../common/submitButton/CustomSubmitButton';

const signForm = ({
    children,
    text
}) => {
    return (
        <S.Wrapper>
        <S.ImgWrapper>
          <h1>똑서</h1>
          <h3>회원가입 하기</h3>
        </S.ImgWrapper>
        <S.InputWrapper>
          {children}
        </S.InputWrapper>
        <S.ButtonWrapper>
          <CustomButton text={text} />
        </S.ButtonWrapper>
      </S.Wrapper>
    );
};

export default signForm;