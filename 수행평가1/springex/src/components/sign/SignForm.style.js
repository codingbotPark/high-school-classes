import styled from "styled-components";

export const Wrapper = styled.div`
  width: 70vw;
  max-width: 500px;
  aspect-ratio: 1 / 1.3;
  background-color: white;
  border-radius: 15px;
  display: flex;
  flex-direction: column;
  /* justify-content: space-between; */
  justify-content:space-around;
  align-items: center;
`;
export const InputWrapper = styled.form`
  height: 170px;
  width: 60%;
  display: flex;
  flex-direction: column;
  justify-content: space-between;
  align-items: center;
  /* margin-bottom:20px; */
`;

export const ImgWrapper = styled.div`
  margin-top: 60px;
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
  margin-bottom: 30px;

  @media (max-width: 550px) {
    width: 100%;
    margin-bottom: 0px;
  }
`;
