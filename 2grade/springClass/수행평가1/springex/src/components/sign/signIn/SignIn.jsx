import React from 'react';
import { useContext } from 'react';
import { useState } from 'react';
import SignForm from '../signForm/SignForm';

import {ModeSetterContext,ModalSetterContext} from "../Sign"
import CustomInput from '../../../common/input/CustomInput';
import customAxios from '../../../util/customAxios';
import { useRecoilState } from 'recoil';

import { userName } from '../../../global/userName';

const SignIn = () => {
  const modalSetter = useContext(ModalSetterContext)
    const modeSetter = useContext(ModeSetterContext)

    const [name,setName] = useRecoilState(userName);

    const [id,setId] = useState("");
    const [password,setPassword] = useState("");

    function onSubmit(){

        customAxios.post("/user/login",{
            email: id,
            password: password
          },
          )
          .then((response) => {
            console.log(response.data)
            localStorage.setItem("access_token",response.data)
            modalSetter(false)
            checkUser();
          })
          .catch((err) => alert("아이디 또는 비밀번호가 잘못됐습니다"))
        console.log(id,password)
    }

    /** 로그인이 아니면 회원가입 */
    function otherF(){
        modeSetter("signUp")
    }

      // 로그인 유무
  function checkUser(){
    const token = localStorage.getItem("access_token")
    customAxios.post("/user/name",{
      token
    })
    .then((response) => {
      console.log(response)
      setName(response.data)
    })
    .catch((error) => {
      localStorage.removeItem("access_token")
      console.log(error)
    })
  }

    return (
        <SignForm
            text="로그인"
            onSubmitF={onSubmit}
            otherText="회원가입 하기"
            otherF={otherF}
        >
            <CustomInput
            placeholder="아이디"
            setter={setId}
            />
            <CustomInput
            placeholder="비밀번호"
            type="password"
            setter={setPassword}
            />
        </SignForm>
    );
};

export default SignIn;