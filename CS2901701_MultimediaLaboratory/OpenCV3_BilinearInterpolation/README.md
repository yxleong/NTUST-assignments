# Bilinear Interpolation
## Problem Statement
Magnify image 2 times by implementing bilinear interpolation scaling.

## Source
![](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV3_BilinearInterpolation/src2.jpg)

## Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV3_BilinearInterpolation/result2.png)

## Note
* 雙線性插值法
    ```
    𝑓(𝑥1) = 𝑓(0,0) ∗ 𝑑2 + 𝑓(1,0) ∗ 𝑑1
    
    𝑓(𝑥2) = 𝑓(0,1) ∗ 𝑑2 + 𝑓(1,1) ∗ 𝑑1
    
    𝑓(𝑥,𝑦) = 𝑓(𝑥1) ∗ 𝑑4 + 𝑓(𝑥2) ∗ 𝑑3 
           = 𝑓(0,0) ∗ 𝑑2 ∗ 𝑑4 + 𝑓(1,0) ∗ 𝑑1 ∗ 𝑑4 + 𝑓(0,1) ∗ 𝑑2 ∗ 𝑑3 + 𝑓(1,1) ∗ 𝑑1 ∗ 𝑑3
    ```

## Additional Notes
* resize
    ```cpp
    void cv::resize ( InputArray src,
                      OutputArray dst,
                      Size dsize,
                      double fx = 0,
                      double fy = 0,
                      int interpolation = INTER_LINEAR 
                    )
    ```
    * src：輸入圖。
    * dst：輸出圖。
    * dsize : 輸出圖的尺寸，
    * 若為 Size(200,100)則寬為200高為100
    * 若為 Size()則dsize 會被指定為(round(fx*src.cols), round(fy*src.rows))
    * fx : 水平軸縮放倍率，若為 0 則會用 dsize 去計算
    * fy :垂直軸縮放倍率，若為 0 則會用 dsize 去計算
    * interpolation : 在做 resize 時要使用的內插法，有幾種 [flag](https://docs.opencv.org/4.x/da/d54/group__imgproc__transform.html#ga5bb5a1fea74ea38e1a5445ca803ff121) 可以使用

* 最近插值法 (Nearest Neighbor Interpolation)
    * 無條件捨去
    * 要用目標座標回推原圖座標
    * 範例：放大2.5倍
        * (0.2, 0.2) -> (1, 1)
        * (1, 0) -> (5, 0)
        * (0.6, 0.2) -> (3, 1)
