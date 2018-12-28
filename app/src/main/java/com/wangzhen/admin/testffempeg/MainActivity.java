package com.wangzhen.admin.testffempeg;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import jniUtils.FfempegCmdUtils;
import jniUtils.FfempegUtils;
import thread.ThreadPoolProxy;

public class MainActivity extends AppCompatActivity {

    private String commonds;
    public static final String PATH = Environment.getExternalStorageDirectory().getAbsolutePath() + "/apeng/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final String mVideoPath = Environment.getExternalStorageDirectory().getAbsolutePath() + "/out.mp4";

        final String currentOutputVideoPath = PATH + "clip.mp4";
        int videoWidth = 1920;
        int videoHeight = 1080;
        final String size = "300*300";

        /**
         *  + "-s " + videoWidth + "x" + videoHeight + "
         */
        final String[] cmd1 = FfempegCmdUtils.clipVideo("2", "10", 25, mVideoPath, currentOutputVideoPath, size);
        String path = Environment.getExternalStorageDirectory() + "/apeng/pic/";
        String[] cmd2 = FfempegCmdUtils.videoToImages("2", "10", mVideoPath, path, 1);
        String[] cmd3 = FfempegCmdUtils.compressToSpecifiedSize(mVideoPath, currentOutputVideoPath, "10M");
        final String[][] cmdArray = {cmd1, cmd2, cmd3};
        final FfempegUtils ffempegUtils = new FfempegUtils();
        ThreadPoolProxy.getFixedThreadPool(1).execute(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < cmdArray.length; i++) {
                    if (i == 2) {
                        ffempegUtils.runFfempeg(cmdArray[i]);
                    }
                }
            }
        });

        //    Log.i("MDL","ret:" + ret);


    }
}
