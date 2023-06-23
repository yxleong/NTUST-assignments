# RGB to GRAY
## Problem Statement
Convert image from RGB to Gray using formula
`Gray = 0.299 * Red + 0.587 * Green + 0.114 * Blue`

## Source
![lenna.jpg](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV1_RGBtoGray/lenna.jpg)

## Output
![lenna_converted.png](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV1_RGBtoGray/lenna_converted.png)

## Note
* Mat 基本應用及介紹
    * Mat是OpenCV訂定的資料型態，代表的是矩陣(Matrix)
    * 每個通道的資料型態:
        * 8U: Unsigned 8 bits
        * 8S: Signed 8 bits
        * 16U: Unsigned 16 bits
        * 16S: Signed 16 bits
        * 32F: Float
        * 64F: Double
    * 最常使用的3通道RGB的型態就是**CV_8UC3**
* Color Image 介紹
    * (B, G, R) -> (0 ~ 255)
    * 讀取圖片
      ```cpp
      Mat cv::imread	( const String & filename,
                        int 	         flags = IMREAD_COLOR 
                      )
      ```
        * filename: 檔案名稱，檔案必須放在專案同個資料夾
        * flags: 支援的色彩通道格式
