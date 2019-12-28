# 用ESP8266破解悦享校园
<p align="center"><img alt="PICTURE" src="https://i.loli.net/2019/12/28/eSGROt32XV7jciF.png" width="500"></p>
## About this project
This project is to crack the hot water system of CSUST(长沙理工大学云塘) by using an ESP8266 WiFi SoC.

No one seems to care about the huge vulnerability in the hot water system, so I took action and enabled everyone who has less than 20 yuan to spare to recreate this project.

The official encrypted the communication in the update of the subsequent versions of the app, but it's a band-aid at best. I was opposed to this so-called technological upgrade from the beginning. The more features, the wider the attack surface.

I hope it raises more attention on the issue, but I don't want it to run rampant. So I wrote these words in my poor English.

## Disclaimer
This project is a proof of concept for testing and educational purposes.

Please don't use it to make dirty money, that totally undermines the real purpose of this project!

I don't take any responsibility for what you do with this program.

## Getting Started
#### Supported Devices
This software is written for the ESP8266. There are plenty of development boards available.

I recommend **NodeMCU** because it is more friendly for beginners. You can get them from Taobao.

#### Packet Capture
1. Install a packet capture APP like `抓包精灵` on your smart phone.

2. Install `悦享校园`, the version I provided.

3. Sniff the network traffic during normal app usage.


#### Compiling using Arduino IDE
1. First you have to install and open the [Arduino IDE](https://www.arduino.cc/en/Main/Software?setlang=cn) .

2. In Arduino go to 文件 -> 首选项 add url in 附加开发板管理器网址http://arduino.esp8266.com/stable/package_esp8266com_index.json

3. Go to 工具 -> 开发板 -> 开发板管理器, search `esp8266` and install the latest version.

4. Select your board at 工具 -> 开发板, be sure it is at `ESP8266 Boards`.

5. Go to 工具 -> 管理库, search `ArduinoJson` and install the version 5.13.5.

6. Download the source code and open `esp8266_csust_yuexiang.ino` with Arduino.

7. Modify settings based on packet capture results.

8. Check your upload settings(工具 -> 端口) and press upload!

#### Instructions
1. Connect the WiFi of ESP8266 with smart phone after powering up the development board.

2. Open the app provided by me. Mobile number and verification code can be filled in at will.

3. Enjoy it!

## License
This software is licensed under the MIT License. See the license file for details.
