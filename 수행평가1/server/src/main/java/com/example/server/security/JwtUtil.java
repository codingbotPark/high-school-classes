package com.example.server.security;

import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import io.jsonwebtoken.impl.DefaultClaims;
import io.jsonwebtoken.impl.DefaultJws;
import org.springframework.stereotype.Component;

import java.time.ZonedDateTime;
import java.util.Date;

@Component // 컴포넌트로 하는 이유?
public class JwtUtil {
    private String secretKey = "dgsw12345678";
    private long expire = 60 + 24 + 30; // 만료기간

    public String generateToken(String content) throws Exception{
        return Jwts.builder()
                .setIssuedAt(new Date()) // 만든시간
                .setExpiration(Date.from(ZonedDateTime.now().plusMinutes(expire).toInstant())) // 만료시간
                .claim("sub",content) // 토큰 제목을 content로 함
                .signWith(SignatureAlgorithm.ES256, secretKey.getBytes("UTF-8"))
                .compact();
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

}
