import styled from "styled-components";

export const Wrapper = styled.div`
  width: 100%;
  display: flex;
  flex-direction:column;
  align-items:center;
`;
export const InnerWrapper = styled.section`
  max-width: 900px;
  width: 70%;
  margin-top: 60px;
  min-height: calc(100vh - 180px);
`;

export const Header = styled.header``;
export const TitleWrapper = styled.div`
  display:flex;
  justify-content:space-between;
  align-items:center;
  margin: 10px 0px;
  >img{
    cursor:pointer;
    height:30px;
  }
`
export const Title = styled.h1`
  margin:0px;
  font-size: 50px;
`;
export const BookName = styled.h3`
  font-size: 23px;
  margin: 10px 0px;
`;

export const RowTemp = styled.div`
  height: 1px;
  width: 30%;
  background-color: lightgray;
  margin: 20px 0px;
`;

export const Article = styled.article`
  width: 100%;
`;

export const ClosingArea = styled.div`
  width: 100%;
  display: flex;
  align-items: center;
  justify-content: center;
  margin: 110px 0px;
  word-break:keep-all;
  font-size:20px;

  background-color:${(props) => props.theme.main};
  padding:30px 0px;
  > *{
  color:white;
  }
`;
export const ClosingImg = styled.img`
  height: 250px;

  object-fit: contain;
  margin: 0px 60px;
  @media (max-width: 1400px) {
    height: 200px;
  }
  @media (max-width: 900px) {
    height: 150px;
  }
`;

export const CommentArea = styled.div`
  margin: 0px 0px 100px 0px;
  border-radius: 15px;
  max-width: 900px;
  width: 70%;
  height: 100px;
  box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.1);
  display: flex;
  flex-direction: column;
`;
export const CommentTitle = styled.h2`
  margin: 20px 20px;
`;
