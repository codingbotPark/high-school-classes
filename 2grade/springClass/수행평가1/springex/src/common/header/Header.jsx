import React, { useState } from "react";
import { Link, useNavigate } from "react-router-dom";
import * as H from "./Header.style";

import profile from "../../assets/header/profile.svg";
import Modal from "../modal/Modal";
import DropDownButtons from "../../common/dropDownButtons/DropDownButtons"
import Sign from "../../components/sign/Sign";
import { useEffect } from "react";

import menuProfile from "../../assets/header/menuProfile.svg"
import customAxios from "../../util/customAxios";
import { useRecoilState } from "recoil";

import { userName } from "../../global/userName";

const Header = () => {
  const [modalIsOpen, setModalIsOpen] = useState(false);
  const [dropDown,setDropDown] = useState(false);
  const [name,setName] = useRecoilState(userName);

  useEffect(() => {
    checkUser();
  }, []);

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

  function onProfileClick(){
    if(name && localStorage.getItem("access_token")){
      setDropDown(true)
    } else {
      setModalIsOpen(true)
    }
  }

  const navigator = useNavigate()
  function onClickWriteButton(){
    if (name){
      navigator("/write")
    } else {
      alert("로그인이 필요한 서비스입니다")
      setModalIsOpen(true)
    }
  }

  useEffect(() => {
    console.log(dropDown);
  },[dropDown])

  function logOut(){
    setName("")
    localStorage.removeItem("access_token")
    setDropDown(false)
  }

  return (
    <H.Wrapper>
      <Link to="/">
        <H.Logo>똑서</H.Logo>
      </Link>
      <H.ProfileMenu>
          <H.Write
            onClick={onClickWriteButton}
          >글쓰기</H.Write>
        <H.Profile onClick={onProfileClick}>
          <img src={profile} alt="프로필" />
          { name &&
          <div>
            <b>{name}</b>
            <span>님</span>
          </div>
          }
          {
            dropDown && 
            <H.DropDown>
            <DropDownButtons 
            setter={setDropDown}
            left="-190px"
            top="7px"
            >
              <H.ProfileMenuWrapper>
                <H.MenuButton>
                  <Link to="/profile">
                    <img src={menuProfile} /><span>내 프로필</span>
                    </Link>
                  </H.MenuButton>
                  <hr></hr>
                  <H.MenuButton onClick={logOut}>
                    로그아웃
                  </H.MenuButton>
              </H.ProfileMenuWrapper>
            </DropDownButtons>
            </H.DropDown>
          }
        </H.Profile>
      </H.ProfileMenu>
      {modalIsOpen && (
        <Modal setter={setModalIsOpen}>
          <Sign setModalIsOpen={setModalIsOpen}  />
        </Modal>
      )}
    </H.Wrapper>
  );
};

export default Header;
