# Watermark Decode
## Problem Statement
Decipher the QR Code hidden in the LSB.
* [Reference](https://docs.opencv.org/3.4/d5/d98/tutorial_mat_operations.html) for the operation of channel data.

## Source
![](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV3_WatermarkDecode/src1.png)

## Output
![target](https://github.com/yxleong/NTUST-assignments/blob/main/CS2901701_MultimediaLaboratory/OpenCV3_WatermarkDecode/result1.png)

## Note
* 影像浮水印
    * LSB: least significant bit (最不重要的 bit)
    * MSB: most significant bit (最重要的 bit)
    * 示例
>         Pixel value **1010** 0100 = 164
>         + 
>         浮水印 1111 *1111* = 255
>         ⬇
>         影像浮水印 **1010** *1111* = 175
>           can simply isolate the rightmost bit `1` to extract the least significant bit (LSB) from the watermarked pixel value
