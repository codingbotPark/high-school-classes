import styled from "styled-components";

export const Wrapper = styled.footer`
    background-color:lightgray;
    height:100px;
    width:100%;
    color:gray;
    display:flex;
    justify-content:center;
    align-items:center;
`
export const Info = styled.div`
   display:flex;
   justify-content:space-between;
   align-items:center;
   width:500px;
   @media (max-width:700px) {
        width:300px;
   }
`

export const FooterImg = styled.img`
    width:40px;
    filter: invert(54%) sepia(0%) saturate(0%) hue-rotate(269deg) brightness(93%) contrast(91%);
`