import React, { useState } from "react";
import { Link } from "react-router-dom";
import * as H from "./Header.style";

import profile from "../../assets/header/profile.svg";
import Modal from "../modal/Modal";
import Sign from "../../components/sign/Sign";
import { useEffect } from "react";

const Header = () => {
  const [modalIsOpen, setModalIsOpen] = useState(false);
  const [userName,setUserName] = useState("박병돤");

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

    } else {
        setModalIsOpen(true)
    }
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
          <div>
            {<b>{userName}</b>}
            <span>님</span>
          </div>
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
