package com.example.server.entity;

import lombok.Getter;
import lombok.NoArgsConstructor;
import org.hibernate.annotations.CreationTimestamp;
import org.hibernate.annotations.UpdateTimestamp;
import org.springframework.web.multipart.MultipartFile;

import javax.persistence.*;
import java.io.IOException;
import java.time.LocalDateTime;

@Entity
@Getter @NoArgsConstructor
public class Post {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id", nullable = false)
    private Long id;
    private String title;
    private String bookName;
    private String content;
    private String writer;

    private String imgName;

    // sql에 그냥 넣으면 안 들어가기 때문에
    @Lob
    @Column(columnDefinition = "MEDIUMBLOB")
    private byte[] imgByte;

    // 업데이트 됐을 때 시간 변경
    @UpdateTimestamp
    private LocalDateTime time;
    private int views;

    public Post(String title,String bookName, String content, String writer, String imgName, byte[] imgByte) {
        this.title = title;
        this.bookName = bookName;
        this.content = content;
        this.writer = writer;
        this.imgName = imgName;
        this.imgByte = imgByte;
    }

    public void viewCount(){
        this.views++;
    }

    public void updatePost(String title, String bookName, String content, String writer,String imgName, byte[] imgByte){
            this.title = title;
            this.bookName = bookName;
            this.content = content;
            this.writer = writer;
            this.imgName = imgName;
            this.imgByte = imgByte;

    }
}
