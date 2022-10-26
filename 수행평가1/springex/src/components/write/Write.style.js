import styled from "styled-components";

export const Wrapper = styled.div`
    width:100%;
    height:calc(100vh - 80px);
    display:flex;
    justify-content:center;
    align-items:center;
    margin-top:40px;
`

export const InnerWrapper = styled.div`
    width:90%;
    min-height:100%;
    display:flex;
`

const Area = styled.div`
    width:50%;
    /* background-color:tomato; */
    min-height:100%;
    
    display:flex;
    flex-direction:column;
    min-height:100%;
`
export const InputArea = styled(Area)`
    
    *{
        ::placeholder{color:lightgray;}
    }
    textarea{
        resize:none;
        border:none;
        outline:none;
    }
    border-right:1px solid lightgray;
    padding-right:30px;

`
export const ResultArea = styled(Area)`
    padding-left:30px;
    display:flex;
    flex-direction:column;
`


export const InputTemp = styled.div`
    height:1px;
    background-color:lightgray;
    width:44%;
`





export const InputTitle = styled.textarea`
    font-size:50px;
    height:50px;
    height:65px;
    font-weight:bold;
    transition:all 0s;
`
export const InputBook = styled.textarea`
    margin:10px 0px;
    font-size:25px;
    font-weight:bold;
    height:35px;
    transition:all 0s;
`
export const InputContent = styled.textarea`
    margin:20px 0px;
    font-size:20px;
    font-weight:normal;
    transition:all 0s;
    // 70이하일 때 계산 필요
    height:28px;
    /* min-height:70%; */
`


export const ResultTitle = styled.h1`
    font-size:50px;
    height:65px;
    font-weight:bold;
    margin:0px;
`
export const ResultBook = styled.h3`
    margin:10px 0px;
    font-size:25px;
    font-weight:bold;
    height:35px;
`
export const ResultContent = styled.p`
    margin:20px 0px;
    font-size:20px;
    font-weight:normal;
`