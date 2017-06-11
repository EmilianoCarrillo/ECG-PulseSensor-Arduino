# (ECG) Pulse sensor - Arduino Project

![myECG](https://github.com/emiliano-carrillo/ECG-PulseSensor-Arduino/blob/master/README%20photos/Captura%20de%20pantalla%202016-12-22%20a%20la(s)%2013.59.13.png)
---
[You can click here to check some more videos and photos about the project.](https://drive.google.com/file/d/0B7gTH-maKTLiVDBhSjJ2X2hRYkU/view?usp=sharing)

## WHAT IS IT?
The heart rate monitor I built is a cheap and simple instrument, you can use it in many ways and it has lots of functions such as:
- Heartbeat sensor (You may change it's sensitivity with a fisical knob).
- Heartbeat indicators: Sound and LEDs that blink whenever a pulse in the heart occurs.
-Monitor showing your heart rate in real time.
-Electrocardiogram. When you connect it to the computer, you can see a graph of the heart beats.

## HOW DOES IT WORK?

![inside](https://github.com/emiliano-carrillo/ECG-PulseSensor-Arduino/blob/master/README%20photos/Captura%20de%20pantalla%202016-12-22%20a%20la(s)%2013.59.44.png)

- Emitter: It is a powerful red LED. The color red is chosen because of blood color, it mostly absorbs colors of 700-750 nm (reddish colors).
- Amplifier: It amplifies the pulses and makes them so much clearer to be able to interpret them by the arduino. Two OpAmp are used, the second one is called Buffer because it stabilizes the signal a little more.
- Collector: A Photoresistor that captures the amount of red light that reaches itself. The patient's finger is between the sender and the collector, the LDR captures the difference of light when the blood passes trough the arteries (when the blood flows because of a pulse, it absorbs light and therefore gives less light to the LDR, when the heart is in diastole there is not so much blood pressure so it picks up more light).

## THE CIRCUIT USED:

![Circuit](https://github.com/emiliano-carrillo/ECG-PulseSensor-Arduino/blob/master/README%20photos/Captura%20de%20pantalla%202016-12-22%20a%20la(s)%2013.59.54.png)

## HOW DOES THE ARDUINO INTERPRETS THIS VALUES?
![ECG](https://github.com/emiliano-carrillo/ECG-PulseSensor-Arduino/blob/master/README%20photos/Captura%20de%20pantalla%202016-12-22%20a%20la(s)%2014.00.25.png)

The arduino reads these values through a digital input (Pin A0) and does different things:
- It tells the graph that both increase or decrease to form their crests and valleys of the heart rate. This is based on continuous vertical lines that go from the bottom of the screen to a variable height that would be the amount of light that reaches the LDR with each pulsation.
- It turns two LEDs, the first indicating the first part of the pulse (when the blood goes from the atria to the corresponding ventricular) and the second blinks when the blood passes from the ventricles to the arteries and veins.
- It calculates the beats or pulsations per minute in a quick and simple way. The program doesnt wait a full minute to get your results, but make a collection of your last ten beats and compare the time interval between each to average how many of these would occur during a
 minute and sends them to the LCD screen.
 
## MATERIALS

- [] 220Ω
- [] 39KΩ
- [] 68KΩ - 2
- [] 8.2KΩ
- [] 470KΩ - 2
- [] 1.8KΩ
- [] 1KΩ - 2
- [] 10kΩ
- [] 1μF polar - 2
- [] 0.1μF ceramic - 2
- [] 100nF ceramic - 2
- [] 47μF polar
- [] LM324 or LM358 CI
- [] 2n3904 Transistor
- [] TIP120
- [] Red LED
- Photoresistance

**Built and programmed by Emiliano Carrilo Moncayo. 2016.**
