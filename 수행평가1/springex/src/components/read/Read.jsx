import React from "react";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import * as R from "./Read.style";

import { useRecoilState } from "recoil";
import { posts } from "../../global/posts";
import { useEffect } from "react";
import { useState } from "react";
import customAxios from "../../util/customAxios";
import { Link, useLocation } from "react-router-dom";

import config from "../../config/config.json";

import edit from "../../assets/read/edit.svg"

const Read = () => {
  const [post, setPost] = useState();

  const location = useLocation();
  const splitedURL = location.pathname.split("/");
  const postIndex = splitedURL[splitedURL.length - 1];
  useEffect(() => {
    customAxios
      .get(`/board/find/${postIndex}`)
      .then((result) => {
        const data = result.data;
        setPost({
          id: postIndex,
          title: data.title,
          bookName: data.bookName,
          content: data.content,
        });
      })
      .catch((error) => console.log(error));
  }, []);

  return (
    <R.Wrapper>
      {post && (
        <>
          <R.InnerWrapper>
            <R.Header>
              <R.TitleWrapper>
              <R.Title>{post.title}</R.Title>
              <Link to={`/edit/${postIndex}`} title="수정하기">
              <img src={edit} alt="수정"/>
              </Link>
              </R.TitleWrapper>
              <R.BookName>{post.bookName}</R.BookName>
            </R.Header>
            <R.RowTemp />
            <R.Article>
              <ReadmeParser content={post.content} />
            </R.Article>
          </R.InnerWrapper>
          <R.ClosingArea>
            <strong>이 글에 흥미가 생겼다면</strong>
            <R.ClosingImg
              src={`${config.server}/board/img/${post.id}`}
              alt="감상문 책"
            />
            <strong>을 직접 읽어보세요</strong>
          </R.ClosingArea>
          <R.CommentArea>
            <R.CommentTitle>댓글</R.CommentTitle>
          </R.CommentArea>
        </>
      )}
    </R.Wrapper>
  );
};

export default Read;
