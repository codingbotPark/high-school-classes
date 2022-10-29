import React from "react";
import ReadmeParser from "../../common/readmeParser/ReadmeParser";
import * as R from "./Read.style";

import { useRecoilState } from "recoil";
import { posts } from "../../global/posts";
import { useEffect } from "react";
import { useState } from "react";

const Read = () => {
  const [post, setPost] = useState({
    title:"인간관계론 독서감상문",
    bookName:"인간관계론",
    content: "안녕하세요\n# 저는 박병관입니다\n## 이건 제목2 \n###이건 제목3 \n> 이건 인용",
  });

  useEffect(() => {
    
  }, []);

  return (
    <R.Wrapper>
      {post && (
        <R.InnerWrapper>
          <R.Header>
            <R.Title>{post.title}</R.Title>
            <R.BookName>{post.bookName}</R.BookName>
          </R.Header>
          <R.RowTemp />
          <R.Article>
            <ReadmeParser content={post.content} />
          </R.Article>
          <R.CommentArea>
            <R.CommentTitle>댓글</R.CommentTitle>
          </R.CommentArea>
        </R.InnerWrapper>
      )}
    </R.Wrapper>
  );
};

export default Read;
