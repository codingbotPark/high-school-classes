import React from 'react';
import * as F from "./Footer.style"

import githubLogo from "../../assets/footer/github.png"

const Footer = () => {
    return (
        <F.Wrapper>
            <F.Info>
                <div>made by
                    <a href='https://www.instagram.com/0b0ut/' target="blank" title='개발자 인스타그램'> 병관
                    </a>
                </div>
                <div>
                    <a href='https://github.com/codingbotPark/spring-highSchoolClass/tree/master/%EC%88%98%ED%96%89%ED%8F%89%EA%B0%801/springex' target="blank" title="깃허브">
                    <F.FooterImg src={githubLogo} />
                    </a>
                </div>
            </F.Info>
        </F.Wrapper>
    );
};

export default Footer;