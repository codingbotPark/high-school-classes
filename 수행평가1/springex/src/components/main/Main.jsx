import React from "react";
import * as M from "./Main.style";

import dumBook from "../../assets/main/dumBook.jpg";
import { Link } from "react-router-dom";
import { useState } from "react";
import { useEffect } from "react";

import customAxios from "../../util/customAxios";
import { posts } from "../../global/posts";
import { useRecoilState } from "recoil";
import PostView from "../../common/postView/PostView";

const Main = () => {
  const [postList,setPostList] = useRecoilState(posts)

  // useEffect(() => {
  //   customAxios.get("http://localhost:8080/board/findall")
  //   .then((result) => {
  //       setPostList(result.data)
  //   })
  //   .catch((error) => {console.log(error)})
  // },[])



  return (
    <M.Wrapper>
      <M.PostListWrapper>
        {postList.map((i) => (
          <Link to={`/read/${i.id}`}  key={i.id}>
            <PostView
              title={i.title}
              author={i.author}
              time={i.time}
              views={i.views}
            />
          </Link>
        ))}
      </M.PostListWrapper>
    </M.Wrapper>
  );
};

export default Main;
