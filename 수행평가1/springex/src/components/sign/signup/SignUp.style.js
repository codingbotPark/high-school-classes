import styled from "styled-components"

export const Wrapper = styled.div`
    width:70vw;
    max-width:500px;
    aspect-ratio: 1 / 1.3;
    background-color:white;
    border-radius:15px;
    display:flex;
    flex-direction:column;
    justify-content:space-between;
    align-items:center;
`
export const InputWrapper = styled.div`
    height:170px;
    width:60%;
    display:flex;
    flex-direction:column;
    justify-content:space-between;
    align-items:center;
`

export const ImgWrapper =styled.div`
    width:150px;
    height:150px;
    background-color:black;
    margin-top:60px;
    @media (max-width:550px) {
        width:100px;
        height:100px;
        margin-top:35px;
    }
`

export const ButtonWrapper =styled.div`
    width:45%;
    height:60px;
    margin-bottom:60px;
    background-color:black;

    @media (max-width:550px){
        width:100%;
        margin-bottom:0px;
    }
`