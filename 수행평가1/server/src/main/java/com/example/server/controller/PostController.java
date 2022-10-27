package com.example.server.controller;

import com.example.server.dto.CreatePost;
import com.example.server.entity.Post;
import com.example.server.repository.PostRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.List;

@RestController
@RequestMapping("board")
public class PostController {

    @Autowired
    PostRepository postRepository;

    @GetMapping("findall")
    public List<Post> findall(){
        List<Post> postList = postRepository.findAll();
        return postList;
    }

    @PostMapping("create")
    public void create(
            @RequestBody CreatePost createPost
    ){
        // 저장하기 전 처리
        try {
            Post tempPost = new Post(
                    createPost.getTitle(),
                    createPost.getBookName(),
                    createPost.getContent(),
                    createPost.getWriter(),
                    createPost.getImgFile().getName(),
                    createPost.getImgFile().getBytes()
            );
            postRepository.save(tempPost);
        } catch (IOException e) { // bytes의 예외처리
            throw new RuntimeException(e);
        }
    }


    // 이미지 src로 들고올 수 있도록
    @GetMapping(value = "/img/{id}", produces = MediaType.APPLICATION_OCTET_STREAM_VALUE)
    public ResponseEntity<byte[]> getImg(
            @PathVariable("id") Long id // pathValue들고오기
    ){
        Post post = postRepository.findById(id) // id
                .orElseThrow(() -> {throw new RuntimeException("");});

        String contentDisposition = String.format("attachment; filename=\"%s\"", post.getImgName());

        return ResponseEntity.ok()
                .header(HttpHeaders.CONTENT_DISPOSITION, contentDisposition)
                .body(post.getImgByte());
    }
}
