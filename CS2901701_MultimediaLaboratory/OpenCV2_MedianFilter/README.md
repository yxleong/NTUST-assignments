# Median Filter
## Problem Statement
Implement median filter with [sort()](http://www.cplusplus.com/reference/algorithm/sort/) in algorithm library, no need to handling image edges.

## Source
![src](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV2_MedianFilter/src2.jpg)

## Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV2_MedianFilter/result2.png)

## Note
* 中值濾波器
    * 找遮罩的中位數，然後取代中間的值，當有數值差異大的值出現時效果通常會比平滑法好

        | *10*  | *10*  | *10*  | 10  |
        | --- |:---:|:---:| --- |
        | *10*  | *150* | *200* | 10  |
        | *10*  | *10*  |  *0*  | 10  |
        | 10  | 10  | 10  | 10  |
        
        ⬇
        
        | 10 | 10 | 10 | 10 |
        |----|----|----|----|
        | 10 | *10* | 10 | 10 |
        | 10 | 10 | 10 | 10 |
        | 10 | 10 | 10 | 10 |
        
## Additional Notes
* 高斯濾波器 (Gaussian Filter)
    * 功能
        * 濾除雜訊
        * 低通
        * 模糊化
    * ![](https://latex.codecogs.com/svg.latex?G%28x%29%20%3D%20%5Cfrac%7B1%7D%7B%5Csqrt%7B2%5Cpi%5Csigma%5E2%7D%7D%20e%5E%7B-%5Cfrac%7B%28x%20-%20%5Cmu%29%5E2%7D%7B2%5Csigma%5E2%7D%7D)
        * 𝜎 (sigma) 是標準差
        * 𝜇 (mean) 是平均值
    * 範例
        | (-1, -1) | (0, -1) | (1, -1) |
        |----------|---------|---------|
        | (-1, 0)  | (0, 0)  | (1, 0)  |
        | (-1, 1)  | (0, 1)  | (1, 1)  |

        將此矩陣的 x,y 值以及 𝜇 = 0, 𝜎 = 1 套入 Gaussian function 並正規化後即可得到 3*3 的 Gaussian filter

        | 0.045 | 0.122 | 0.045 |
        |-------|-------|-------|
        | 0.122 | 0.332 | 0.122 |
        | 0.045 | 0.122 | 0.045 |

* 二值化 (Binarization)
    * `threshold(src, dst, 127, 255, THRESH_BINARY);`
    * OTSU自動門檻值 `threshold(src, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);`
    * adaptiveThreshold
        * 每一個點的閥值，會根據周圍的點決定
            ```cpp
            void cv::adaptiveThreshold ( InputArray src,
                                         OutputArray dst,
                                         double maxValue,
                                         int adaptiveMethod,
                                         int thresholdType,
                                         int blockSize,
                                         double C 
                                        )	
            ```
            * src：輸入圖。
            * dst：輸出圖。
            * maxValue：最大值。
            * adaptiveMethod：方法
                * 有 ADAPTIVE_THRESH_MEAN_C 和ADAPTIVE_THRESH_GAUSSIAN_C
            * thresholdType：二值化型態
                * 有THRESH_BINARY 和 THRESH_BINARY_INV
            * blockSize：遮罩大小。
            * C：常數，計算閾值時，要從平均或加權平均減去的數。
