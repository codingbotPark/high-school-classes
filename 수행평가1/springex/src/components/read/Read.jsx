import React from "react";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import * as R from "./Read.style";

import { useRecoilState } from "recoil";
import { posts } from "../../global/posts";
import { useEffect } from "react";
import { useState } from "react";
import customAxios from "../../util/customAxios";
import { Link, useLocation, useNavigate } from "react-router-dom";

import config from "../../config/config.json";

import edit from "../../assets/read/edit.svg"

import useFormatLocalDate from "../../hooks/useFormatLocalDate"

import goBack from "../../assets/read/leftArrow.svg"

const Read = () => {
  const [post, setPost] = useState();

  const location = useLocation();
  const splitedURL = location.pathname.split("/");
  const postIndex = splitedURL[splitedURL.length - 1];
  const formatLocalDate = useFormatLocalDate()
  useEffect(() => {
    customAxios
      .get(`/board/find/${postIndex}`)
      .then((result) => {
        const data = result.data;
        console.log(data);
        setPost({
          id: postIndex,
          title: data.title,
          bookName: data.bookName,
          content: data.content,
          writer:data.writer,
          views:data.views,
          time:formatLocalDate(data.time),
        });
      })
      .catch((error) => console.log(error));
  }, []);

  // 글 정보를 navigate정보로 넘겨준다
  const navigate = useNavigate();
  function onClickEdit(){
    navigate(`/edit/${postIndex}`,{state:{post}})
  }

  return (
    <R.Wrapper>
      {post && (
        <>
          <R.InnerWrapper>
            <R.Header>
              <R.TitleWrapper>
              <R.Title>{post.title}</R.Title>
              <div onClick={onClickEdit} title="수정하기" >
              <img src={edit} alt="수정"/>
              </div>
              </R.TitleWrapper>
              <R.BookName>{post.bookName}</R.BookName>
              <R.ArticleInfo>
                <div>작성자 : {post.writer} </div>
                <div>조회수 : {post.views} </div>
                <div>날짜 : {post.time}</div>
              </R.ArticleInfo>
            </R.Header>
            <R.RowTemp />
            <R.Article>
              <ReadmeParser content={post.content} />
            </R.Article>
          </R.InnerWrapper>
          <R.ClosingArea>
            <strong>이 글에 흥미가 생겼다면</strong>
            <R.ClosingImg
              src={`${config.server}/board/img/${post.id}?${Date.now()}`}
              alt="감상문 책"
            />
            <strong>을 직접 읽어보세요</strong>
          </R.ClosingArea>
          {/* <R.CommentArea>
            <R.CommentTitle>댓글</R.CommentTitle>
          </R.CommentArea> */}
          <Link to="/">
          <R.DirectArea>
            <img src={goBack} alt="목록으로" />
            목록으로
          </R.DirectArea>
          </Link>
        </>
      )}
    </R.Wrapper>
  );
};

export default Read;
