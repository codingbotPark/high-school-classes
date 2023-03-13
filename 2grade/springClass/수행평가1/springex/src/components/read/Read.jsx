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

import deleteSvg from "../../assets/read/delete.svg"

const Read = () => {
  const [post, setPost] = useState();

  const [postList,setPostList] = useRecoilState(posts)


  const location = useLocation();
  const splitedURL = location.pathname.split("/");
  const postIndex = splitedURL[splitedURL.length - 1];
  const formatLocalDate = useFormatLocalDate()
  useEffect(() => {
    customAxios
      .get(`board/view/${postIndex}`)
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
    if (localStorage.getItem("access_token")){
      navigate(`/edit/${postIndex}`,{state:{post}})
    } else {
      alert("로그인이 필요한 서비스입니다")
    }

  }
  function onClickDelete(){
    if (localStorage.getItem("access_token")){
      const list = postList
      list.filter((i) => {
        return i.id !== postIndex
      })
      setPostList(list)
  
      customAxios.delete(`board/delete/${postIndex}`)
      .then((result) => {
  
        navigate("/");
      })
      .catch((error) => console.log(error))
    } else {
      alert("로그인이 필요한 서비스입니다")
    }


  }

  return (
    <R.Wrapper>
      {post && (
        <>
          <R.InnerWrapper>
            <R.Header>
              <R.TitleWrapper>
              <R.Title>{post.title}</R.Title>
              <div>
              <img src={edit} alt="수정" onClick={onClickEdit} title="수정하기"/>
              <img src={deleteSvg} alt="삭제" onClick={onClickDelete} title="삭제하기" />
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
