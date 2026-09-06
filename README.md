<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />



# Selfie Wiper


## Basic Details
### Team Name: Electrotops


### Team Members
- Member 1: Abirami Sankar - scms school of engineering and technology
- Member 2: Devika N S     - scms school of engineering and technology

### Project Description
A smart selfie-camera wiper that uses a servo-driven pendulum mechanism to gently sweep across the camera lens, removing water and dust for a clearer view.
With every button press, the wiper performs a controlled cleaning cycle while the OLED displays the achieved clarity level from 80% to 99%.

### The Problem (that doesn't exist)
A dirty or wet selfie camera can ruin the perfect selfie, forcing users to manually wipe the lens every time, our product can be a fun and creative alternative for that.

### The Solution (that nobody asked for)
Why use your finger or get your clothes dirty when your camera can have its own tiny windshield wiper?

## Technical Details
### Technologies/Components Used
- List main components
1. ESP32 Dev Board
2. SG90 Servo Motor
3. 0.96-inch OLED Display (SSD1306 I²C)
4. Push Button
5. Breadboard
6. Jumper Wires
7. 5V External Power Supply
8. microfiber Wiper Strip
9. arduino uno
- List specifications
1. The ESP32 acts as the main controller.
2. The push button activates the wiper.
3. The servo motor moves the wiper across the camera.
4. The OLED displays the current status and funny messages.
5. The servo returns to its original position after wiping.

- List tools required
 1. Arduino IDE – Programming and uploading code to ESP32
 2. Git – Version control and project management
 3. GitHub – Online repository for storing and sharing the project
 4. Breadboard – Prototyping the circuit
 5. Jumper Wires – Making circuit connections
 6. Soldering Iron – Permanent connections 
 7. Wire Cutter/Stripper – Preparing wires

### Implementation
 Circuit
![Circuit daigram]<img width="1137" height="638" alt="Untitled design (7)" src="https://github.com/user-attachments/assets/686cc7e4-5e05-419e-8b7f-0e7528f8267a" />
 1. first connect the esp32 on breadboard and connect pushbutton to gpio 4 and the other leg to gnd
 2. connect OLED motor (SCL=22,SDL=21),and connect vcc and gnd
 3. power servo via arduino(5V) and connect signal pin to gpio 18
 4. remember all gnd should be connect common.

# Build Photos
![Components Used]<img width="1536" height="1024" alt="ChatGPT Image Sep 6, 2026, 06_56_38 AM" src="https://github.com/user-attachments/assets/424d08f8-f924-470e-bb2a-c79e1721c80a" />

![build](build2.png)
![final build](build.png)
The project is essentially a ridiculously over-engineered manual selfie-camera windshield wiper: instead of simply wiping the lens, you press the button multiple times to tell the ESP32 how aggressively it should "clean" it, while the OLED proudly reports an increasingly impressive 80% → 99% clarity.
### Project Demo
## Video
[https://drive.google.com/drive/u/1/folders/1ndzFR-gETCY5620Y9F9OwOYA3qWYOJI-]


## Additional Demos
[https://drive.google.com/drive/u/1/folders/1ndzFR-gETCY5620Y9F9OwOYA3qWYOJI-]

## Team Contributions
- [Abirami Sankar]: [code,documentation,problem solving]
- [Devika N S]: [hardware connectios,problem solving]

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)



