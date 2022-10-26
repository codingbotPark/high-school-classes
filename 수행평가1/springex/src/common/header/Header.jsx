import React from 'react';
import { Link } from 'react-router-dom';
import * as H from "./Header.style"

import profile from "../../assets/header/profile.svg"

const Header = () => {
    return (
        <H.Wrapper>
            <Link to="/"><H.Logo>logo</H.Logo></Link>
            <H.ProfileMenu>
            <Link to="/write"><H.Write>글쓰기</H.Write></Link>
            <Link to="/my"><H.Profile src={profile}></H.Profile></Link>
            </H.ProfileMenu>
        </H.Wrapper>
    );
};

export default Header;