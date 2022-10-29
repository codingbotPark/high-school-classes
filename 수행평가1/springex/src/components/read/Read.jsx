import React from "react";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import * as R from "./Read.style";

import { useRecoilState } from "recoil";
import { posts } from "../../global/posts";
import { useEffect } from "react";
import { useState } from "react";
import customAxios from "../../util/customAxios";
import { useLocation } from "react-router-dom";

import config from "../../config/config.json"

const Read = () => {
  const [post, setPost] = useState();

  const location = useLocation()
  
  useEffect(() => {
    const splitedURL = location.pathname.split("/")
    const postIndex = splitedURL[splitedURL.length -1]
    customAxios.get(`/board/find/${postIndex}`)
    .then((result) => {
      const data = result.data
      setPost({
        id:postIndex,
        title:data.title,
        bookName:data.bookName,
        content:data.content,
      })
    })
    .catch((error) => console.log(error))
  }, []);

  return (
    <R.Wrapper>
      {post && (
        <R.InnerWrapper>
          <R.Header>
            <R.Title>{post.title}</R.Title>
            <R.BookName>{post.bookName}</R.BookName>
          </R.Header>
          <R.RowTemp />
          <R.Article>
            <ReadmeParser content={post.content} />
          </R.Article>
          
          <R.ClosingArea>
            <strong>
            이 글에 흥미가 생겼으면
            </strong>
            <R.ClosingImg src={`${config.server}/board/img/${post.id}`} alt="감상문 책" />
            <strong>
            를 직접 보세요
            </strong>
          </R.ClosingArea>

          {/* <R.CommentArea>
            <R.CommentTitle>댓글</R.CommentTitle>
          </R.CommentArea> */}
        </R.InnerWrapper>
      )}
    </R.Wrapper>
  );
};

export default Read;
