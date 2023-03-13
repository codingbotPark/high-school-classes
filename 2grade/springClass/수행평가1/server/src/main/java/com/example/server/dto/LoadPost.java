package com.example.server.dto;

import lombok.AllArgsConstructor;
import lombok.Getter;

import java.time.LocalDateTime;

@Getter
@AllArgsConstructor // 메게변수를 가지고 생성자를 만든다
public class LoadPost {
    private Long id;
    private String title;
    private String bookName;
    private String content;
    private String writer;
    private LocalDateTime time;
    private int views;
}
