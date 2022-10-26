import React from "react";
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
  const [titleLine, setTitleLine] = useState(1);
  const [bookNameLine, setBookNameLine] = useState(1);
  const [contentLine, setContentLine] = useState(1);

  function inputHandler(e, setter) {
    setter(e.target.value);
  }

  function textAreaResize(ref, px) {
    if (ref === null || ref.current === null) return;
  }

  const handleResizeHeight = useCallback(
    (ref, px) => {
      if (ref === null || ref.current === null) return;
      ref.current.height = "";
    },
    [titleLine, bookNameLine, contentLine]
  );

  return (
    <W.Wrapper>
      <W.InnerWrapper>
        <W.InputArea>
          <W.InputTitle placeholder="제목을 입력하세요" />
          <W.InputBook placeholder="책 이름을 입력하세요" />
          <W.InputTemp />
          <W.InputContent placeholder="내용을 입력하세요" />
        </W.InputArea>
        <W.ResultArea>
            <W.ResultTitle>{title}</W.ResultTitle>
            <W.ResultBook>{bookNameLine}</W.ResultBook>
          <W.ResultContent>
            {
                "<h1>ㅎㅇ</h1>"
            }
          </W.ResultContent>
        </W.ResultArea>
      </W.InnerWrapper>
    </W.Wrapper>
  );
};

export default Write;
