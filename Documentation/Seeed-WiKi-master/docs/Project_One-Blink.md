---
title: Project One - Blink
category: Tutorial
oldwikiname:  Project One - Blink
prodimagename:
surveyurl: https://www.research.net/r/Project_One-Blink
---

The purpose of this project is to demonstrate a simple digital-out display using the LED twig. Connect your equipment as shown in the image below:
Connect the LED Twig to the D1/D2 Digital I/O jack on the Grove Shield.
Arduino Pin D1 powers the Green LED on the Twig's SIG connector.

![](https://github.com/SeeedDocument/Project_One-Blink/raw/master/img/Blinkv1.0.jpg)

_**Now upload the following Arduino sketch:**_

```
// Project One - Double Blink
//

int del=500; // adjust for blink rate

void setup()
{
  pinMode(1, OUTPUT);
}

void loop()
{
  digitalWrite(1, HIGH);

  delay(del);
  digitalWrite(1, LOW);

  delay(del);
}
```
te simple. The LED alternately blink, with the delay between the two set by the variable del. However, in doing so you can experience for yourself how simple the Grove system is to use.
