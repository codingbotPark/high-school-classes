package com.example.demo.controller;

import com.example.demo.components.ACompo;
import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

@Controller
public class MainController {

    @Autowired
    ACompo aCompo;

    @Autowired
    SqlSessionTemplate sqlSessionTemplate;
    
    @GetMapping
    public String index(){
        // 객체 호출 한 번 하고, reutrn aa 를 한다
        return "aa";
    }

    @GetMapping("feature")
    public String feature(){
        return "feature";
    }

    @GetMapping("freeboard")
    public String freeboard(Model model){
        List list = sqlSessionTemplate.selectList("test.findall");
        System.out.println(list);
        // model안에 값을 넣어서 저장
        model.addAttribute("list",list);
        model.addAttribute("aaa","a값");
        return "freeboard";
    }

    @GetMapping("insert")
    public String insert(){
        sqlSessionTemplate.insert("test.insert");
        return "insert";
    }

}
