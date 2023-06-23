# Edge Detection
## Problem Statement
Implement edge detection of Sobel.
* Threshold = 180

## Lenna
### Source
![src](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV6_EdgeDetection/lenna.jpg)
### Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV6_EdgeDetection/lennaResult.png)

## Pikachu
### Source
![src](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV6_EdgeDetection/pikachu.png)
### Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV6_EdgeDetection/pikachuResult.png)

## Note
* 邊緣偵測
    * 目的是要找出灰階有劇烈變化的邊界
    * Sobel
        * `G = √(Gx^2 + Gy^2) ≅ |Gx| + |Gy|`
            * G >= threshold 設成白點
            * G < threshold 設成黑點
        * 這種 image 經過 S𝑥 會在中心產生很大的數值
            | white | grey | black |
            |-------|------|-------|
            | white | grey | black |
            | white | grey | black |
            * S𝑥
                | -1 | 0 | 1 |
                |----|---|---|
                | -2 | 0 | 2 |
                | -1 | 0 | 1 |
            * G𝑥
                | |              | |
                |-|--------------|-|
                | | (-1)*255+1*0 | |
                | | (-2)*255+2*0 | |
                | | (-1)*255+1*0 | |
                | |              | |
        * 這種 image 經過 S𝑦會在中心產生很大的數值
            | white | white | white |
            |:-----:|:-----:|:-----:|
            | grey  | grey  | grey  |
            | black | black | black |
            * Sy
                | -1  | -2  | -1  |
                |:---:|:---:|:---:|
                |  0  |  0  |  0  |
                |  1  |  2  |  1  |
            * Gy
                | |              | |
                |-|--------------|-|
                | | (-1)*0+1*255 | |
                | | (-2)*0+2*255 | |
                | | (-1)*0+1*255 | |
                | |              | |
* Canny edge detection
    * Steps of canny
        1. To gray 轉為單通道
        2. Blur 消除雜訊
        3. Erode/Dilate 看情況，可有可無，主要也是為了消除雜訊
        4. Calculate Gradient
            * 對圖片利用微分 (Sobel) 放大那個 Block 內的邊界出來
            * 某一圈的數值比較大, 即是數值 G, 就是 X 方向以及 Y 方向的 Sobel Result 算出來的
        5. Non-Max Suppression
            * 篩選掉比較小的數值，主要是使用前面 Gx, Gy 去計算角度(可以想成邊的角度)，之後看根據不同 case 判斷它是不是那附近最大的 gradient value
        6. Canny result = Strong + Connect to Strong
            * Upper: strong edge
            * Lower: weak edge
