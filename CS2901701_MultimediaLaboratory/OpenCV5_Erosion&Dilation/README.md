# Erosion & Dilation
## Problem Statement
Calculate how many pieces there are by calling function.
* It is recommended to use blur method to remove noise first, or use dilation to remove noise
* Remember to use `THRESH_BINARY_INV` for binarization

## Source
![src](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV5_Erosion%26Dilation/src.jpg)

## Output
![result](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV5_Erosion%26Dilation/result.png)

## Note
* Morphology
    * [Erosion](https://www.youtube.com/watch?v=fmyE7DiaIYQ)
        * 用 Structure element 掃過， element 上任意部位與 Input AND, 若任一為 0 則消掉 element 中心處
    * [Dilation](https://www.youtube.com/watch?v=xO3ED27rMHs)
        * 用 Structure element 掃過，element 上任意部位與 Input OR, 若任一不為 0 則填滿 element 中心處
    * Opening
        * 先侵蝕再膨脹
        * 功用: 斷細邊/雜訊，可留下主要紋理
    * Closing
        * 先膨脹再侵蝕
        * 功用: 補洞
