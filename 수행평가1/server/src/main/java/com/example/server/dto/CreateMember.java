package com.example.server.dto;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;

@NoArgsConstructor
@AllArgsConstructor
@Getter
public class CreateMember {
    @NotBlank(message = "이름은 필수 값입니다")
    private String name;

    @NotBlank(message = "이메일은 필수 입력값입니다")
    @Email(message = "이메일 형식으로 입력해주세요")
    private String email;

    @NotEmpty(message = "비밀번호는 필수 값입니다")
    @Length(min=8,max=20, message="비밀번호는 8자 이상, 20자 이하로 입력해주세요")
    private String password;

}
