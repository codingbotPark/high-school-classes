package com.example.jwtst;

import com.example.jwtst.config.JwtUtil;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class JwtstApplicationTests {

    @Autowired
    JwtUtil jwtUtil;

    @Test
    void contextLoads() throws Exception {
        // 그냥 테스트만 한다

        String jtoken = jwtUtil.generateToken("email");
        System.out.println(jtoken);

        String madeemail = jwtUtil.validateAndExtract(jtoken);
        System.out.println(madeemail);
    }


}
