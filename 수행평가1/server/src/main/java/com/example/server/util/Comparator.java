package com.example.server.util;

import com.example.server.dto.LoadPost;
import com.example.server.entity.Post;

public class Comparator implements java.util.Comparator<LoadPost> {


    @Override
    public int compare(LoadPost o1, LoadPost o2) {
        if (o1.getTime().isAfter(o2.getTime())) {
            return 1;
        } else if (o1.getTime().isBefore(o2.getTime())) {
            return -1;
        }
        return 0;
    }
}
