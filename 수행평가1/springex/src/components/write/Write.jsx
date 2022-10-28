import React, { useEffect } from "react";
import { useState } from "react";
import { useCallback } from "react";
import { useRef } from "react";
import * as W from "./Write.style";

const Write = () => {
  const [title, setTitle] = useState("");
  const [bookName, setBookName] = useState("");
  const [content, setContent] = useState("");

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
    console.log(e.target.value.split("\n"));
    // console.log(e.target.value.split("\n").split(""))

    setter(e.target.value);
  }

  /** 바꿀 textarea의 ref와 setter */
  function handleResizeHeight(ref, defaultPx) {
    if (ref === null || ref.current === null) return;
    ref.current.style.height = defaultPx + "px";
    ref.current.style.height = ref.current.scrollHeight + "px";
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
            <W.ResultContent>
              {
                content.split("\n").map((i, idx) => {
                  //enter로 한 번 나눈다
                  console.log(i);
                  const splitedLine = i.split(" ");

                  switch (
                    splitedLine[0] // 라인을 스페이스바로 나눴을 때 첫 명령
                  ) {
                    case "#":
                      // 명령어 라인 삭제
                      // console.log(splitedLine)
                      splitedLine.shift();
                      return <h1 key={idx}>{splitedLine}</h1>;
                    case "##":

                    default: // 첫 줄에 명령어가 없을 때(bold, a 파악)
                      return <p key={idx}></p>;
                  }

                })
              }
            </W.ResultContent>
          </W.ResultArea>
        </W.InnerWrapper>

        <W.SubmitArea>
          <W.SubmitAreaWrapper>
            <W.SubmitImgWrapper></W.SubmitImgWrapper>
            <W.SubmitButtonWrapper></W.SubmitButtonWrapper>
          </W.SubmitAreaWrapper>
        </W.SubmitArea>
      </W.WrapperLayout>
    </W.Wrapper>
  );
};

export default Write;
