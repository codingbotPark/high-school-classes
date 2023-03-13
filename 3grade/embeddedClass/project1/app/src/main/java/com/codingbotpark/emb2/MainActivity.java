package com.codingbotpark.emb2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    int yy = 0;

    int count = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);
        //setContentView(new CustomView(this));

//        CustomView CustomView = new CustomView(this);
//        setContentView(CustomView);

        MyView MyView = new MyView(this);
        setContentView(MyView);


        new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    // 코드 작성
                    Log.d("haha","hello"+count);

                    loop_func(MyView);
                    count+=1;
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }

    void loop_func(MyView MyView)
    {
        yy =20;
        MyView.y1 = MyView.y1+yy;
        MyView.y2 = MyView.y2+yy;
        MyView.invalidate(); //데이터갱신
    }
}


class MyView extends View {
    //생성자에 인수를 세개 준다. 생성자를 세개 다 만들어줘야한다. 생성자들앞에 public붙여야함
    public MyView(Context context){
        super(context);
    }
    public MyView(Context context, AttributeSet att){
        super(context,att);
    }
    public MyView(Context context,AttributeSet att, int a){
        super(context,att,a);
    }

    //사각형 좌표값의 값을 변수로 설정!
    int x1=100,y1=100,x2=300,y2=300;
    @Override //부모가 가진 onDraw와 오버라이딩
    public void onDraw(Canvas c){
        Paint paint= new Paint();
        paint.setColor(Color.DKGRAY);
        c.drawRect(x1, y1, x2, y2, paint);

        //-----------------------------------------------------------
        Paint paint1 = new Paint(); //페인트 객체 생성
        paint1.setColor(Color.GRAY); //페인트 색 지정
        paint1.setStyle(Paint.Style.STROKE); //STROKE 스타일로 그리기
        paint1.setStrokeWidth(10.0F); //STROKE 두께 지정
        c.drawLine(300, 300, 500, 500, paint1);
        //-----------------------------------------------------------
    }
}