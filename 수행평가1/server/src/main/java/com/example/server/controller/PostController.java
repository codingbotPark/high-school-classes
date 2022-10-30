package com.example.server.controller;

import com.example.server.dto.CreatePost;
import com.example.server.dto.LoadPost;
import com.example.server.dto.UpdatePost;
import com.example.server.entity.Image;
import com.example.server.entity.Post;
import com.example.server.repository.ImageRepository;
import com.example.server.repository.PostRepository;
import lombok.RequiredArgsConstructor;
import lombok.extern.log4j.Log4j2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

@Log4j2
@RestController
@RequestMapping("board")
@RequiredArgsConstructor
public class PostController {

    private final PostRepository postRepository;
    private final ImageRepository imageRepository;

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

    @PostMapping(value = "create")
    public void create(
            @RequestBody CreatePost createPost
    ){
        Image image = imageRepository.findById(createPost.getImageId())
                .orElseThrow(() -> {throw new RuntimeException("이미지가 없습니다");});
        // 저장하기 전 처리
        Post tempPost = new Post(
                createPost.getTitle(),
                createPost.getBookName(),
                createPost.getContent(),
                createPost.getWriter(),
                image.getImgName(),
                image.getImgByte()
        );
        postRepository.save(tempPost);
    }

    // 업데이트할 때의 게시글
    @PostMapping("update/{id}")
    public void update(
            @PathVariable("id") Long id,
            @RequestBody UpdatePost updatePost
    ){
        Image image = imageRepository.findById(id).orElseThrow(() -> {throw new RuntimeException("이미지가 없습니다");});
        
        Post findedPost = postRepository.findById(id).orElseThrow(() -> {throw new RuntimeException("수정하려는 글을 못 찾았습니다");});
        findedPost.updatePost(
                updatePost.getTitle(),
                updatePost.getBookName(),
                updatePost.getContent(),
                updatePost.getWriter(),
                image.getImgName(),
                image.getImgByte()
        );
        postRepository.save(findedPost);
    }

    
    // 업데이트 할 때의 img
    @PostMapping("update/image/{id}")
    public Long image(
            @PathVariable("id") Long id,
            MultipartFile file
    ) {
        Image upImg = imageRepository.findById(id).orElseThrow(() -> {throw  new RuntimeException("이미지를 못 찾았습니다");});
        try {
            upImg.updateImage(
                    file.getName(),
                    file.getBytes()
            );

            return imageRepository.save(upImg).getImageId();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @PostMapping("image")
    public Long image(
            MultipartFile file
    ) {
        try {
            Image image = new Image(file.getName(), file.getBytes());

            return imageRepository.save(image).getImageId();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
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
        findedPost.viewCount();
        postRepository.save(findedPost);
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
