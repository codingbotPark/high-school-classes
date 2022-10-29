package com.example.server.controller;

import com.example.server.dto.CreatePost;
import com.example.server.dto.LoadPost;
import com.example.server.dto.UpdatePost;
import com.example.server.entity.Post;
import com.example.server.repository.PostRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("board")
public class PostController {

    @Autowired
    PostRepository postRepository;

    @GetMapping("/findall")
    public List<LoadPost> findall(){
        List<LoadPost> postList = postRepository.findAll().stream().map((i) -> {
            return new LoadPost(
                    i.getId(),
                    i.getTitle(),
                    i.getBookName(),
                    i.getContent(),
                    i.getWriter(),
                    i.getTime(),
                    i.getViews()
            );
        }).collect(Collectors.toList());
        System.out.println(postList);

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

    @PostMapping("update/{id}")
    public void update(
            @PathVariable("id") Long id,
            @RequestBody UpdatePost updatePost
            ){
        Post findedPost = postRepository.findById(id).orElseThrow(() -> {throw new RuntimeException("수정하려는 글을 못 찾았습니다");});
        findedPost.updatePost(
                updatePost.getTitle(),
                updatePost.getBookName(),
                updatePost.getContent(),
                updatePost.getImg()
        );
        postRepository.save(findedPost);
    }
    
    @DeleteMapping("delete/{id}")
    public void delete(
            @PathVariable("id") Long id
    ){
        Post post = postRepository.findById(id).orElseThrow(() -> {throw new RuntimeException("삭제하려는 글을 못 찾았습니다");});
        postRepository.delete(post);
    }


    @GetMapping("find/{id}")
    public LoadPost find(
            @PathVariable("id") Long id
    ){
        Post findedPost = postRepository.findById(id).orElseThrow(() -> {throw new RuntimeException("글을 못 찾았습니다");});
        return new LoadPost(
                findedPost.getId(),
                findedPost.getTitle(),
                findedPost.getBookName(),
                findedPost.getContent(),
                findedPost.getWriter(),
                findedPost.getTime(),
                findedPost.getViews()
        );
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
