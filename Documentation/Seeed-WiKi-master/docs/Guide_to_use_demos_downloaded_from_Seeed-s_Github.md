---
title: Guide to use demos downloaded from Seeed's Github
category: Tutorial
bzurl:  
oldwikiname: Guide to use demos downloaded from Seeed's Github
prodimagename:
surveyurl: https://www.research.net/r/Guide_to_use_demos_downloaded_from_Seeed-s_Github
sku:
---

It is necessary to use demos from Seeeduino Github frequently and there some slight difficult for a novice to run the demo well.
So we want to show you a scheduled procedure to run the demos quickly.

##   Get started

1.  You can download sample code and library or header files on [Seeed's Github](https://github.com/Seeed-Studio) sites.

2.  Click a button named "Download Zip" at Github.

3.  Decompress the downloaded ZIP file.

4.  Remove the "-master" twice in decompressed file name.

5.  Copy the folder decompressed file _xxx_ into your library folder (In default, it is same with Sketchbook Location which can be found by clicking File &gt; Preference).

6.  Under Windows, it will likely be called "My Documents\Arduino\libraries". For Mac users, it will likely be called "Documents/Arduino/libraries". On Linux, it will be the "libraries" folder in your sketchbook.

7.  Add ZIP library by the downloaded ZIP file(with "-master" removed first).

![](https://github.com/SeeedDocument/Guide_to_use_demos_downloaded_from_Seeed-s_Github/raw/master/img/Add_ZIP_library.png)

8. Open _**.ino**_ file in the sub directory _**example**_
9. Compile or Upload demos into your main controller board.
</dd></dl>

**Tips:** Always add compress a library file(header file in majority circumstances) with **zip** format if Arduino prompt that it can not find a _foo.h_ file.
