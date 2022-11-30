package com.example.server.entity;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import javax.persistence.*;

// dbTable
@Entity
@Setter // 값 넣을때, db를 바꾸는 것이기 때문에 사실상 한 번에 바꾸는 것이 더 좋다
@Getter // 값 뺄때
@ToString // 객체를 하나의 문자열
@NoArgsConstructor
public class Member {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    @Column(name = "id",nullable = false)
    private Long name;

    private String email;
    private String password;

}
