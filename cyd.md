# CYD 與相似板型

## 什麼是 Cheap Yellow Display（CYD）？

CYD 指的是 `ESP32-2432S028`：整合 ESP32、2.8 吋顯示器與電阻式觸控的開發板。

市面上還有許多不同尺寸、外觀相似的顯示板，但它們不一定是 CYD。這不是要排除其他硬體，而是不同顯示器與板型的差異很多，若全部混在一起會難以提供正確支援。

請查看顯示板背面的型號來確認。

![CYD 背面型號](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/assets/1562562/d23bf84f-f34b-4814-b609-87c359d6334e)

## 我的 CYD 有兩個 USB 連接埠

原版 CYD 只有 micro-USB。另有一種同樣標示 `ESP32-2432S028` 的板子，同時具有 micro-USB 與 USB-C，通常稱為 CYD2USB。

它不只多一個 USB 連接埠，顯示器驅動與顏色設定也不同。可用以下方式處理：

- 使用 PlatformIO：上游範例已提供 `cyd` 與 `cyd2usb` environment。
- 使用上游 repo 的 [CYD2USB 專用 `User_Setup.h`](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/DisplayConfig/CYD2USB)。該設定使用 `ST7789_DRIVER` 與 `TFT_BGR`。
- 某些程式可呼叫 `tft.invertDisplay(1);` 修正反相，但這不能取代正確的顯示驅動設定。

## USB-C 連接埠無法使用

這個 USB-C 連接埠缺少 CC 線所需電阻，因此 USB-C 對 USB-C 傳輸線通常無法工作。

如果電腦只有 USB-C，可改用 USB-C 轉 USB-A 轉接器，再接 USB-A 對 micro-USB／USB-C 線。

## 顯示效果不佳

CYD2USB 似乎有 gamma 顯示問題。原始文件提供以下嘗試方式：

```cpp
tft.writecommand(ILI9341_GAMMASET); // 選擇 gamma curve
tft.writedata(2);
delay(120);
tft.writecommand(ILI9341_GAMMASET);
tft.writedata(1);
```

這段程式沿用英文原文，但 CYD2USB 的正確顯示設定使用 ST7789。請先套用 CYD2USB 專用 `User_Setup.h`，再依實際面板測試；不要把這段程式視為所有 CYD2USB 的通用修正。
