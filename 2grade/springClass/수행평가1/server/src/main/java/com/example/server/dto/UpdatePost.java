package com.example.server.dto;

import lombok.AllArgsConstructor;
import lombok.Getter;
import org.springframework.web.multipart.MultipartFile;

@Getter
@AllArgsConstructor
public class UpdatePost {
    private String title;
    private String bookName;
    private String content;
    private String writer;
}
