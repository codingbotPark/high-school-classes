import styled from "styled-components";

export const Wrapper = styled.form`
  width: 70vw;
  max-width: 500px;
  aspect-ratio: 1 / 1.3;
  background-color: white;
  border-radius: 15px;
  display: flex;
  flex-direction: column;
  justify-content: space-between;
  align-items: center;
`;

export const InputWrapper = styled.div`
  width: 60%;
  display: flex;
  flex-direction: column;
  /* margin-bottom:20px; */
`;

export const ImgWrapper = styled.div`
  margin-top: 80px;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;

  > h1 {
    font-weight: bold;
    font-size: 50px;
    margin:0px;
  }
  > h3 {
    margin:0px;
    font-size:25px;
  }
  @media (max-width: 550px) {
    width: 100px;
    height: 100px;
    margin-top: 35px;
  }
`;

export const ButtonWrapper = styled.div`
  width: 45%;
  height: 50px;
  margin-bottom:60px;
  border-radius:15px;
  @media (max-width: 550px) {
    border-radius:0px 0px 15px 15px;
    width: 100%;
    margin-bottom: 0px;
  }
`;


export const OtherWay =styled.b`
  margin-top:20px;
  width:100%;
  display:flex;
  justify-content:flex-end;
  cursor:pointer;
  color:${(props) => props.theme.main};
`