package jniUtils;

import android.util.Log;

/**
 * Created by admin on 2018/12/7.
 */

public class FfempegUtils {

    static {
        System.loadLibrary("swscale");
        System.loadLibrary("avdevice");
        System.loadLibrary("avfilter");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("avutil");
        System.loadLibrary("ffempeg");
    }

    public native int runFfempeg(String[] commonds);

    public void progress(String progress){
     //   Log.i("MDL","progress:" + progress);
        //return progress;
    }

}
