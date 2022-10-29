import dumBook from "../../assets/main/dumBook.jpg";
import React from "react";
import * as P from "./PostView.style"

const PostView = ({
    img,
    title,
    author,
    time,
    views
}) => {
  return (
    <P.PostWrapper>
      <P.PostImgWrapper>
        <P.PostImg src={img} />
      </P.PostImgWrapper>
      <P.PostInfoWrapper>
        <P.PostInfoHeader>
          <P.PostInfoTitle>{title}</P.PostInfoTitle>
          <P.PostInfoAuthor>{author}</P.PostInfoAuthor>
        </P.PostInfoHeader>
        <P.PostInfoTemp />
        <P.PostInfoContent>
          <P.PostInfoTime>{time}</P.PostInfoTime>
          <P.PostInfoViews>{views}</P.PostInfoViews>
        </P.PostInfoContent>
      </P.PostInfoWrapper>
    </P.PostWrapper>
  );
};

export default PostView;
