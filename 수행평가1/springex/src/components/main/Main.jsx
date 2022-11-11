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

import config from "../../config/config.json"
import useFormatLocalDate from "../../hooks/useFormatLocalDate";

import Modal from "../../common/modal/Modal";

const Main = () => {
  const [postList,setPostList] = useRecoilState(posts)


  useEffect(() => {
    customAxios.get("/list")
    // customAxios.get("/board/list")
    .then((result) => {
        console.log("서버통신")
        console.log(result.data)
        setPostList(result.data)

    })
    .catch((error) => {console.log(error)})
  },[])

  const formatLocalDate = useFormatLocalDate();


  const [modalIsOpen,setModalIsOpen] = useState(true);
  function onClose(){
    setModalIsOpen(false)
  }

  return (
    <M.Wrapper>
      <M.PostListWrapper>
        {postList.map((i) => (
          <Link to={`/read/${i.id}`}  key={i.id}>
            <PostView
              img={`${config.server}/img/${i.id}?${Date.now()}`}
              title={i.title}
              author={i.writer}
              time={formatLocalDate(i.time)}
              views={i.views}
            />
          </Link>
        ))}
      </M.PostListWrapper>

      
      { modalIsOpen &&
      <Modal
        onClose={setModalIsOpen}
        maskCloseable={true}
      >
        <div>ㅎㅇ</div>
      </Modal>
      }

    </M.Wrapper>
  );
};

export default Main;
