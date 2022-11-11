import React, { useEffect } from "react";
import * as M from "./Modal.style";

import Portal from "../Portal";

const Modal = ({ 
    name, 
    onClose, 
    maskCloseable, 
    children }) => {
  useEffect(() => {
    document.body.style.cssText = `
            position:fixed;
            top:-${window.scrollY}px`;
    return () => {
      const scrollY = document.body.style.top;
      document.body.style.cssText = ``;
      window.scrollTo(0, parseInt(scrollY || "0") * -1);
    };
  }, []);

  return (
    <Portal elementId="modal-root">
      <M.ModalOverlay></M.ModalOverlay>
    </Portal>
  );
};

export default Modal;
