package com.example.server.repository;

import com.example.server.entity.Member;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface MemberRepository extends JpaRepository<Member,Long> {
    // 회원 가입시 중복된 회원 검사
    Member findByEmail(String email);
}
