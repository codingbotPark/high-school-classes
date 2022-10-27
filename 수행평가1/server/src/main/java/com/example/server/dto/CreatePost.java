package com.example.server.dto;

import lombok.Getter;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

@Getter @NoArgsConstructor
public class CreatePost {

    private String title;
    private String bookName;
    private String content;
    private String writer;
    private MultipartFile imgFile;
}
