import React, { useEffect } from "react";
import { useState } from "react";
import { useCallback } from "react";
import { useRef } from "react";
import PostView from "../../common/postView/PostView";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import customAxios from "../../util/customAxios";
import * as W from "./Write.style";

const Write = () => {
  const [title, setTitle] = useState("");
  const [bookName, setBookName] = useState("");
  const [content, setContent] = useState("");

  const [author,setAuthor] = useState();

  const [image, setImage] = useState();

  const titleRef = useRef();
  const bookNameRef = useRef();
  const contentRef = useRef();

  useEffect(() => {
    window.addEventListener("resize", settingInputHeight);
    return () => {
      window.removeEventListener("resize", settingInputHeight);
    };
  }, []);

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

  useEffect(() => {
    console.log(image);
  },[image])

  function formatFile(file){
    return URL.createObjectURL(file)
  }
  /**글 미리보기 날짜 형태를 포멧 */
  function formatNow(){
    const date = new Date()
    return `${date.getFullYear()}년${date.getMonth()}월${date.getDate()}일 ${date.getHours()}시${date.getMinutes()}분`
  }

  function createPost(){
  
    const form = new FormData()
    form.append("file",image)
    customAxios.post("/board/image",form)
    .then((result) => {
      customAxios.post("/board/create",{
        title,
        bookName,
        content,
        writer:author,
        imageId:result.data,
      }).then((response) => console.log(response))
      .catch((error) => console.log(error))
    })
    .catch((error) => console.log(error));


    // customAxios.post("/board/create",form, image, {
    //   headers: {
    //     "Content-Type": "multipart/formDate"
    //   }
    // })
    // .then((result) => console.log(result))
    // .catch((error) => console.log(error))
  }

  return (
    <W.Wrapper>
      <W.WrapperLayout>
        <W.InnerWrapper>
          <W.InputArea>
            <W.InputTitle
              ref={titleRef}
              placeholder="제목을 입력하세요"
              onChange={(e) => {
                inputHandler(e, setTitle);
                handleResizeHeight(titleRef, 70);
              }}
            />
            <W.InputBook
              ref={bookNameRef}
              placeholder="책 이름을 입력하세요"
              onChange={(e) => {
                inputHandler(e, setBookName);
                handleResizeHeight(bookNameRef, 38);
              }}
            />
            <W.LatTemp />
            <W.InputContent
              ref={contentRef}
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
                // img={formatFile(image)}
                img={image && formatFile(image)}
                title={title}
                author={"박병관"}
                time={formatNow()}
                views={100}
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
              <input onChange={(e) => inputHandler(e,setAuthor)} type="text" placeholder="글쓴이 닉네임" />
              </W.AuthorInput>
              <button
                onClick={createPost}
              >글 생성하기</button>
            </W.SubmitButtonWrapper>
          </W.SubmitAreaWrapper>
        </W.SubmitArea>
      </W.WrapperLayout>
    </W.Wrapper>
  );
};

export default Write;
