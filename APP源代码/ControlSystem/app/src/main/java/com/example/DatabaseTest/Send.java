package com.example.DatabaseTest;

import android.os.AsyncTask;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;

public class Send extends AsyncTask<String, Void, Void> {

    //这里是连接ESP8266的IP和端口号，IP是通过指令在单片机开发板查询到，而端口号可以自行设置，也可以使用默认的，333就是默认的
    private static final String IP = "192.168.4.1";
    private static final int PORT = 8080;

    private Socket client = null;
    private PrintStream out = null;

    protected Void doInBackground(String... params) {
        String str = params[0];
        try {
            client = new Socket(IP, PORT);//通过IP地址和端口实例化Socket，请求连接服务器
            client.setSoTimeout(5000);
            // 获取Socket的输出流，用来发送数据到服务端
            out = new PrintStream(client.getOutputStream());
            out.print(str);
            out.flush();

            if (client == null) {
                return null;
            } else {
                out.close();
                client.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

}
