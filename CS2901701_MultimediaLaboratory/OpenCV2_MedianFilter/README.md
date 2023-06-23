# Smoothing Method
## Problem Statement
Implement smoothing method, no need to handle image edges.

## Source
![src](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV2_MedianFilter/src2.jpg)

## Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV2_MedianFilter/result2.png)

## Note
* 平滑法
    * 對於一個`3*3` 的 Filter size

        | 1/9 | 1/9 | 1/9 |
        |-----|-----|-----|
        | 1/9 | 1/9 | 1/9 |
        | 1/9 | 1/9 | 1/9 |
        
        * 如果是 `5*5` 的 Filter size，各個位置的權重就會變成 1/25

    * Filter 會掃過 image 範圍內每個位置
        
        | 10  | 10  | 10  | 10  |
        | --- |:---:|:---:| --- |
        | 10  | 150 | 200 | 10  |
        | 10  | 10  |  0  | 10  |
        | 10  | 10  | 10  | 10  |
       
    * 各個 `?` 就是對分別掃到的 Mask 範圍內取平均

        | 10  | 10  | 10  | 10  |
        | --- |:---:|:---:| --- |
        | 10  |  ?  |  ?  | 10  |
        | 10  |  ?  |  ?  | 10  |
        | 10  | 10  | 10  | 10  |

    * 範例
        | 10  | 10  | 10  |
        | --- |:---:|:---:|
        | 10  | 150 | 200 |
        | 10  | 10  |  0  |
        
        ×
        
        | 1/9 | 1/9 | 1/9 |
        |-----|-----|-----|
        | 1/9 | 1/9 | 1/9 |
        | 1/9 | 1/9 | 1/9 |
        
        ⬇
        
        (10+10+10+10+150+200+10+10+0)/9 = 45
        
        | 10  | 10  | 10  |
        | --- |:---:|:---:|
        | 10  | *45*  |  ?  |
        | 10  |  ?  |  ?  |

    * 周圍外框處理
        * 不管
        * 補0
        * 複製
