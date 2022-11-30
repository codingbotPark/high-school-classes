package com.example.server.controller;

import com.example.server.dto.CreateMember;
import com.example.server.dto.LoginRequest;
import com.example.server.entity.Member;
import com.example.server.repository.MemberRepository;
import com.example.server.security.JwtUtil;
import lombok.RequiredArgsConstructor;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
@RequiredArgsConstructor
public class MemberController {

    private final MemberRepository memberRepository;
    private final JwtUtil jwtUtil;
    private final PasswordEncoder passwordEncoder;

    @PostMapping("register")
    public String psignup(@RequestBody CreateMember member) {
        memberRepository.findByEmail(member.getEmail())
                .ifPresent(m -> {
                    throw new RuntimeException("존재하는 회원입니다.");
                });

        Member member1 = new Member(member.getName(), member.getEmail(), passwordEncoder.encode(member.getPassword()));

        memberRepository.save(member1);
        return "성공";
    }

    @PostMapping("login")
    public String signin(@RequestBody LoginRequest request){
        Member member = memberRepository.findByEmail(request.getEmail())
                .orElseThrow();

        if(passwordEncoder.matches(request.getPassword(), member.getPassword())){
            return jwtUtil.generateToken(member.getEmail());
        } else {
            throw new RuntimeException("비밀번호가 맞지 않습니다.");
        }
    }

//    @PostMapping("getName")
//    public
}
