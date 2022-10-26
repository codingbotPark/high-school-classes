package com.example.server.controller;

import com.example.server.entity.Post;
import com.example.server.repository.PostRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

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
    public void create(Post post){
        postRepository.save(post);
    }


}
