import React, { useEffect } from "react";
import { useState } from "react";
import { useCallback } from "react";
import { useRef } from "react";
import { useLocation, useNavigate } from "react-router-dom";
import PostView from "../../common/postView/PostView";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import customAxios from "../../util/customAxios";
import * as W from "./Write.style";

import config from "../../config/config.json";



const Write = ({ mode = "write" }) => {
  const [title, setTitle] = useState("");
  const [bookName, setBookName] = useState("");
  const [content, setContent] = useState("");

  const [author, setAuthor] = useState("익명");
  const [views, setViews] = useState(0);

  const [image, setImage] = useState();

  const titleRef = useRef();
  const bookNameRef = useRef();
  const contentRef = useRef();

  const location = useLocation();
  useEffect(() => {
    if (mode === "edit") {
      if (location.state.post) {
        // 값이 location에 잘 저장되어 왔을 때
        const post = location.state.post;

        setTitle(post.title);
        setBookName(post.bookName);
        setContent(post.content);
        setAuthor(post.writer);
        setViews(post.views);
        setImage(`${config.server}/board/img/${post.id}`);
      } else {
        // location에 저장되어 오지 않았을 때 서버 통신
      }
    }

    window.addEventListener("resize", settingInputHeight);
    return () => {
      window.removeEventListener("resize", settingInputHeight);
    };
  }, []);

  useEffect(() => {
    // 높이 세팅
    settingInputHeight();
  }, [title , bookName , content]);
  
  // --------

  function settingInputHeight() {
    handleResizeHeight(titleRef);
    handleResizeHeight(bookNameRef);
    handleResizeHeight(contentRef);
  }

  // --------

  function inputHandler(e, setter) {
    setter(e.target.value);
  }

  /** 바꿀 textarea의 ref와 setter */
  function handleResizeHeight(ref, defaultPx) {
    if (ref === null || ref.current === null) return;
    ref.current.style.height = defaultPx + "px";
    ref.current.style.height = ref.current.scrollHeight + "px";
  }

  function handleChangeFile(e) {
    setImage(...e.target.files);
  }

  function formatFile(file) {
    const temp = URL.createObjectURL(file)
    return temp
    // console.log(temp.substring(5,temp.length-1))
    // return temp.substring(5,temp.length-1)
  }

  /**글 미리보기 날짜 형태를 포멧 */
  function formatNow() {
    const date = new Date();
    return `${date.getFullYear()}년${date.getMonth()}월${date.getDate()}일 ${date.getHours()}시${date.getMinutes()}분`;
  }

  const navigate = useNavigate();

  function createPost() {
    if (typeof image === "object") {

      const form = new FormData();
      form.append("file", image);
      customAxios
        .post(`/${mode==="edit"?
         `board/update/image/${location.state.post.id}` 
        : "board/image"}`, form)
        .then((result) => {
          customAxios
            .post(`/${mode === "edit" ? `board/update/${location.state.post.id}` : "board/writer"}`, {
              title,
              bookName,
              content,
              writer: author,
              imageId: result.data,
            })
            .then((response) => navigate("/"))
            .catch((error) => console.log(error));
        })
        .catch((error) => console.log(error));

    } else {

      customAxios.post(`board/update/${location.state.post.id}`,{
        title,
        bookName,
        content,
        writer: author,
        imageId: location.state.post.id,
      }).then((response) => navigate("/"))
      .catch((error) => console.log(error));

    }

  }

  // function updatePost

  return (
    <W.Wrapper>
      <W.WrapperLayout>
        <W.InnerWrapper>
          <W.InputArea>
            <W.InputTitle
              ref={titleRef}
              value={title}
              placeholder="제목을 입력하세요"
              onChange={(e) => {
                inputHandler(e, setTitle);
                handleResizeHeight(titleRef, 70);
              }}
            />
            <W.InputBook
              ref={bookNameRef}
              value={bookName}
              placeholder="책 이름을 입력하세요"
              onChange={(e) => {
                inputHandler(e, setBookName);
                handleResizeHeight(bookNameRef, 38);
              }}
            />
            <W.LatTemp />
            <W.InputContent
              ref={contentRef}
              value={content}
              placeholder="내용을 입력하세요"
              onChange={(e) => {
                inputHandler(e, setContent);
                handleResizeHeight(contentRef, 30);
              }}
            />
          </W.InputArea>

          <W.LngTemp />

          <W.ResultArea>
            <W.ResultTitle>{title}</W.ResultTitle>
            <W.ResultBook>{bookName}</W.ResultBook>
            <W.LatTemp />

            <W.ResultContent>
              <ReadmeParser content={content} />
            </W.ResultContent>
          </W.ResultArea>
        </W.InnerWrapper>

        <W.SubmitArea>
          <W.SubmitAreaWrapper>
            <W.SubmitImgWrapper>
              {/* <imgsrc={URL.createObjectURL(image)}/> */}

              <PostView
                img={
                  image &&
                  (typeof image === "string" ? image : formatFile(image))
                }
                title={title}
                author={author}
                time={formatNow()}
                views={views}
              />
              <W.SubmitImgButton>
                <label htmlFor="fileBox">
                  {image ? "책사진 변경" : "책사진 업로드"}
                </label>
                <input
                  type="file"
                  id="fileBox"
                  onChange={(e) => handleChangeFile(e)}
                />
              </W.SubmitImgButton>
            </W.SubmitImgWrapper>
            <W.SubmitButtonWrapper>
              <W.AuthorInput>
                <div>글쓴이</div>
                <input
                  onChange={(e) => inputHandler(e, setAuthor)}
                  type="text"
                  value={author || ""}
                  placeholder="글쓴이 닉네임"
                />
              </W.AuthorInput>
              <button onClick={createPost}>
                {mode === "edit" ? "글 수정하기" : "글 생성하기"}
              </button>
            </W.SubmitButtonWrapper>
          </W.SubmitAreaWrapper>
        </W.SubmitArea>
      </W.WrapperLayout>
    </W.Wrapper>
  );
};

export default Write;
