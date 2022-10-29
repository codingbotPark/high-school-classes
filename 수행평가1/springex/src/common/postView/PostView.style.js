import styled from "styled-components";

export const PostWrapper = styled.div`
    width:300px;
    height:300px;
    display:flex;
    flex-direction:column;
    justify-content:flex-end;
    /* float:bottom; */
    position:relative;
    :hover{
        transform:translateY(-10px);
    }
    cursor:pointer; 
`
export const PostImgWrapper = styled.div`
    width:100%;
    height:100%;
    display:flex;
    justify-content:center;
    position:absolute;
    /* background-color:powderblue; */
`
export const PostImg = styled.img`
    /* width:0%; */
    height:100%;
`

export const PostInfoWrapper = styled.div`
    z-index:1;
    width:100%;
    height:55%;
    box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.1);
    border-radius:15px;
    background-color:${(props) => props.theme.background};
    
    display:flex;
    flex-direction:column;
    justify-content:space-between;

    padding:13px 18px;

    *{
        margin:0px;
    }

`

export const PostInfoHeader = styled.div`
    height:80%;
    display:flex;
    flex-direction:column;
    justify-content:space-between;
`
export const PostInfoTitle = styled.h1`
    margin:0px;
    font-size:large;
`
export const PostInfoAuthor = styled.p`
    margin-bottom:10px;
    font-size:14px;
`

export const PostInfoTemp = styled.div`
    height:1px;
    background-color:lightgray;
`

export const PostInfoContent = styled.div`
    height:20%;
    display:flex;
    justify-content:space-between;
    align-items:center;
    font-size:14px;
    margin-top:2px;
`
export const PostInfoTime = styled.div`

`
export const PostInfoViews = styled.div`

`