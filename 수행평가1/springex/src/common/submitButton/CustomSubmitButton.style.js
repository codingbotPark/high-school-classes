import styled from "styled-components";

export const Wrapper = styled.input`
    width:100%;
    height:100%;
    border-radius:15px;
    background-color:${(props) => props.theme.main};
    display:flex;
    justify-content:center;
    align-items:center;
    color:${(props) => props.theme.titleFontColor};
    font-size:15px;
    cursor: pointer;
`