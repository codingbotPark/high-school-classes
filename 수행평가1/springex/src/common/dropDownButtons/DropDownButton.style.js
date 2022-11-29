import styled from "styled-components";

export const Wrapper = styled.div`
    position:absolute;
    top:${(props) => props.top};
    right:${(props) => props.right};
    bottom:${(props) => props.bottom};
    left:${(props) => props.left};
    /* left:-40px; */
`