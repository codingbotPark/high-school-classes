import React, { useState } from "react";
import { Link } from "react-router-dom";
import * as H from "./Header.style";

import profile from "../../assets/header/profile.svg";
import Modal from "../modal/Modal";
import Sign from "../../components/sign/Sign";
import { useEffect } from "react";

const Header = () => {
  const [modalIsOpen, setModalIsOpen] = useState(false);

  useEffect(() => {
    // const value = localStorage.getItem("access_token");
    // if (!value) return;
    // // 서버에 유효성 검사
    // console.log("hi");

  }, []);

  function checkUser(){
    return false
  }

  function onProfileClick(){
    if(checkUser()){

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
        <H.Profile onClick={onProfileClick} src={profile}></H.Profile>
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
