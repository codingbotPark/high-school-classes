package com.example.server.controller;

import com.example.server.entity.Member;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MemberController {
    @PostMapping("signup")
    public String psignup(Member member){
        System.out.println("ㅎㅇ");

        member.setPassword()
    }
}
