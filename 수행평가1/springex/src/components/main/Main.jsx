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
    customAxios.get("/findall")
    .then((result) => {
        console.log(result)
        setPostList(result)
    })
    .catch((error) => {console.log(error)})
  },[])

//   const posts = [
//     {
//       id: 1,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     {
//       id: 2,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     {
//       id: 3,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     {
//       id: 4,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     ,
//     {
//       id: 5,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     {
//       id: 6,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//     ,
//     {
//       id: 7,
//       img: dumBook,
//       title: "인간 관계론 독서감상문",
//       author: "박병관",
//       time: "2022년 10월 26일 14:23",
//       views: 100,
//     },
//   ];


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
