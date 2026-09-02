# 安裝與設定

本頁說明開始使用 CYD 所需的基本設定。

## 硬體設定

硬體幾乎不需要額外設定，只要用 micro-USB 線把 CYD 接上電腦即可；多數賣家也會隨板附線。

## 軟體設定

不論使用 Arduino IDE 或網頁燒錄，電腦都需要能辨識 CYD 的 USB 轉序列埠晶片。

### 驅動程式

CYD 使用 CH340 USB-to-UART 晶片。如果電腦尚未安裝 CH340 驅動程式，請參考 [SparkFun 的 CH340 安裝說明](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all)。

## Arduino 程式開發設定

如果要自行撰寫 CYD 程式，請完成以下設定。

### 開發板定義

先在 Arduino IDE 安裝 ESP32 board package，步驟請參考 [Arduino-ESP32 官方安裝文件](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)。

接著可在開發板選單選擇一般 ESP32 開發板；原作者通常使用 `ESP32 Dev Module`。如果上傳時發生錯誤，可先把 Upload Speed 改為 `115200`。

### 函式庫設定

CYD 可搭配多種顯示函式庫；原專案主要使用 [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)，因為使用者多、範例也完整。

請在 Arduino IDE 的 Library Manager 搜尋並安裝 `TFT_eSPI`。

> 安裝完成後，必須把上游 repo 的 [`DisplayConfig/User_Setup.h`](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/DisplayConfig/User_Setup.h) 複製到 Arduino 的 `libraries\TFT_eSPI` 資料夾，讓函式庫使用正確的 CYD 顯示腳位。

雙 USB 的 CYD2USB 顯示器設定不同，請改用 [`DisplayConfig/CYD2USB/User_Setup.h`](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/DisplayConfig/CYD2USB)。詳見 [CYD 與 CYD2USB](cyd.md)。

### 範例

完成設定後，可從[繁中基礎範例 1～3](Examples/Basics/)開始，其他範例位於[英文原始 repo](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/Examples)。
