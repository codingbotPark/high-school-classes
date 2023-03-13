package com.dgsw.ex01_springboot.controller;

import com.dgsw.ex01_springboot.conponents.A;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@Controller // url 주소 매핑
public class AController {

    @Autowired
    A a1;

    @Autowired
    DataSource ds;

    @GetMapping("aa") // 주소 설
    public String aa(){
        return "aa";
    }

    @GetMapping("tablecreate")
    @ResponseBody
    public String tablecreate() {
        Connection conn = null;
        try {
            conn = ds.getConnection();
            PreparedStatement pstmt = conn.prepareStatement("create table test (aa varchar(20),bb varchar(20))");
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {

                conn.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        return "tablecreate";
    }
}


// Configuration
// 객체 컨테이터
// Bean
// 객체 설정
// SpringBootApplication
// springboot라이브러리 로딩, 환경 설정
// Controller
// url 주소 맵핑
// GetMapping
// 주소 설정