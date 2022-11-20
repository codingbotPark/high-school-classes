import styled from "styled-components";

export const ModalOverlay = styled.div`
  box-sizing: border-box;
  position: fixed;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  background-color: rgba(0, 0, 0, 0.6);
  display: flex;
  justify-content: center;
  align-items: Center;
  z-index: 4;
`;

export const ModalWrapper = styled.div`
  display: flex;
  flex-direction: column;
  z-index: 5;
`;

export const Header = styled.header`
  width: 100%;
  height: 46px;
  background-color: ${(props) => props.theme.background};
  border-radius: 15px 15px 0px 0px;
  display: flex;
  justify-content: flex-end;
  align-items: Center;
  img {
    width: 35px;
    cursor: pointer;
    margin-right: 5px;
  }
`;

// ---------

export const ModalBackground = styled.div`
  position: absolute;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  background-color: rgba(0, 0, 0, 0.6);
`;
