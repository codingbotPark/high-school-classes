import React from 'react';
import ReadmeParser from '../../common/readmeParser/ReadmeParser';
import * as R from "./Read.style"

const Read = () => {
    const dum = "안녕하세요\n# 저는 박병관입니다\n## 이건 제목2 \n###이건 제목3 \n> 이건 인용"

    return (
        <R.Wrapper>
            <R.InnerWrapper>
                <R.Header>
                    <R.Title></R.Title>
                    <R.BookName></R.BookName>
                </R.Header>
                <R.Article>
                <ReadmeParser content={dum} />
                </R.Article>
            </R.InnerWrapper>
        </R.Wrapper>
    );
};

export default Read;