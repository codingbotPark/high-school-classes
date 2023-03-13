package com.example.ex2220907;

import com.example.ex2220907.components.A;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class Ex2220907Application {

	public static void main(String[] args) {
		SpringApplication.run(Ex2220907Application.class, args);
	}

	@Bean
	public A a(){
		return new A();
	}

}
