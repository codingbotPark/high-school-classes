import styled from "styled-components";

export const ModalBackground = styled.div`
  position: absolute;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  width:100vw;
  height:100vh;
  background-color: rgba(0, 0, 0, 0.6);
  display:flex;
  justify-content:center;
  align-items:center;
  z-index:10;
`;

export const Modal = styled.div`
  z-index:10;
`
