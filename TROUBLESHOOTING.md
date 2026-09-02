# CYD 疑難排解

## 先確認板子真的是 CYD

遇到問題時，第一步先檢查板型。

本 repo 的範例與資訊只針對 `ESP32-2432S028`。型號通常以金色文字印在板子背面、喇叭接頭旁。外觀相似但型號不同的顯示板不一定相容，詳見 [CYD 與 CYD2USB](cyd.md)。

## 顯示器沒有亮

先從原始 repo 的[已知可用網頁燒錄作品](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/PROJECTS.md#projects-1)測試。如果現成韌體能正常顯示，通常表示硬體正常，問題較可能在本機開發環境或程式設定。

### 現成網頁燒錄作品可以正常顯示

- 確認已依[函式庫設定](SETUP.md#函式庫設定)，把正確的 `User_Setup.h` 放入 TFT_eSPI 函式庫。
- IO21 是背光腳位，確認 sketch 沒有把它用於其他用途。
- 雙 USB 的 CYD2USB 必須使用對應的 ST7789 設定，不能直接套用原版 CYD 的 ILI9341 設定。

### 現成網頁燒錄作品也無法顯示

- 不要把任何裝置接到 P3 的 IO21。
- 更換 USB 電源或傳輸線。
- 若以上方式都無效，板子可能故障，請聯絡賣家。

## 顯示、觸控與 microSD 無法同時運作

ESP32 有兩組可用的硬體 SPI bus，但 CYD 的顯示器、觸控與 microSD 分別接在三組配置上。若三者要同時使用，其中一項必須改用軟體模擬 SPI。

一般會讓頻寬需求較低的觸控使用 software SPI，例如 [XPT2046_Bitbang_Slim](https://github.com/TheNitek/XPT2046_Bitbang_Arduino_Library)，並參考上游的 [Buttons 範例](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/Examples/Basics/8-Buttons)。

## 顯示器閃爍

- 更換 USB 電源或傳輸線。
- 依照[顯示器沒有亮](#顯示器沒有亮)的步驟逐項檢查。
- 若仍無法解決，板子可能故障，請聯絡賣家。

## 無法上傳

- Ubuntu 與其衍生版本請停用或移除 `brltty` service，並確認目前使用者屬於 `dialout` 群組。
- 可嘗試把 Arduino IDE 的 Upload Speed 改成 `115200`。

## esptool 自動進入燒錄模式失敗：Wrong boot mode detected (0x13)

這是 ESP32 透過 USB-to-UART 燒錄時的已知問題。DTR 與 RTS 訊號會透過額外的 2×NPN 電晶體邏輯切換 bootloader；在某些電腦、作業系統或驅動版本能正常運作，在其他環境則可能失敗：

```text
A fatal error occurred: Failed to connect to ESP32: Wrong boot mode detected (0x13)!
The chip needs to be in download mode.
```

原始文件建議把 EN（RST）與 GND 間的 0.1 µF 電容更換為 1～10 µF。

> 原理圖將它標為 C4，但至少在 Type-C 版本的 CYD 上，實際位置是 C5。這項操作需要拆焊；不熟悉焊接時，先改用手動按住 BOOT／RESET 的燒錄方式或尋求協助。
