import dumBook from "../../assets/main/dumBook.jpg";
import React from "react";
import * as P from "./PostView.style";

const PostView = ({ img, title, author, time, views }) => {
  return (
    <P.PostWrapper>
      {img && (
        <P.PostImgWrapper>
          {/* <P.PostImg src={typeof img && (typeof img === "string" ? img : URL.createObjectURL(img) )} /> */}
          <P.PostImg src={img} />
        </P.PostImgWrapper>
      )}

      <P.PostInfoWrapper>
        <P.PostInfoHeader>
          <P.PostInfoTitle>{title}</P.PostInfoTitle>
          <P.PostInfoAuthor>{author}</P.PostInfoAuthor>
        </P.PostInfoHeader>
        <P.PostInfoTemp />
        <P.PostInfoContent>
          <P.PostInfoTime>{time}</P.PostInfoTime>
          <P.PostInfoViews>조회수 {views}</P.PostInfoViews>
        </P.PostInfoContent>
      </P.PostInfoWrapper>
    </P.PostWrapper>
  );
};

export default PostView;
