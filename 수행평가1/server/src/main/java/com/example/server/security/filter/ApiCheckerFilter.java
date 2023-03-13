package com.example.server.security.filter;

import com.example.server.security.JwtUtil;
import lombok.RequiredArgsConstructor;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.filter.OncePerRequestFilter;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

@RequiredArgsConstructor
public class ApiCheckerFilter extends OncePerRequestFilter {

    private final JwtUtil jwtUtil;

    @Override
    protected void doFilterInternal(HttpServletRequest request, HttpServletResponse response, FilterChain filterChain) throws ServletException, IOException {
        String auth = request.getHeader("Authorization");
        String path = request.getRequestURI();

            if (path.startsWith("/board/img/")) {
                filterChain.doFilter(request, response);
            } else if (path.startsWith("/user/login") || path.startsWith("/user/register")) {
                filterChain.doFilter(request, response);
            } else if (path.startsWith("/board/list") || path.startsWith("/board/view")) {
                filterChain.doFilter(request, response);
            } else {

                if (auth != null && auth.startsWith("Bearer ")) {
                    try {
                        String body = jwtUtil.validateAndExtract(auth);
                        System.out.println("body" + body);

                        SecurityContextHolder.getContext().setAuthentication(jwtUtil.getAuthentication(auth.split("Bearer ")[1]));
                        filterChain.doFilter(request, response);
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                }
            }

    }
}
