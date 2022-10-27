import styled from "styled-components";

export const Wrapper = styled.div`
    width:100%;
    /* height:calc(100vh - 80px); */
    /* min-height:calc(100vh - 80px); */
    display:flex;
    justify-content:center;
    margin-top:40px;
`

export const InnerWrapper = styled.div`
    width:90%;
    min-height:calc(100vh - 80px);
    display:flex;
`

const Area = styled.div`
    width:50%;
    
    display:flex;
    flex-direction:column;
    height:100%;
    overflow-y:auto;
`
export const InputArea = styled(Area)`
    
    *{
        ::placeholder{color:lightgray;}
    }
    textarea{
        resize:none;
        border:none;
        outline:none;
        font-family:'Tahoma';
    }
    padding-right:30px;

`
export const ResultArea = styled(Area)`
    padding-left:30px;
    display:flex;
    flex-direction:column;
`


export const LatTemp = styled.div`
    height:1px;
    background-color:lightgray;
    width:44%;
`
export const LngTemp = styled.div`
    height:95%;
    width:1.5px;
    background-color:lightgray;
`



export const InputTitle = styled.textarea`
    font-size:50px;
    height:70px;
    font-weight:bold;
    
    transition:all 0s;
`
export const InputBook = styled.textarea`
    margin:10px 0px;
    font-size:25px;
    font-weight:bold;
    height:38px;
    transition:all 0s;
`
export const InputContent = styled.textarea`
    margin:20px 0px;
    font-size:20px;
    font-weight:normal;
    transition:all 0s;
    // 70이하일 때 계산 필요
    height:30px;
`


export const ResultTitle = styled.h1`
    font-size:50px;
    height:fit-content;
    font-weight:bold;
    margin:0px;
    
`
export const ResultBook = styled.h3`
    height:fit-content;
    margin:10px 0px;
    font-size:25px;
    font-weight:bold;
`
export const ResultContent = styled.p`
    margin:20px 0px;
    font-size:20px;
    font-weight:500;
    height:fit-content;
`