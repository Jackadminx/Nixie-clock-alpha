![1](./1.png)

简单辉光管时钟

也是我的第一个完整的电子设计项目

还有很多地方需要完善，**不推荐直接使用**

感谢UP主[小鲤Magikarp](https://space.bilibili.com/196915)制作教程视频，不然我还真没思路🤣



### 开发环境：

立创EDA

Fusion360

PlatformIO



### 硬件

Arduino系列开发板

DS3231高精度时钟模块

QS30-1/SZ-8辉光管

K155ID1/SN74141N辉光管驱动IC

74HC595N

5V转170V电源升压模块

电阻，辉光管底座等



### 缺陷

驱动电路与MCU分离 

辉光管与电路板需要大量线路连接

设计时未考虑氖泡，使用LED二极管代替

3D模型设计时过分紧凑，安装困难，有些地方需要打磨扩大



### tree
```
├─Hardware
│  ├─3DPrint
│  ├─PCB
│  └─Schematics
└─Software
    └─Nixie-alpha-code
        ├─include
        ├─lib
        │  ├─DS3232RTC_ID78
        │  │  ├─examples
        │  │  │  ├─alarm_ex1
        │  │  │  ├─alarm_ex2
        │  │  │  ├─alarm_ex3
        │  │  │  ├─alarm_ex4
        │  │  │  ├─alarm_ex5
        │  │  │  ├─alarm_ex6
        │  │  │  ├─alarm_ex7
        │  │  │  ├─SetSerial
        │  │  │  ├─TimeRTC
        │  │  │  └─tiny3232_KnockBang
        │  │  └─src
        │  └─Time_ID44
        │      └─examples
        │          ├─Processing
        │          │  └─SyncArduinoClock
        │          ├─TimeArduinoDue
        │          ├─TimeGPS
        │          ├─TimeNTP
        │          ├─TimeNTP_ESP8266WiFi
        │          ├─TimeRTC
        │          ├─TimeRTCLog
        │          ├─TimeRTCSet
        │          ├─TimeSerial
        │          ├─TimeSerialDateStrings
        │          └─TimeTeensy3
        └─src
```
