package jniUtils;

/**
 * Created by admin on 2018/12/7.
 */

public class FfempegUtils {

    {
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("avutil");
        System.loadLibrary("ffempeg");
    }

    public static native void  runFfempeg();

}
