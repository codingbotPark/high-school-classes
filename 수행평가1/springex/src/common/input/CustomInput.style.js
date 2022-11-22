import styled, { css } from "styled-components";

export const Wrapper = styled.div`
    width:100%;
    height:40px;
    /* border-bottom:2px lightgray solid; */
    display:flex;
    flex-direction:column;
    justify-content:center;
    position:relative;
    padding-top:10px;
`
export const PlaceHolder = styled.div`
    font-size:13px;
    position:absolute;
    color:lightgray;
    ${(props) => props.isFill && css`
        font-size:11px;
        top:0px;
        left:0px;
    `}
`

export const Input = styled.input`
    width:100%;
    /* height:auto; */
    height:30px;
    padding:0px;
    border-bottom:2px solid ${(props) => props.isFill ? "black" : "lightgray"};
    
`