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
    cursor:pointer;
    @media (max-width:700px){
        margin-right:25px;
    }
`

export const DropDown = styled.div`
    z-index:10;
    position:relative;
    border-radius:15px;
`

export const ProfileMenuWrapper = styled.div`
    background-color:white;
    width:230px;
    border-radius:15px;
    box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.1);
    >hr{
        border:solid 0.5px #DCDCDC;
        margin:0px;
    }
`
export const MenuButton = styled.button`
    width:100%;
    height:50px;
    display:flex;
    justify-content:flex-start;
    align-items:center;
    color:${(props) => props.theme.fontColor};
    cursor: pointer;
    border:0px;
    :first-child{border-radius:15px 15px 0px 0px;}
    :last-child{border-radius:0px 0px 15px 15px;}
    :hover{
        background-color:whitesmoke;
    }
    img{
        width:22px;
        margin:0px 5px 0px 5px;
    }
    *{color:${(props) => props.theme.fontColor};}
    *{display:inherit; justify-content:inherit; align-items:inherit;}
`