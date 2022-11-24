import React, { useState } from 'react';
import * as S from "./SignForm.style"
import CustomButton from '../../common/submitButton/CustomSubmitButton';

const SignForm = ({
    mode,
    children,
    text,
    onSubmitF
}) => {

    const [disable,setDisable] = useState(false);

    return (
        <S.Wrapper onSubmit={(e) => {
          setDisable(true);

          e.preventDefault();
          onSubmitF();

          setDisable(false)
        }}>
        <S.ImgWrapper>
          <h1>똑서</h1>
          <h3>{text}</h3>
        </S.ImgWrapper>
        <S.InputWrapper >
          {children}
        </S.InputWrapper>
        <S.ButtonWrapper>
          <CustomButton text={text} disable={disable} />
        </S.ButtonWrapper>
        
      </S.Wrapper>
    );
};

export default SignForm;