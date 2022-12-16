import React, { useEffect } from "react";
import * as M from "./Modal.style";

import Portal from "../Portal";

import close from "../../assets/modal/close.svg";
import userClickOutSide from "../../hooks/outSideClick/useClickOutSide";

const Modal = ({
  children,
  setter
}) => {
  useEffect(() => {
    document.body.style.cssText = `
    position: fixed; 
    top: -${window.scrollY}px;
    overflow-y: scroll;
    width: 100%;`;

    return () => {
      const scrollY = document.body.style.top;
      document.body.style.cssText = "";
      window.scrollTo(0, parseInt(scrollY || "0", 10) * -1);
    };
  }, []);

  // 모달 설정
  const [el, clickOutside] = userClickOutSide(setter);
  useEffect(() => {
    document.addEventListener('mousedown', clickOutside);
    return () => {
      document.removeEventListener('mousedown', clickOutside);
    };
  }, [clickOutside]);

  return (
    <Portal elementId="modal-root">
      <M.ModalBackground>
        <M.Modal ref={el}>
          {children}
        </M.Modal>
      </M.ModalBackground>
    </Portal>
  );
};

export default Modal;
