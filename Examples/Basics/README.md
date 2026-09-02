# 基礎範例

本資料夾收錄英文上游 Basics 1～3 的繁中註解版。程式邏輯、腳位與字串保持上游基準 commit `dc3771e51ce27018ae62c658470ee8d6d7177567` 不變。

1. [`1-HelloWorld`](1-HelloWorld/)：初始化螢幕並顯示文字。
2. [`2-TouchTest`](2-TouchTest/)：讀取觸控壓力與座標。
3. [`3-SDCardTest`](3-SDCardTest/)：測試 microSD 卡讀寫與檔案操作。

Arduino IDE 使用者請先依[安裝與設定](../../SETUP.md)放置正確的 `User_Setup.h`。PlatformIO 使用者可在 `platformio.ini` 選擇 `cyd` 或 `cyd2usb` environment。
