import React, { useEffect } from "react";
import * as M from "./Modal.style";

import Portal from "../Portal";

import close from "../../assets/modal/close.svg"

const Modal = ({ onClose, maskCloseable, children }) => {

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



  return (
    <Portal elementId="modal-root" >
      <M.ModalOverlay
          onMouseDown={maskCloseable && onClose}
      >  
        <M.ModalWrapper>
        <M.Header>
          <button onClick={() => onClose()}>
            <img src={close} alt="모달 닫기" />
            </button>
          </M.Header>
        {children}
        </M.ModalWrapper>
      </M.ModalOverlay>
    </Portal>
  );
};

export default Modal;
