---
title: Grove - 3 Axis Digital Accelerometer(±16g)
category: Sensor
bzurl: <a href="https://www.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer(%C2%B116g)-p-1156.html">https://www.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer(%C2%B116g)-p-1156.html</a>
oldwikiname: Grove - 3 Axis Digital Accelerometer(±16g)
prodimagename: Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/Grove-3-Axis_16g_v1.3.jpg
surveyurl: https://www.research.net/r/Grove_3_Axis_Digital_Accelerometer_plus_and_Minus_16_g
sku: 101020054
---

---
![](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/Grove-3-Axis_16g_v1.3.jpg)


这是一种高精度数字加速度计，可提供最高 3.9mg / LSB 分辨率和高达±16g测量范围。 它基于先进的 3 轴 IC ADXL345。您无需担心自由落体实验对该模块造成损坏，它可以承受至多 10000g 的振动。此外，它可以灵敏地检查到相关信号，因而可以用于运动检测、手势检测和机器人学。


[![](https://github.com/SeeedDocument/wiki_chinese/raw/master/docs/images/click_to_buy.PNG)](https://item.taobao.com/item.htm?spm=a1z10.3-c.w4002-11172317909.13.5bd1190VbULj1&id=45505202190)


## 规格参数
---
- 输入电压: 3.3V, 5V
- 测试范围: ±16
- 高灵敏度
- 大测量范围
- 低功耗电源0.1 μA（在标准模式下VS = 2.5 V (典型值)）
- 能承受 10,000 g 振动
- 符合 RoHS/WEEE 无铅标准
- Suli标准兼容库

!!!Tip
    - More details about Grove modules please refer to [Grove System](http://seeed.wiki/Grove_System/)

## 操作示例
---
**使用 Arduino**

Every accelerometer has been individually tested before shipping to you. But in rare cases, you might need to reset the zero-offset by yourself.
Here below we show you how to read the raw data and obtain data in the unit of g, AKA g-force, from this accelerometer.

![](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/Grove_-_3-Axis_Digital_Accelerometer_ADXL345_connect_photo.JPG)

- **Step1:** Plug it onto the I2C port of your Grove - Base Shield.
- **Step2:** Download the [Digital Accelerometer(±16g) Library](https://github.com/Seeed-Studio/Accelerometer_ADXL345) .zip and unpack it into arduino-1.0\libraries in your Arduino installation folder. If you don't know how to install library for Arduino, please follow the toturial [How to install an Arduino library](/Tutorial/How_to_Install_an_Arduino_Library/)
- **Step3：** If you  have the library installed, Open the demo code directly by the path:
** File(文件) -> Example(示例) ->DigitalAccelerometer_ADXL345->ADXL345_demo_code. **
- **Step4：** Upload the code and open the serial monitor(usually it is on the right up corner). Please refer to the toturial [Upload code](http://wiki.seeedstudio.com/wiki/Upload_Code) if you do not know how to upload.
- **Step5：** The result will be showed as the format in below image, shake the grove and you will find the number changing.

![](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/Digital_Accelerometer.jpg)

The outputs of this sensor consist of two parts: raw data and 3-axis acceleration info converted into the unit of gravity, "g".

**With Raspberry Pi**

- **Step1:** You should have got a raspberry pi and a grovepi or grovepi+.

- **Step2:** You should have completed configuring the development enviroment, otherwise follow [here](http://wiki.seeedstudio.com/wiki/GrovePi+#Introducing_the_GrovePi.2B).

![](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/C9-create-tab.png)

![](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/images/C9_newfile.jpg)

- **Step3:** Connection
   - Plug the sensor to grovepi socket i2c-x(1~3) by using a grove cable.

- **Step4:** Navigate to the demos' directory:

```python
cd yourpath/GrovePi/Software/Python/
```
To see the code

```
  nano grovepi_tilt_switch.py   # "Ctrl+x" to exit #
```

```python
import smbus
from time import sleep

# select the correct i2c bus for this revision of Raspberry Pi
revision = ([l[12:-1] for l in open('/proc/cpuinfo','r').readlines() if l[:8]=="Revision"]+['0000'])[0]
bus = smbus.SMBus(1 if int(revision, 16) >= 4 else 0)

# ADXL345 constants
EARTH_GRAVITY_MS2   = 9.80665
SCALE_MULTIPLIER    = 0.004

DATA_FORMAT         = 0x31
BW_RATE             = 0x2C
POWER_CTL           = 0x2D

BW_RATE_1600HZ      = 0x0F
BW_RATE_800HZ       = 0x0E
BW_RATE_400HZ       = 0x0D
BW_RATE_200HZ       = 0x0C
BW_RATE_100HZ       = 0x0B
BW_RATE_50HZ        = 0x0A
BW_RATE_25HZ        = 0x09

RANGE_2G            = 0x00
RANGE_4G            = 0x01
RANGE_8G            = 0x02
RANGE_16G           = 0x03

MEASURE             = 0x08
AXES_DATA           = 0x32

class ADXL345:

    address = None

    def __init__(self, address = 0x53):
        self.address = address
        self.setBandwidthRate(BW_RATE_100HZ)
        self.setRange(RANGE_2G)
        self.enableMeasurement()

    def enableMeasurement(self):
        bus.write_byte_data(self.address, POWER_CTL, MEASURE)

    def setBandwidthRate(self, rate_flag):
        bus.write_byte_data(self.address, BW_RATE, rate_flag)

    # set the measurement range for 10-bit readings
    def setRange(self, range_flag):
        value = bus.read_byte_data(self.address, DATA_FORMAT)

        value &= ~0x0F;
        value |= range_flag;
        value |= 0x08;

        bus.write_byte_data(self.address, DATA_FORMAT, value)

    # returns the current reading from the sensor for each axis
    #
    # parameter gforce:
    #    False (default): result is returned in m/s^2
    #    True           : result is returned in gs
    def getAxes(self, gforce = False):
        bytes = bus.read_i2c_block_data(self.address, AXES_DATA, 6)

        x = bytes[0] | (bytes[1] << 8)
        if(x & (1 << 16 - 1)):
            x = x - (1<<16)

        y = bytes[2] | (bytes[3] << 8)
        if(y & (1 << 16 - 1)):
            y = y - (1<<16)

        z = bytes[4] | (bytes[5] << 8)
        if(z & (1 << 16 - 1)):
            z = z - (1<<16)

        x = x * SCALE_MULTIPLIER
        y = y * SCALE_MULTIPLIER
        z = z * SCALE_MULTIPLIER

        if gforce == False:
            x = x * EARTH_GRAVITY_MS2
            y = y * EARTH_GRAVITY_MS2
            z = z * EARTH_GRAVITY_MS2

        x = round(x, 4)
        y = round(y, 4)
        z = round(z, 4)

        return {"x": x, "y": y, "z": z}

if __name__ == "__main__":
    # if run directly we'll just create an instance of the class and output
    # the current readings
    adxl345 = ADXL345()

    axes = adxl345.getAxes(True)
    print "ADXL345 on address 0x%x:" % (adxl345.address)
    print "   x = %.3fG" % ( axes['x'] )
    print "   y = %.3fG" % ( axes['y'] )
    print "   z = %.3fG" % ( axes['z'] )
```

5.Run the demo.

```
    sudo python grove_tilt_switch.py
```

**With Beaglebone Green**

To begin editing programs that live on BBG, you can use the Cloud9 IDE.
As a simple exercise to become familiar with Cloud9 IDE, creating a simple application to blink one of the 4 user programmable LEDs on the BeagleBone is a good start.

If this is your first time to use Cloud9 IDE, please follow this link.

- Step1: Set the Grove - UART socket as a Grove - GPIO Socket, just follow this link.

- Step2: Click the "+" in the top-right to create a new file.

- Step3: Copy and paste the following code into the new tab.

```python
import smbus
import time

bus = smbus.SMBus(1)

# ADXL345 device address
ADXL345_DEVICE = 0x53

# ADXL345 constants
EARTH_GRAVITY_MS2   = 9.80665
SCALE_MULTIPLIER    = 0.004

DATA_FORMAT         = 0x31
BW_RATE             = 0x2C
POWER_CTL           = 0x2D

BW_RATE_1600HZ      = 0x0F
BW_RATE_800HZ       = 0x0E
BW_RATE_400HZ       = 0x0D
BW_RATE_200HZ       = 0x0C
BW_RATE_100HZ       = 0x0B
BW_RATE_50HZ        = 0x0A
BW_RATE_25HZ        = 0x09

RANGE_2G            = 0x00
RANGE_4G            = 0x01
RANGE_8G            = 0x02
RANGE_16G           = 0x03

MEASURE             = 0x08
AXES_DATA           = 0x32

class ADXL345:

    address = None

    def __init__(self, address = ADXL345_DEVICE):
        self.address = address
        self.setBandwidthRate(BW_RATE_100HZ)
        self.setRange(RANGE_2G)
        self.enableMeasurement()

    def enableMeasurement(self):
        bus.write_byte_data(self.address, POWER_CTL, MEASURE)

    def setBandwidthRate(self, rate_flag):
        bus.write_byte_data(self.address, BW_RATE, rate_flag)

    # set the measurement range for 10-bit readings
    def setRange(self, range_flag):
        value = bus.read_byte_data(self.address, DATA_FORMAT)

        value &= ~0x0F;
        value |= range_flag;
        value |= 0x08;

        bus.write_byte_data(self.address, DATA_FORMAT, value)

    # returns the current reading from the sensor for each axis
    #
    # parameter gforce:
    #    False (default): result is returned in m/s^2
    #    True           : result is returned in gs
    def getAxes(self, gforce = False):
        bytes = bus.read_i2c_block_data(self.address, AXES_DATA, 6)

        x = bytes[0] | (bytes[1] << 8)
        if(x & (1 << 16 - 1)):
            x = x - (1<<16)

        y = bytes[2] | (bytes[3] << 8)
        if(y & (1 << 16 - 1)):
            y = y - (1<<16)

        z = bytes[4] | (bytes[5] << 8)
        if(z & (1 << 16 - 1)):
            z = z - (1<<16)

        x = x * SCALE_MULTIPLIER
        y = y * SCALE_MULTIPLIER
        z = z * SCALE_MULTIPLIER

        if gforce == False:
            x = x * EARTH_GRAVITY_MS2
            y = y * EARTH_GRAVITY_MS2
            z = z * EARTH_GRAVITY_MS2

        x = round(x, 4)
        y = round(y, 4)
        z = round(z, 4)

        return {"x": x, "y": y, "z": z}

if __name__ == "__main__":
    # if run directly we'll just create an instance of the class and output
    # the current readings
    adxl345 = ADXL345()

    while True:
        axes = adxl345.getAxes(True)
        print "ADXL345 on address 0x%x:" % (adxl345.address)
        print "   x = %.3fG" % ( axes['x'] )
        print "   y = %.3fG" % ( axes['y'] )
        print "   z = %.3fG" % ( axes['z'] )
        time.sleep(2)
```

- Step4: Save the file by clicking the disk icon with with the .py extension..

- Step5: Connect Grove - 3-Axis Digital Accelerometer(±16g) to Grove I2C socket on BBG.

- Step6: Run the code. You'll sfind that the terminal outputs Gravity info every 2 seconds.

## Resources
---
- **[原理图]** [Eagle file.zip](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/resources/202000067_PCBA-Grove%203%20Axis%20Digital%20Accelerometer%C2%B116g%20v1.2.zip)
- **[库文件]**[Suli-compatible Library](https://github.com/Seeed-Studio/ACC_Adxl345_Suli)
- **[数据手册]**[ADXL345 datasheet.pdf](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/res/ADXL345_datasheet.pdf)
- **[其他资源]**[github repository for 3-Axis Digital Accelerometer(±16g)](https://github.com/Seeed-Studio/Accelerometer_ADXL345)
- **[其他资源]**[Grove - 3-Axis Digital Accelerometer(±16g)](https://github.com/SeeedDocument/Grove_3_Axis_Digital_Accelerometer_Plus_Minus_16g/raw/master/resources/DigitalAccelerometer_ADXL345.zip)
