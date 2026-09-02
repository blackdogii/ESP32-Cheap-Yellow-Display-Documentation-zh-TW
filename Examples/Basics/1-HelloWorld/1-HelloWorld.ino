/*******************************************************************
    ESP32 Cheap Yellow Display 的 Hello World 範例。

    https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display

    如果這些內容對你有幫助，歡迎贊助原作者：
    https://github.com/sponsors/witnessmenow/

    原作者：Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

// 請先依 GitHub 說明，把正確的 User_Setup.h 複製到函式庫；
// 顯示器腳位定義在該檔案中。

// Font 1：原始 Adafruit 8 pixel 字型，FLASH 約需 1820 bytes。
// Font 2：16 pixel 高的小字型，96 個字元，FLASH 約需 3534 bytes。
// Font 4：26 pixel 高的中字型，96 個字元，FLASH 約需 5848 bytes。
// 以下較大字型主要只包含數字。
// Font 6：48 pixel 大字型，只有 1234567890:-.apm，約需 2666 bytes。
// Font 7：48 pixel 七段顯示字型，只有 1234567890:-.，約需 2438 bytes。
// Font 8：75 pixel 大字型，只有 1234567890:-.，約需 3256 bytes。

#include <TFT_eSPI.h>
// LCD 顯示器介面函式庫。
//
// 可在 Library Manager 搜尋 "TFT_eSPI" 安裝。
// https://github.com/Bodmer/TFT_eSPI

TFT_eSPI tft = TFT_eSPI();

void setup() {
  // 初始化 TFT 顯示器。
  tft.init();
  tft.setRotation(1); // 橫向顯示。
  
  // 寫入文字前先清除畫面。
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  int x = 5;
  int y = 10;
  int fontNum = 2; 
  tft.drawString("Hello", x, y, fontNum); // 靠左對齊。
  x = 320 /2;
  y += 16;
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.drawCentreString("World", x, y, fontNum);

}

void loop() {
  // 主迴圈不需要重複執行內容。

}
