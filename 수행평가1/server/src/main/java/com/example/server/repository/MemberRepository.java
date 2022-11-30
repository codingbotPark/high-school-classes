package com.example.server.repository;

import com.example.server.entity.Member;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface MemberRepository extends JpaRepository<Member,Long> {
    // 회원 가입시 중복된 회원 검사
    Optional<Member> findByEmail(String email);
}
