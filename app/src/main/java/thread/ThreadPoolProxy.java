package thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Created by admin on 2018/12/28.
 */

public class ThreadPoolProxy {

    public static ExecutorService getFixedThreadPool(int size){
        ExecutorService executorService = Executors.newFixedThreadPool(size);//核心线程数
        return executorService;
    }

}
