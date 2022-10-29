import React from "react";
import * as M from "./Main.style";

import dumBook from "../../assets/main/dumBook.jpg";
import { Link } from "react-router-dom";
import { useState } from "react";
import { useEffect } from "react";

import customAxios from "../../util/customAxios";
import { posts } from "../../global/posts";
import { useRecoilState } from "recoil";

const Main = () => {
  const [postList,setPostList] = useRecoilState(posts)

  useEffect(() => {
    customAxios.get("http://localhost:8080/board/findall")
    .then((result) => {
        setPostList(result.data)
    })
    .catch((error) => {console.log(error)})
  },[])

  return (
    <M.Wrapper>
      <M.PostListWrapper>
        {postList.map((i) => (
          <Link to={`/read/${i.id}`}  key={i.id}>
            <M.PostWrapper>
              <M.PostImgWrapper>
                <M.PostImg src={i.img} />
              </M.PostImgWrapper>
              <M.PostInfoWrapper>
                <M.PostInfoHeader>
                  <M.PostInfoTitle>{i.title}</M.PostInfoTitle>
                  <M.PostInfoAuthor>{i.author}</M.PostInfoAuthor>
                </M.PostInfoHeader>
                <M.PostInfoTemp />
                <M.PostInfoContent>
                  <M.PostInfoTime>{i.time}</M.PostInfoTime>
                  <M.PostInfoViews>{i.views}</M.PostInfoViews>
                </M.PostInfoContent>
              </M.PostInfoWrapper>
            </M.PostWrapper>
          </Link>
        ))}
      </M.PostListWrapper>
    </M.Wrapper>
  );
};

export default Main;
