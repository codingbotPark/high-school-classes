
import styled from "styled-components";

export const Wrapper = styled.div`
    width:100%;
    min-height:calc(100vh - 180px);
    display:flex;
    justify-content:center;
`
export const InnerWrapper = styled.section`
    max-width:900px;
    width:70%;
    margin-top:60px;
`

export const Header = styled.header`

`
export const Title = styled.h1`
    font-size:50px;
    margin:10px 0px;
`
export const BookName = styled.h3`
    font-size:23px;
    margin:10px 0px;
`

export const RowTemp = styled.div`
    height:1px;
    width:70%;
    background-color:lightgray;
    margin:20px 0px;
`

export const Article = styled.article`
    width:100%;
`

export const CommentArea = styled.div`
    margin:100px 0px;
    border-radius:15px;
    width:100%;
    height:100px;
    box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.1);
    display:flex;
    flex-direction:column;

`
export const CommentTitle = styled.h2`
    margin:20px 20px;
`
