import React, { useState } from "react";
import { Link } from "react-router-dom";
import * as H from "./Header.style";

import profile from "../../assets/header/profile.svg";
import Modal from "../modal/Modal";
import DropDownButtons from "../../common/dropDownButtons/DropDownButtons"
import Sign from "../../components/sign/Sign";
import { useEffect } from "react";

import menuProfile from "../../assets/header/menuProfile.svg"

const Header = () => {
  const [modalIsOpen, setModalIsOpen] = useState(false);
  const [dropDown,setDropDown] = useState(false);
  const [userName,setUserName] = useState("병관");

  useEffect(() => {
    // const value = localStorage.getItem("access_token");
    // if (!value) return;
    // // 서버에 유효성 검사
    // console.log("hi");
    
  }, []);

  // 로그인 유무
  function checkUser(){
    return false
  }

  function onProfileClick(){
    if(userName){
      setDropDown(true)
    } else {
      setModalIsOpen(true)
    }
  }

  function logOut(){
    
  }

  return (
    <H.Wrapper>
      <Link to="/">
        <H.Logo>똑서</H.Logo>
      </Link>
      <H.ProfileMenu>
        <Link to="/write">
          <H.Write>글쓰기</H.Write>
        </Link>
        <H.Profile onClick={onProfileClick}>
          <img src={profile} alt="프로필" />
          { userName &&
          <div>
            <b>{userName}</b>
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
          <Sign />
        </Modal>
      )}
    </H.Wrapper>
  );
};

export default Header;
