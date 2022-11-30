package com.example.server.security;

import com.example.server.entity.Member;
import com.example.server.repository.MemberRepository;
import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import io.jsonwebtoken.impl.DefaultClaims;
import io.jsonwebtoken.impl.DefaultJws;
import lombok.RequiredArgsConstructor;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.userdetails.User;
import org.springframework.stereotype.Component;

import java.io.UnsupportedEncodingException;
import java.time.ZonedDateTime;
import java.util.Date;

@Component // 컴포넌트로 하는 이유?
@RequiredArgsConstructor
public class JwtUtil {
    private String secretKey = "dgsw12345678";
    private long expire = 60 + 24 + 30; // 만료기간
    private final MemberRepository memberRepository;

    public String generateToken(String content){
        try {
            return Jwts.builder()
                    .setIssuedAt(new Date()) // 만든시간
                    .setSubject(content)
                    .setExpiration(Date.from(ZonedDateTime.now().plusMinutes(expire).toInstant())) // 만료시간
                    .claim("sub",content) // 토큰 제목을 content로 함
                    .signWith(SignatureAlgorithm.HS256, secretKey.getBytes("UTF-8"))
                    .compact();
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }
    }

    // 토큰 유효성 체크
    public String validateAndExtract(String tokenStr) throws Exception{
        String contentValue = null;
        try{
            // key로 파싱
            DefaultJws defaultJws = (DefaultJws) Jwts.parser()
                    .setSigningKey(secretKey.getBytes("UTF-8")).parseClaimsJws(tokenStr);
            // body를 가져온다
            DefaultClaims claims = (DefaultClaims) defaultJws.getBody();
            // 주제 가져오기
            contentValue = claims.getSubject();
        } catch (Exception e){
        }
        return contentValue;
    }

    public Authentication getAuthentication(String token) {
        Member member = memberRepository.findByEmail(getTokenSubject(token).getSubject())
                .orElseThrow();
        return new UsernamePasswordAuthenticationToken(member, null, null);
    }

    public Claims getTokenSubject(String token) {
        try {
            return Jwts.parser().setSigningKey(secretKey.getBytes("UTF-8"))
                    .parseClaimsJws(token).getBody();
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }
    }

}
