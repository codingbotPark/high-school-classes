package com.example.jwtst.config;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.config.annotation.web.configurers.AbstractAuthenticationFilterConfigurer;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.web.authentication.AbstractAuthenticationProcessingFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@Slf4j
public class ApiLoginFilter extends AbstractAuthenticationProcessingFilter {



    // api/login이라는 주소로 들어올 떄
    protected ApiLoginFilter(String defaultFilterProcessesUrl) {
        super(defaultFilterProcessesUrl);
    }

    @Override // 성공했을 때 토큰을 던저준다
    protected void successfulAuthentication(HttpServletRequest request, HttpServletResponse response, FilterChain chain, Authentication authResult) throws IOException, ServletException {
        response.setContentType("text/plain");
//        response.getOutputStream().write("성공적으로 로그인".getBytes(StandardCharsets.UTF_8));

//        log.info(authResult.getPrincipal().toString());
        String email = ((User)authResult.getPrincipal()).getUsername();

        JwtUtil jwtUtil = new JwtUtil();

        try {
            response.getOutputStream().write(jwtUtil.generateToken(email).getBytes());
        } catch (Exception e){
            throw new RuntimeException(e);
        }

    }

    // login 할지 시도하는 메서드
    @Override
    public Authentication attemptAuthentication(HttpServletRequest request, HttpServletResponse response) throws AuthenticationException, IOException, ServletException {
        System.out.println("테스트");

        String email = request.getParameter("email");
        String password = request.getParameter("password");

        System.out.println(email);
        System.out.println(password);

        UsernamePasswordAuthenticationToken authToken = new UsernamePasswordAuthenticationToken(email,password);


        return getAuthenticationManager().authenticate(authToken);
    }
}
