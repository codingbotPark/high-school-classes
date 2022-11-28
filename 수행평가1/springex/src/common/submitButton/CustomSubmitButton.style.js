import styled from "styled-components";

export const Wrapper = styled.button`
    width:100%;
    height:100%;
    /* border-radius:15px; */
    border-radius:inherit;
    background-color:${(props) => props.theme.main};
    display:flex;
    justify-content:center;
    align-items:center;
    color:${(props) => props.theme.titleFontColor};
    font-size:15px;
    cursor: pointer;

    :disabled{
        background-color:lightgray;
    }
`