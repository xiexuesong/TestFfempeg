1、libavformat：用于各种音视频封装格式的生成和解析，包括获取解码所需信息以生成解码上下文结构和读取音视频帧等功能，包含demuxers和muxer库；

2、libavcodec：用于各种类型声音/图像编解码；

3、libavutil：包含一些公共的工具函数；

4、libswscale：用于视频场景比例缩放、色彩映射转换；

5、libpostproc：用于后期效果处理；

6、ffmpeg：是一个命令行工具，用来对视频文件转换格式，也支持对电视卡实时编码；

7、ffsever：是一个HTTP多媒体实时广播流服务器，支持时光平移；

8、ffplay：是一个简单的播放器，使用ffmpeg 库解析和解码，通过SDL显示；