import React, { useEffect } from "react";
import { useState } from "react";
import { useCallback } from "react";
import { useRef } from "react";
import * as W from "./Write.style";

const Write = () => {
  const [title, setTitle] = useState("");
  const [bookName, setBookName] = useState("");
  const [content, setContent] = useState("");

  const titleRef = useRef();
  const bookNameRef = useRef();
  const contentRef = useRef();
  const [titleHeight, setTitleHeight] = useState(65);
  const [bookNameHeight, setBookNameHeight] = useState(35);
  const [contentHeight, setContentHeight] = useState(28);
  const [convertedContent,setConvertedContent] = useState()

  // todo
  useEffect(() => {
    window.addEventListener('resize',settingInputHeight)
    return () => {window.removeEventListener('resize',settingInputHeight)}
  },[])

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
  function handleResizeHeight(ref,setter,defaultPx){
    if (ref === null || ref.current === null) return;
    ref.current.style.height = defaultPx+"px"
    ref.current.style.height = ref.current.scrollHeight + "px";
    setter(ref.current.style.height);
  }

//   const handleResizeHeight = useCallback(
//     (ref) => {
//       if (ref === null || ref.current === null) return;
//       ref.current.style.height = ref.current.scrollHeight + "px";
//     },
//     [titleRef.current.style.height, bookNameRef.current.style.height, contentRef.current.style.height]
//   );

  return (
    <W.Wrapper>
      <W.InnerWrapper>
        <W.InputArea>
          <W.InputTitle
            ref={titleRef}
            placeholder="제목을 입력하세요"
            onChange={(e) => {
              inputHandler(e, setTitle);
              handleResizeHeight(titleRef,setTitleHeight,65);
            }}
          />
          <W.InputBook
            ref={bookNameRef}
            placeholder="책 이름을 입력하세요"
            onChange={(e) => {
              inputHandler(e, setBookName);
              handleResizeHeight(bookNameRef,setBookNameHeight,35);
            }}
          />
          <W.LatTemp />
          <W.InputContent
            ref={contentRef}
            placeholder="내용을 입력하세요"
            onChange={(e) => {
              inputHandler(e,setContent);
              handleResizeHeight(contentRef,setContentHeight,28);
            }}
          />
        </W.InputArea>

        <W.LngTemp/>

        <W.ResultArea>
          <W.ResultTitle height={titleHeight} >{title}</W.ResultTitle>
          <W.ResultBook height={bookNameHeight} >{bookName}</W.ResultBook>
          <W.ResultContent height={contentHeight} >{

            
          }</W.ResultContent>
        </W.ResultArea>
      </W.InnerWrapper>
    </W.Wrapper>
  );
};

export default Write;
