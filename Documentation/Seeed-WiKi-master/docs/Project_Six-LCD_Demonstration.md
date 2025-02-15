---
title: Project Six – LCD Demonstration
category: Tutorial
oldwikiname:  Project Six – LCD Demonstration
prodimagename:  
surveyurl: https://www.research.net/r/Project_Six-LCD_Demonstration
---
Now it is time to demonstrate the LCD module and matching Grove units. With the LCD you can display data or messages within the two line, eight-character display. For this example, connect the wires from the following LCD sockets to the Grove Base Shield:

*   right-bottom to D1/2;

*   bottom-left to D3/4;

*   bottom-right to D5/6;

![](https://github.com/SeeedDocument/Project_Six-LCD_Demonstration/raw/master/img/Conn-six.jpg)

_**Now upload the following Arduino sketch:**_

```
// Project Six - LCD demonstration
//

#include &lt;LiquidCrystal.h&gt;

LiquidCrystal lcd(1,2,3,4,5,6);

void setup()
{
  lcd.begin(8,2);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("01234567");
  lcd.setCursor(0,1);
  lcd.print("ABCDEFGH");
  delay(65000);
}
```

The lcd.clear() functions blanks the LCD screen; lcd.setCursor() moves the cursor to (column, row); and lcd.print(“”); writes text to the cursor position on the LCD.
