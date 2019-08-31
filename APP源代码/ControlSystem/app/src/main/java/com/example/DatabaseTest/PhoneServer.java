package com.example.DatabaseTest;

import android.os.Handler;
import android.os.Message;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class PhoneServer implements Runnable {
    private ServerSocket server;
    private DataInputStream in;
    private byte[] receice;

    private Handler handler = new Handler();

    public PhoneServer() {
    }

    public void setHandler(Handler handler) {
        this.handler = handler;
    }

    @Override
    public void run() {

        try {
            //5000是手机端开启的服务器的端口号，ESP8266进行TCP连接时使用的端口，而IP也是通过指令查询的联入设备的IP
            server = new ServerSocket(5000);
            while (true) {
                Socket client = server.accept();
                in = new DataInputStream(client.getInputStream());
                receice = new byte[50];
                in.read(receice);
                in.close();

                Message message = new Message();
                message.what = 1;
                message.obj = new String(receice);
                handler.sendMessage(message);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            server.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

