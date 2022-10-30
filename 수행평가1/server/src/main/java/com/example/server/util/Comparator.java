package com.example.server.util;

import com.example.server.entity.Post;

public class Comparator implements java.util.Comparator<Post> {
    @Override
    public int compare(Post o1, Post o2) {
        if (o1.getId() < o2.getId()) {
            return 1;
        } else if (o1.getId() > o2.getId()) {
            return -1;
        }
        return 0;
    }
}
