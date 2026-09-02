# CYD 腳位

本頁整理 CYD 上各接頭與內建元件使用的腳位。

## 接頭類型

這些接頭常被稱為「1.25 mm JST」，正確名稱是 Molex PicoBlade；中國製相容品有時會標示 `mx1.25`。

| 接頭 | 類型 | 用途 |
|---|---|---|
| [P1](#p1) | 4P 1.25 mm Molex PicoBlade | Serial |
| [P3](#p3) | 4P 1.25 mm Molex PicoBlade | GPIO |
| [P4](#喇叭) | 2P 1.25 mm Molex PicoBlade | Speaker |
| [CN1](#cn1) | 4P 1.25 mm Molex PicoBlade | GPIO／I2C |

## 可直接使用的 GPIO

板上有三個容易接線的 GPIO：

| 腳位 | 位置 | 注意事項 |
|---|---|---|
| IO35 | P3 | 只能輸入，沒有內建 pull-up |
| IO22 | P3 與 CN1 | 兩個接頭是同一腳位 |
| IO27 | CN1 | |

若需要更多腳位，可考慮英文原始文件提到的 [microSD sniffer 擴充方式](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/ADDONS.md)，再往後通常就需要拆焊既有元件。

## 引出接頭

板上有三個 4P、1.25 mm Molex PicoBlade 接頭。

### P3

| 腳位 | 用途 | 注意事項 |
|---|---|---|
| GND | | |
| IO35 | | 只能輸入，沒有內建 pull-up |
| IO22 | | 同時出現在 CN1 |
| IO21 | TFT 背光 | 已被背光使用，通常不應另作 GPIO |

### CN1

CN1 很適合連接 I2C 裝置。

| 腳位 | 用途 | 注意事項 |
|---|---|---|
| GND | | |
| IO22 | | 同時出現在 P3 |
| IO27 | | |
| 3.3V | | |

### P1

| 腳位 | 用途 | 注意事項 |
|---|---|---|
| VIN | | |
| IO1（？） | TX | 可能可當 GPIO 使用 |
| IO3（？） | RX | 可能可當 GPIO 使用 |
| GND | | |

## 按鈕

CYD 有 Reset 與 Boot 兩個按鈕。

| 腳位 | 用途 | 注意事項 |
|---|---|---|
| IO0 | BOOT | 可在 sketch 中作輸入使用 |

## 喇叭

2P、1.25 mm Molex PicoBlade 喇叭接頭已連到擴大器，因此不能直接把該接頭當一般 GPIO 使用。

| 腳位 | 用途 | 注意事項 |
|---|---|---|
| IO26 | 連接擴大器 | `i2s_set_dac_mode(I2S_DAC_CHANNEL_LEFT_EN);` |

## RGB LED

如果專案非常缺腳位，可以考慮犧牲板上的 RGB LED。LED 是 active-low：`HIGH` 代表關閉，`LOW` 代表亮起。

| 腳位 | 用途 |
|---|---|
| IO4 | 紅色 LED |
| IO16 | 綠色 LED |
| IO17 | 藍色 LED |

## microSD 卡

microSD 卡使用 VSPI，腳位名稱已在 `SPI.h` 中預先定義。

| 腳位 | 用途 |
|---|---|
| IO5 | SS |
| IO18 | SCK |
| IO19 | MISO |
| IO23 | MOSI |

## 觸控螢幕

| 腳位 | 用途 |
|---|---|
| IO25 | XPT2046_CLK |
| IO32 | XPT2046_MOSI |
| IO33 | XPT2046_CS |
| IO36 | XPT2046_IRQ |
| IO39 | XPT2046_MISO |

## 光敏電阻（LDR）

| 腳位 | 用途 |
|---|---|
| IO34 | 光線感測 |

## 顯示器

顯示器使用 HSPI。

| 腳位 | 用途 | 其他名稱／注意事項 |
|---|---|---|
| IO2 | TFT_RS | TFT_DC |
| IO12 | TFT_SDO | TFT_MISO |
| IO13 | TFT_SDI | TFT_MOSI |
| IO14 | TFT_SCK | |
| IO15 | TFT_CS | |
| IO21 | TFT_BL | 不明原因也被引到 P3 |

## 測試焊盤

| 焊盤 | 用途 | 位置／注意事項 |
|---|---|---|
| S1 | GND | 靠近 USB-SERIAL |
| S2 | 3.3V | ESP32 使用 |
| S3 | 5V | 靠近 USB-SERIAL |
| S4 | GND | ESP32 使用 |
| S5 | 3.3V | TFT 使用 |
| JP0（靠近 USB 插座一側） | 5V | TFT LDO |
| JP0 | 3.3V | TFT LDO |
| JP3（靠近 USB 插座一側） | 5V | ESP32 LDO |
| JP3 | 3.3V | ESP32 LDO |
