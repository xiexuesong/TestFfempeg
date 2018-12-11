package jniUtils;

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

    public static native int runFfempeg(String[] commonds);

}
