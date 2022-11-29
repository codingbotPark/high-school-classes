import styled from "styled-components";

export const Wrapper = styled.header`
    width:100%;
    height:80px;
    background-color:${(props) => props.theme.main};
    display:flex;
    justify-content:space-between;
    align-items:center;
`
export const Logo = styled.h1`
    /* color:white; */
    color:${(props) => props.theme.titleFontColor};
    margin-left:50px;
`

export const ProfileMenu = styled.div`
    display:flex;
    align-items:center;
`
export const Profile = styled.div`
    margin-right:70px;
    @media (max-width:700px) {
        margin-right:30px;    
    }
    cursor:pointer;

    display:flex;
    flex-direction:column;
    align-items:center;
    *{
        font-size:14px;
        color:${(props) => props.theme.titleFontColor};
    }
`
export const Write = styled.div`
    color:${(props) => props.theme.titleFontColor};
    margin-right:40px;
    @media (max-width:700px){
        margin-right:25px;
    }
`