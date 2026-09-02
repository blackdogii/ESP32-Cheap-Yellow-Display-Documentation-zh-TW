/*******************************************************************
    ESP32 Cheap Yellow Display 的觸控螢幕測試。

    https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display

    如果這些內容對你有幫助，歡迎贊助原作者：
    https://github.com/sponsors/witnessmenow/

    原作者：Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

// 請先依 GitHub 說明，把正確的 User_Setup.h 複製到函式庫；
// 顯示器腳位定義在該檔案中。

// ----------------------------
// 標準函式庫
// ----------------------------

#include <SPI.h>

// ----------------------------
// 額外函式庫：以下函式庫都需要另行安裝。
// ----------------------------

#include <XPT2046_Touchscreen.h>
// 觸控螢幕介面函式庫。
//
// 可在 Library Manager 搜尋 "XPT2046" 安裝。
// https://github.com/PaulStoffregen/XPT2046_Touchscreen

#include <TFT_eSPI.h>
// LCD 顯示器介面函式庫。
//
// 可在 Library Manager 搜尋 "TFT_eSPI" 安裝。
// https://github.com/Bodmer/TFT_eSPI

// ----------------------------
// 觸控螢幕腳位
// ----------------------------

// CYD 觸控使用非預設的 SPI 腳位。

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

// ----------------------------

SPIClass mySpi = SPIClass(VSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);

  // 啟動觸控使用的 SPI，並初始化觸控函式庫。
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  ts.begin(mySpi);
  ts.setRotation(1);

  // 初始化 TFT 顯示器。
  tft.init();
  tft.setRotation(1); // 橫向顯示。

  // 寫入文字前先清除畫面。
  tft.fillScreen(TFT_BLACK);

  int x = 320 / 2; // 畫面中央。
  int y = 100;
  int fontSize = 2;
  tft.drawCentreString("Touch Screen to Start", x, y, fontSize);
}

void printTouchToSerial(TS_Point p) {
  Serial.print("Pressure = ");
  Serial.print(p.z);
  Serial.print(", x = ");
  Serial.print(p.x);
  Serial.print(", y = ");
  Serial.print(p.y);
  Serial.println();
}

void printTouchToDisplay(TS_Point p) {

  // 先清除畫面。
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  int x = 320 / 2; // 畫面中央。
  int y = 100;
  int fontSize = 2;

  String temp = "Pressure = " + String(p.z);
  tft.drawCentreString(temp, x, y, fontSize);

  y += 16;
  temp = "X = " + String(p.x);
  tft.drawCentreString(temp, x, y, fontSize);

  y += 16;
  temp = "Y = " + String(p.y);
  tft.drawCentreString(temp, x, y, fontSize);
}

void loop() {
  if (ts.tirqTouched() && ts.touched()) {
    TS_Point p = ts.getPoint();
    printTouchToSerial(p);
    printTouchToDisplay(p);
    delay(100);

  }
}
