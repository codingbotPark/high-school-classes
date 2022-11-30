package com.example.server.controller;

import com.example.server.entity.Member;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
public class MemberController {
    @PostMapping("signup")
    public String psignup(Member member) {
        System.out.println("ㅎㅇ");
        return null;
    }

    @PostMapping("signin")
    public String signin(){
        return null;
    }
}
