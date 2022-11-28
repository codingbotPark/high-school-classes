import styled, { css } from "styled-components";

export const Wrapper = styled.div`
    width:100%;
    height:45px;
    /* border-bottom:2px lightgray solid; */
    display:flex;
    flex-direction:column;
    justify-content:center;
    position:relative;
    padding-top:13px;
`
export const PlaceHolder = styled.div`
    font-size:13px;
    position:absolute;
    color:${(props) => props.somthingWrong ? "indianred" : "gray"};
    /* color:lightgray; */
    top:20px;
    left:0px;
    ${(props) => props.isFill && css`
        font-size:11px;
        top:0px;
        left:0px;
    `}
    display:flex;
    align-items:center;
`

export const InfoHolder = styled.div`
    margin-left:6px;
`

export const Input = styled.input`
    width:100%;
    /* height:auto; */
    height:30px;
    padding:0px;
    border-bottom:2px solid ${(props) => {
        if (props.somthingWrong){
            return "indianred";
        } else if (props.isFill) {
            return "black";
        } else {
            return "lightgray";
        }
    }};
    
`