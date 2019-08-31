package com.example.DatabaseTest;

import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.CheckBox;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity{
    private TextView tv_content;
    private Switch btn1,btn2, btn3, btn4;
    private CheckBox btn5, btn6, btn7, btn8, btn9;
    private String str;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        InitView();                                  //按钮初始化
        lisetenOnClick();                            //设置按钮监听事件
        PhoneServer mobileServer = new PhoneServer();//开启服务器
        mobileServer.setHandler(handler);
        new Thread(mobileServer).start();            //创建线程
    }
    public void lisetenOnClick()
    {
        btn1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if (isChecked) {
                    str = "1";new Send().execute(str);
                }
                else{
                    str = "1";new Send().execute(str);tv_content.setText("     ");
                }

            }
        } );
        btn2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                str = "2";
                new Send().execute(str);
            }
        } );
        btn3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "3";closeFlow();closeRadio();
                    new Send().execute(str);
                }
                else{
                    str = "3";new Send().execute(str);
                    openFlow();openRadio();
                }
            }
        } );
        btn4.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "4";closeLight();closeRadio();
                    new Send().execute(str);
                }
                else {
                    str = "4";new Send().execute(str);
                    openLight();openRadio();
                }
            }
        } );
        btn5.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "5";closeLight();closeFlow();
                    new Send().execute(str);
                }
                else{
                    str = "5";new Send().execute(str);
                    if (ifRadio() == 1)
                    {
                        openLight();openFlow();
                    }
                }
            }
        } );
        btn6.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "6";closeLight();closeFlow();
                    new Send().execute(str);
                }
                else{
                    str = "6";new Send().execute(str);
                    if (ifRadio() == 1)
                    {
                        openLight();openFlow();
                    }
                }
            }
        } );
        btn7.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "7";closeLight();closeFlow();
                    new Send().execute(str);
                }
                else{
                    str = "7";new Send().execute(str);
                    if (ifRadio() == 1)
                    {
                        openLight();openFlow();
                    }
                }
            }
        } );
        btn8.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "8";closeLight();closeFlow();
                    new Send().execute(str);
                }
                else{
                    str = "8";new Send().execute(str);
                    if (ifRadio() == 1)
                    {
                        openLight();openFlow();
                    }
                }
            }
        } );
        btn9.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                // TODO Auto-generated method stub
                if(!buttonView.isPressed()) {
                    return;
                }
                if (isChecked) {
                    str = "9";closeLight();closeFlow();
                    new Send().execute(str);
                }
                else{
                    str = "9";new Send().execute(str);
                    if (ifRadio() == 1)
                    {
                        openLight();openFlow();
                    }
                }
            }
        } );

    }
    ///////////////////////按钮初始化函数///////////////////////////
    private void InitView()
    {
        tv_content = (TextView) findViewById(R.id.temp);
        btn1 = (Switch) findViewById(R.id.btn1);
        btn2 = (Switch) findViewById(R.id.btn2);
        btn3 = (Switch) findViewById(R.id.btn3);
        btn4 = (Switch) findViewById(R.id.btn4);
        btn5 = (CheckBox) findViewById(R.id.rbt1);
        btn6 = (CheckBox) findViewById(R.id.rbt2);
        btn7 = (CheckBox) findViewById(R.id.rbt3);
        btn8 = (CheckBox) findViewById(R.id.rbt4);
        btn9 = (CheckBox) findViewById(R.id.rbt5);
    }
    ///////////////////////关闭全亮按钮///////////////////////////
    public void closeLight()
    {
        if(btn3.isChecked()==true)
        {
            btn3.setChecked(false);str = "3";new Send().execute(str);
        }btn3.setEnabled(false);
    }
    ///////////////////////打开全亮按钮///////////////////////////
    public void openLight()
    {
        btn3.setEnabled(true);
    }
    ///////////////////////关闭流水灯按钮/////////////////////////
    public void closeFlow()
   {
       if(btn4.isChecked()==true)
       {
           btn4.setChecked(false);str = "4";new Send().execute(str);
       }btn4.setEnabled(false);
   }
    ///////////////////////打开流水灯按钮/////////////////////////
    public void openFlow()
    {
        btn4.setEnabled(true);
    }
    ///////////////////////打开LED控制按钮/////////////////////////
    public void openRadio()
    {
        btn5.setEnabled(true);btn6.setEnabled(true);btn7.setEnabled(true);
        btn8.setEnabled(true);btn9.setEnabled(true);
    }
    ///////////////////////判断是否有LED亮着////////////////////////
    public int ifRadio()
    {
        if(btn5.isChecked()==true) return 0;
        if(btn6.isChecked()==true) return 0;
        if(btn7.isChecked()==true) return 0;
        if(btn8.isChecked()==true) return 0;
        if(btn9.isChecked()==true) return 0;
        return 1;
    }
    ///////////////////////关闭LED控制按钮/////////////////////////
    public void closeRadio()
    {
        if(btn5.isChecked()==true)
        {
            btn5.setChecked(false);str = "5";new Send().execute(str);
        }
        if(btn6.isChecked()==true)
        {
            btn6.setChecked(false);str = "6";new Send().execute(str);
        }
        if(btn7.isChecked()==true)
        {
            btn7.setChecked(false);str = "7";new Send().execute(str);
        }
        if(btn8.isChecked()==true)
        {
            btn8.setChecked(false);str = "8";new Send().execute(str);
        }
        if(btn9.isChecked()==true)
        {
            btn9.setChecked(false);str = "9";new Send().execute(str);
        }
        btn5.setEnabled(false);btn6.setEnabled(false);
        btn7.setEnabled(false);btn8.setEnabled(false);
        btn9.setEnabled(false);
    }
    ////////////////////////////监听用户点击事件////////////////////////


    Handler handler = new Handler() {
        public void handleMessage(Message msg) {  ///////////////////*温度数值的显示*********/
            switch (msg.what) {
                case 1:
                    if(btn1.isChecked())tv_content.setText(""+msg.obj);
            }
        }
    };

}