package com.wangzhen.admin.testffempeg;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import jniUtils.FfempegUtils;

public class MainActivity extends AppCompatActivity {

    private String commonds ;
    public static final String PATH = Environment.getExternalStorageDirectory().getAbsolutePath() + "/apeng/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final String mVideoPath = Environment.getExternalStorageDirectory().getAbsolutePath()  +  "/out.mp4";

        final String currentOutputVideoPath = PATH + "clip.mp4";
        int videoWidth = 1920;
        int videoHeight = 1080;

        /**
         *  + "-s " + videoWidth + "x" + videoHeight + "
         */
        //由于剪切视频是耗时操作,所以异步操作
        new Thread(){
            @Override
            public void run() {
                super.run();
                //剪切视频
                String cmd = "-y " + "-ss 2 -i " + mVideoPath + " -r 20 -t 10 " + currentOutputVideoPath;
                String[] commands = cmd.split(" ");
                FfempegUtils ffempegUtils = new FfempegUtils();
                ffempegUtils.runFfempeg(commands);
            }
        }.start();

    //    Log.i("MDL","ret:" + ret);


    }
}
