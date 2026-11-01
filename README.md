# ESP32 Cheap Yellow Display 繁體中文文件

> 這是 [`witnessmenow/ESP32-Cheap-Yellow-Display`](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display) 的非官方繁體中文（台灣）翻譯。
>
> 翻譯基準：[`dc3771e51ce27018ae62c658470ee8d6d7177567`](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/commit/dc3771e51ce27018ae62c658470ee8d6d7177567)，2026-08-08。若內容與英文原文不同，以英文原文為準。

目前已翻譯：

- [安裝與設定](SETUP.md)
- [腳位資訊](PINS.md)
- [疑難排解](TROUBLESHOOTING.md)
- [CYD 與 CYD2USB 的差異](cyd.md)
- [基礎範例 1～3](Examples/Basics/)

## 什麼是 Cheap Yellow Display？

市面上有一款內建 320 × 240、2.8 吋觸控螢幕的 ESP32 開發板，型號是 `ESP32-2432S028R`。這個名稱不太好記，因此原作者建議把它叫做 Cheap Yellow Display，簡稱 CYD。

這塊板子的到手價大約 15 美元，硬體整合度高，是很划算的入門選擇。

![CYD](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/assets/1562562/76c3d481-2523-4b6f-881c-2e29f9368cd0)

## 特色

- ESP32，支援 Wi-Fi 與 Bluetooth
- 320 × 240、2.8 吋 LCD
- 電阻式觸控螢幕
- 可透過 USB 供電與燒錄
- microSD 卡槽、RGB LED，以及額外引出的腳位

## 適合哪些人？

- **剛開始接觸硬體的人**：大部分元件已經接好，不必先焊接或準備額外零件。
- **熟悉硬體，但想快速完成作品的人**：有時只想專心做專案，不想先組裝一堆模組。
- **只想做出有趣作品的人**：即使不打算深入研究每個硬體細節，也能直接使用現成範例開始製作。

## 這個專案的目的

CYD 的硬體價格低、功能完整，但原始軟體說明與支援相對不足，常見資料只是某個網站上的壓縮檔連結。

原作者 Brian Lough 過去曾推出開源的 [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity)。該專案真正帶給社群的價值，不只在硬體，也包括文件、範例程式與可直接使用的作品。

CYD 專案希望為這塊顯示板建立類似的社群，讓大家分享範例與實作作品。

## 如何確認手上的板子是 CYD？

請參考以下判斷圖，以及 [CYD 與相似板型說明](cyd.md)。

![CYD 判斷圖](http://www.plantuml.com/plantuml/png/RP0nJyCm48Nt_8gZNIb3fge3LD2b2q92235UamDRE7PaNuhyxxda7DGgJBs-zxtSE-yJO-IXSzKD6-e8UeVMLyQs1DJrdA6br4JRims-4fW9LiS4bY6JS-47qBTWC052QvEayyCAvA-wS-8vi01F7mS8SVevOxJeUK9zu55QzzP_Nw-exxPmz8tHJzRRsJq4cdo3Pu98oIQsCd4O6WDIbyXF4LN-JNMsYG7UNXyXUAUTLHDfqVeMJWClUfSPrY_OOyPtO_ivUPcfnoMV3iyXJh4cj_MGJd8lEleQkvQKi9TYUT_DvbukXnraIfTQURMT39Nu8kcrXInIwQYO-gCyNwgm6al-ZneTNIRqjLokqS2UV3jqxXS0)

## 購買管道

> **繁中版補充：** 台灣在地購買管道整理中，確認商品規格與供貨情況後將陸續補充。

請依所在地選擇價格合適的賣場：

- [AliExpress＊](https://s.click.aliexpress.com/e/_c4qCIGnp)
- [AliExpress（請確認購買 2.8 吋版本）＊](https://s.click.aliexpress.com/e/_c36bmiWr)
- [AliExpress](https://www.aliexpress.com/item/1005009795213070.html)
- [Makerfabs](https://www.makerfabs.com/sunton-esp32-2-8-inch-tft-with-touch.html)－似乎附 16 GB microSD 卡，也販售原作者的 [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity)。歐盟地區可能需支付進口稅費。

＊代表聯盟行銷連結（affiliate link），依英文原文保留。

## 開始使用

請先閱讀[安裝與設定](SETUP.md)。

## 程式範例

### 基礎範例

這些範例示範 CYD 各項硬體功能，是最適合開始練習的地方。目前繁中版提供[範例 1～3](Examples/Basics/)；其餘範例請參考[英文原始版本](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/Examples/Basics)。

### 其他顯示函式庫

基礎範例使用 TFT_eSPI；CYD 也能搭配其他 Arduino 顯示函式庫。請參考[英文原始版本](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/Examples/AlternativeLibraries)。

### ESPHome

ESPHome 範例請參考[英文原始版本](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/Examples/ESPHome)。

## 其他資訊

- [Discord 討論區](https://discord.gg/nnezpvq)
- [腳位資訊](PINS.md)
- [疑難排解](TROUBLESHOOTING.md)
- [3D 列印、擴充模組、硬體改裝、作品與媒體資料（英文）](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display)

## 翻譯與授權

本翻譯保留原作者、原始連結、聯盟行銷標示與 MIT License。歡迎依 [CONTRIBUTING.md](CONTRIBUTING.md) 回報翻譯問題。

原專案採 MIT License；`OriginalDocumentation/` 例外，不包含在本翻譯 repo 中。詳見 [LICENSE](LICENSE) 與 [UPSTREAM.md](UPSTREAM.md)。

## 支持原作者

如果這些資料對你有幫助，可考慮[贊助 Brian Lough](https://github.com/sponsors/witnessmenow/)。
