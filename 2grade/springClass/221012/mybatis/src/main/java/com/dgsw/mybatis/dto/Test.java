package com.dgsw.mybatis.dto;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.NotEmpty;

@Getter
@Setter
@ToString
@AllArgsConstructor
public class Test {

//    Test(String aa,String bb){
//        this.aa = aa;
//        this.bb = bb;
//    }

    @NotEmpty
    @Length(min = 4)
    private String aa;

    @NotEmpty
    private String bb;

    private Integer idx;

}
