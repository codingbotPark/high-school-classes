package com.example.server.security.filter;

import com.example.server.security.JwtUtil;
import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

public class ApiCheckerFilter extends OncePerRequestFilter {

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {

        String auth = request.getHeader("Authorization");

        if (auth != null && auth.startsWith("bearer ")){
            JwtUtil jwtUtil = new JwtUtil();

            try {
                String body = jwtUtil.validateAndExtract(auth);
                System.out.println("body" +body);
            } catch (Exception e){
                throw new RuntimeException(e);
            }

        } else {
            response.setContentType("text/plain");
            response.getOutputStream().write("로그인 틀림".getBytes(StandardCharsets.UTF_8));
        }

    }
}
