package jniUtils;

import java.util.Locale;

/**
 * ffmpeg命令处理视频
 * Created by admin on 2018/12/28.
 */

public class FfempegCmdUtils {


    /**
     * 处理视频转帧图片
     *
     * @param startTime     从什么时间开始截  单位s
     * @param duration      持续时间
     * @param inputFilePath 输入的文件路径
     * @param outPutPath    输出路径
     * @param frameRate     帧率 就是一秒抽多少帧图片
     * @return
     */
    public static String[] videoToImages(String startTime, String duration, String inputFilePath, String outPutPath, int frameRate) {
        String cmd = "ffmpeg -i %s -ss %s -t %s -r %s %s";
        cmd = String.format(Locale.CHINESE, cmd, inputFilePath, startTime, duration, frameRate, outPutPath);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(cmd);
        stringBuilder.append("%3d.jpg");
        cmd = stringBuilder.toString();
        return cmd.split(" ");
    }

    /**
     * 截取视频片段 从2s 截取10s 视频 -r 表示视频帧率为20 尺寸 352*240 输出路径 clip.mp4
     * ffmpeg -y -ss 2 -i test.mp4 -r 20 -t 10 -s 352x240 clip.mp4
     * @param startTime 开始时间
     * @param duration 持续时间
     * @param frameRate 帧率
     * @param inputPath 输入路径
     * @param outPutPath 输出路径
     * @param size 视频尺寸
     * @return
     */
    public static String[] clipVideo(String startTime, String duration, int frameRate, String inputPath, String outPutPath, String size) {
        String cmd = "ffmpeg -y -ss %s -i %s -r %d -t %s -s %s %s";
        cmd = String.format(Locale.CHINESE,cmd,startTime,inputPath,frameRate,duration,size,outPutPath);
        return cmd.split(" ");
    }




}
