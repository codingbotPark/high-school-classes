package com.example.jwtst.config;

import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;


@EnableWebSecurity // 원래 security에 있던 것을 없애겠다
public class MySecuConfig extends WebSecurityConfigurerAdapter {
    @Override
    protected void configure(HttpSecurity http) throws Exception{
        http.formLogin();
        http.csrf().disable(); // 보안 정책
        http.logout();


        http.addFilterBefore(apiCheckerFilter(),UsernamePasswordAuthenticationFilter.class);
        // 필터를 달아준다
        http.addFilterBefore(apiLoginFilter() , UsernamePasswordAuthenticationFilter.class);

    }

    @Bean
    public ApiCheckerFilter apiCheckerFilter(){
        return new ApiCheckerFilter();
    }

    @Bean
    public ApiLoginFilter apiLoginFilter() throws Exception{ // api/login이 됐을 때만 filter하게 된다
        ApiLoginFilter apiLoginFilter = new ApiLoginFilter("/api/login");
        apiLoginFilter.setAuthenticationManager(authenticationManager());
        return apiLoginFilter;
    }
}
