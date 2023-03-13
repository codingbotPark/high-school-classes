package com.example.jwtst.config;

import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

// 요청되는 모든 주소에 한해 토큰을 검사
public class ApiCheckerFilter extends OncePerRequestFilter {
    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {
        System.out.println("apicheckerfileter");


        String auth = request.getHeader("Authorization");

        System.out.println(auth);

        // login으로 들어왔을 때는 원래대로 filter
        if (request.getRequestURI().equals("/api/login")) {
            filterChain.doFilter(request,response);
        } else if (auth != null && auth.startsWith("bearer ")) {
            // jwt가 유효한지 확인
            JwtUtil jwtutil = new JwtUtil();
            try {
                String email = jwtutil.validateAndExtract(auth.substring(7));
                System.out.println("email = " + email);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }

            filterChain.doFilter(request, response);
        } else {
            response.setContentType("text/plain");
            response.getOutputStream().write("로그인정보틀림".getBytes(StandardCharsets.UTF_8));
        }

        filterChain.doFilter(request,response);
    }
}
