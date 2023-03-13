package com.example.server.entity;

import lombok.Getter;
import lombok.NoArgsConstructor;

import javax.persistence.*;

@Entity
@Getter @NoArgsConstructor
public class Image {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long imageId;

    private String imgName;

    // sql에 그냥 넣으면 안 들어가기 때문에
    @Lob
    @Column(columnDefinition = "MEDIUMBLOB")
    private byte[] imgByte;

    public Image(String imgName, byte[] imgByte) {
        this.imgName = imgName;
        this.imgByte = imgByte;
    }
    public void updateImage(String imgName,byte[] imgByte){
        this.imgName = imgName;
        this.imgByte = imgByte;
    }
}
