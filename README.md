EasyPR Non Opencv version
======

EasyPR是一个中文的开源车牌识别系统，其目标是成为一个简单、高效、准确的车牌识别引擎。

本項目基於EasyPR項目，完全用c重構代碼，使其脫離opencv的平臺限制，成爲跨平臺的程序。

### LOG

20150505：
重構PlateLocate部分，劃分結構層次。

### 平台

使用標準C編寫，原則上通用於任何標準C兼容的的平臺。

原版EasyPR除了windows平台以外，还有以下其他平台的EasyPR版本。一些平台的版本可能会暂时落后于主平台。

|版本 | 开发者 | 版本 | 地址 
|------|-------|-------|-------
| android |  goldriver  |  1.1  |  [linuxxx/EasyPR_Android](https://github.com/linuxxx/EasyPR_Android)
| linux | Micooz  |  1.2  |  已跟EasyPR整合
| ios | zhoushiwei |  1.1  |  [zhoushiwei/EasyPR-iOS](https://github.com/zhoushiwei/EasyPR-iOS)
| mac | zhoushiwei |  1.1  | [zhoushiwei/EasyPR](https://github.com/zhoushiwei/EasyPR)
| java | fan-wenjie |  1.2  | [fan-wenjie/EasyPR-Java](https://github.com/fan-wenjie/EasyPR-Java)

### 兼容性

使用標準C編寫，原則上通用於任何標準C兼容的的平臺，不再需要opencv的兼容。

### 安装

cmake ./
make

原版详细的开发与教程请见[介绍与开发教程](http://www.cnblogs.com/subconscious/p/3979988.html)。

### 使用

以下表格是本工程中所有目录的解释:

|目录 | 解释
|------|----------
| src |  所有源文件
| RECG | 测试用的图片

以下表格是src目录中子目录的解释:

|目录 | 解释
|------|----------
| core |  核心功能
| include | 相关头文件

### Contributer

* liuruoze：作者与核心代码编写

* Micooz：linux平台编译，性能优化，util类

* jsxyhelu：deface版本一

* zhoushiwei：deface版本二

* ahccom：新的plateLocate函数

* eastpiger：標準C重構，脫離opencv函數支持

### 鸣谢

taotao1233，唐大侠，jsxyhelu，如果有一天(zhoushiwei)，学习奋斗，袁承志，圣城小石匠，goldriver，Micooz，梦里时光，Rain Wang，任薛纪，ahccom





