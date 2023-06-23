# Histogram Equalization & Histogram Matching
## Problem Statement
1. Implement histogram equalization without calling library
    * Need to test an overexposed picture and a dark picture, save the converted result.
2. Implement histogram matching
    * Correspond the RGB histogram of transition image to the RGB histogram of target image, save the converted result.

## Overexposed
### Source
![overexposed](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/target/src1.jpg)
### Output
![overexposed](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/result1.png)

## Dark
### Source
![dark](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/target/src2.jpg)
### Output
![dark](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/result2.png)

## Transition
### Source
![transition](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/target/src3.jpg)
### Target
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/target/target.jpg)
### Output
![RGB](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV4_HistogramEqualization%26HistogramMatching/result3.png)

## Note
* 直方圖均值化
    * 假設圖片總共有𝑛個pixels，𝑛𝑖代表灰階值𝑖出現的次數
    * `𝑝𝑥(𝑖) = 𝑝(𝑥 = 𝑖) = 𝑛𝑖 / 𝑛` , 0 ≤ 𝑖 < 255
    * 累積分布函數 𝑐𝑑𝑓𝑥(𝑖) = ∑ `j = 0 to i` 𝑝𝑥(𝑗)
    * 原本pixel值為i，要轉換的pixel值為 `0 + 𝑐𝑑𝑓𝑥(𝑖) ∗ (255 − 0)`
    * 示例
        | Pixel value (𝒊) | Nums of this pixel in image (𝒏𝒊) | Probability (𝒑𝒙(𝒊)) | CDF (𝒄𝒅𝒇𝒙(𝒊)) | 𝒄𝒅𝒇𝒙(𝒊) = 0 + 𝒄𝒅𝒇𝒙(𝒊) ∗ (7 − 0) |
        |------------------|---------------------------------|-----------------------|------------------|------------------------------------|
        |        0         |             790                 |         0.19          |       0.19       |            1 (1.33)                |
        |        1         |             1023                |         0.25          |       0.44       |            3 (3.08)                |
        |        2         |             850                 |         0.21          |       0.65       |            5 (4.55)                |
        |        3         |             656                 |         0.16          |       0.81       |            6 (5.67)                |
        |        4         |             329                 |         0.08          |       0.89       |            6 (6.23)                |
        |        5         |             245                 |         0.06          |       0.95       |            7 (6.55)                |
        |        6         |             122                 |         0.03          |       0.98       |            7 (6.86)                |
        |        7         |             81                  |         0.02          |       1.00       |            7 (7.00)                |
        * 舉例為 value =[0, 7] 的圖像，實務上會是 [0, 255]
        * 會看到原本過度集中在 value = 1 的值被取代為更高的值(3)了

* 轉換指定直方圖
    * 算出原圖及目標圖片之累積分布函數𝑐𝑑𝑓1, 𝑐𝑑𝑓2
    * 建立原圖𝑐𝑑𝑓1與目標圖片𝑐𝑑𝑓2之對應表
        * 0.01 -> 0.01
        * 0.56 -> 0.57
        * ……
    * 建立 (𝑐𝑑𝑓2)-1 對應表
    * 原圖中其中一 pixel 值 x1，以𝑐𝑑𝑓1(x1)得累積機率值，在對應上述建立之對應表後得𝑐𝑑𝑓2(x2)之值，最後使用(𝑐𝑑𝑓2)-1得到轉換後數值。
