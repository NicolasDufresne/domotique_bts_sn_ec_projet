---
title: LinkIt Introduction
nointro:
---

---
The first product you need to know about the LinkIt family is LinkIt One, because it well defines what the LinkIt platform is doing. LinkIt One must be one of the most features-rich board in the planet. It includes ARM7 EJ-S™, GSM, GPRS, Wi-Fi, Bluetooth BR/EDR/BLE, GPS, Audio codec, and SD card connector on a single development board. Now you may understand why it is called LinkIt One. In addition to all these features it is also a board with rich-compatibility and strong extensibility, by using LinkIt ONE together with MediaTek LinkIt SDK (for Arduino) you will be able to easily turn your ideas into practical prototypes and make them a reality with the Seeed productization and agile manufacturing service.

After LinkIt ONE, we released LinkIt Smart 7688 and LinkIt Smart 7688 Duo, both are designed especially for the prototyping of Rich Application IoT devices for Smart-Home and offices. In order to make the prototyping even more convenient, you may find that we also released some breakouts for LinkIt Smart 7688 and LinkIt Smart 7688 Duo such as Arduino Breakout for LinkIt Smart 7688 Duo and Breakout for LinkIt Smart 7688 V2.0. More and more boards are joining in the LinkIt family, and you can find all the tutorial of how to get started with these boards in the New Seeed Wiki. Happy hacking!

## Product  List
--

Here is the list of the LinkIt Boards you can find in the Seeed WiKi. The list will be constantly updated.

{{ range .Data.Pages.ByTitle }}{{ $cat1 := trim (index (split .Params.category ",") 0) " "}}{{ $cat2 := trim (index (split .Params.category ",") 1) " "}}{{if or (eq $cat1 "LinkIt") (eq $cat2 "LinkIt") }}- [{{.Title}}](/{{.File.BaseFileName}}/){{"\n"}}{{ end }}{{ end }}
