import React, { useEffect } from "react";
import * as M from "./Modal.style";

import Portal from "../Portal";

import close from "../../assets/modal/close.svg";

const Modal = ({
  
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

  return (
    <Portal elementId="modal-root">
      <M.ModalBackground>
        
      </M.ModalBackground>
      {/* <M.ModalOverlay
      onMouseDown={() => {console.log("클릭됨")}}
       tabIndex="-1">
        <M.ModalWrapper tabIndex="0">
          <M.Header>
            <img src={close} alt="모달 닫기" onClick={() => onClose()} />
          </M.Header>
          {children}
        </M.ModalWrapper>
      </M.ModalOverlay> */}
    </Portal>
  );
};

export default Modal;
