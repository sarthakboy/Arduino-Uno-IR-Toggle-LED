# Arduino Uno IR Toggle LED

A simple Arduino Uno project that uses **two infrared (IR) sensors** to control an LED.

The first IR sensor turns the LED **ON**, while the second IR sensor turns the LED **OFF**. This demonstrates digital sensor input, conditional control, and basic hardware interfacing using Arduino.

## Project Overview

The system uses two IR sensors:

* **IR Start Sensor** → Turns the LED ON
* **IR Stop Sensor** → Turns the LED OFF
* **LED** → Indicates the current state

### Working

```text
IR START Sensor ──┐
                  │
                  ▼
              Arduino Uno
                  │
                  ▼
                LED
                  ▲
                  │
IR STOP Sensor ───┘
```

When the **START IR sensor detects an object**, the Arduino turns the LED ON.

When the **STOP IR sensor detects an object**, the Arduino turns the LED OFF.

## Hardware Used

* Arduino Uno
* 2 × IR Obstacle Sensors
* LED
* Resistor for LED
* Jumper wires
* Breadboard

## Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------- |
| IR Start Sensor | D2          |
| IR Stop Sensor  | D3          |
| LED             | D8          |

## How It Works

The IR sensors are configured as digital inputs.

```cpp
ir1State = digitalRead(IRSTART);
ir2State = digitalRead(IRSTOP);
```

The project assumes the IR sensors output **LOW when an object is detected**.

### START Detection

```cpp
if (!ir1State) {
    digitalWrite(LED, HIGH);
}
```

When the START sensor becomes LOW, the LED is switched ON.

### STOP Detection

```cpp
if (!ir2State) {
    digitalWrite(LED, LOW);
}
```

When the STOP sensor becomes LOW, the LED is switched OFF.

## Source Code

```cpp
#define IRSTART 2
#define IRSTOP 3
#define LED 8

int ir1State, ir2State;

void setup() {
    pinMode(IRSTART, INPUT);
    pinMode(IRSTOP, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    ir1State = digitalRead(IRSTART);
    ir2State = digitalRead(IRSTOP);

    if (!ir1State) {
        digitalWrite(LED, HIGH);
        delay(500);
    }

    if (!ir2State) {
        digitalWrite(LED, LOW);
        delay(500);
    }
}
```

## Key Concepts Demonstrated

* Arduino digital input/output
* IR sensor interfacing
* `digitalRead()`
* `digitalWrite()`
* Active-LOW sensor detection
* Conditional control using `if`
* Basic embedded control logic
* Interfacing multiple sensors with an MCU

## Video Demonstration

A video demonstration of the working project is available here:

**[▶ Watch Project Demonstration](https://drive.google.com/file/d/19ZtzZXosYd8pAUtroxPZlJHgCQi5744Y/view?usp=drive_link)**


## Author

**Sarthak Pandey**

Embedded Software / Firmware Engineer
C | STM32 | Arduino Uno | Bare-Metal Programming
