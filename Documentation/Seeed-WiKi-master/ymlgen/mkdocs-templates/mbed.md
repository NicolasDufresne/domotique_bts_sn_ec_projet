---
title: mbed Introduction
nointro:
---

---
What is mbed? mbed is a prototyping development platform that specially designed for ARM, it provides almost everything you need such as free SDK, HDK and web based IDE to develop IoT application. If you are a beginner at coding and hardware, mbed can definitely accelerate your learning and prototyping. If you are in the middle of hardware prototype design, and hard to decide which board to use, mbed is the one that can make your work easier.

There are already many open source platforms boards in the world, and every boards are claiming they are powerful and easy to use, What's the unique features that differentiate mbed from others. Firstly, mbed uses CMSIS(Cortex Microcontroller Software Interface Standard ) to standardize the difference of interface between different chip producers. Secondly, the web based IDE has simplified the compiling process, no matter what system you are using, you don't need to install an extra IDE, the only thing you need to do is open the web browser and start coding.

Seeed Studio is one of the members that producing mbed boards. Up to now, there are more than 10 mbed you can get from Seeed, such as Arch Max, Arch Link and Arch BLE. Most of them integrate the advantage of Arduino and mbed board, and we also add grove connectors to make them compatible with the family of grove sensors.


## Product  List
---

Here is the list of the mbed Boards you can find in the Seeed WiKi. The list will be constantly updated.

{{ range .Data.Pages.ByTitle }}{{ $cat1 := trim (index (split .Params.category ",") 0) " "}}{{ $cat2 := trim (index (split .Params.category ",") 1) " "}}{{if or (eq $cat1 "mbed") (eq $cat2 "mbed") }}- [{{.Title}}](/{{.File.BaseFileName}}/){{"\n"}}{{ end }}{{ end }}
