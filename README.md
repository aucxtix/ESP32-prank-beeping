
# ESP32-prank-beeping


# ESP32 Captive Portal Prank 😈

A fun ESP32 captive portal project that creates a fake public WiFi network and opens a hacker-style prank webpage with:

- Matrix rain effect
- Fake security alerts
- Long warning beeps
- Vibrations
- Flash effects
- Fireworks animations
- Captive portal auto redirect

Built using:
- ESP32
- Arduino IDE
- HTML/CSS/JavaScript
- DNSServer
- WebServer

--- 

# Features

✅ Fake Public WiFi  
✅ Auto Redirect Captive Portal  
✅ Matrix Hacker Animation  
✅ Touch Triggered Alert Sound  
✅ Flash Effects  
✅ Vibrations  
✅ Fake System Logs  
✅ Fireworks Animation  
✅ Offline Working  
✅ Mobile Friendly  

---

# WiFi Name

```txt
Free_Public_WiFi
```

---

# Default IP

```txt
192.168.4.1
```

If the captive portal does not open automatically, manually open:

```txt
http://192.168.4.1
```

---

# Required Components

- ESP32
- USB Cable
- Arduino IDE

Optional:
- OLED Display
- LCD Display 
- Buzzer
- LEDs

---

# Required Libraries

Install these libraries in Arduino IDE:

- WiFi.h
- WebServer.h
- DNSServer.h

ESP32 Board Package:
- ESP32 by Espressif Systems

---

# Arduino IDE Setup

## Add ESP32 Board URL

Go to:

```txt
File → Preferences
```

Paste:

```txt
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

---

## Install ESP32 Board

Go to:

```txt
Tools → Board → Boards Manager
```

Search:

```txt
esp32
```

Install:

```txt
ESP32 by Espressif Systems
```

---

# Upload Steps

1. Connect ESP32 via USB
2. Select:
   ```txt
   ESP32 Dev Module
   ```
3. Select COM Port
4. Upload code
5. Open Serial Monitor
6. Connect phone to WiFi

---

# Captive Portal Routes

The project redirects common captive portal detection URLs:

- /generate_204
- /fwlink
- /hotspot-detect.html

---

# Manual Access (Important)

Some phones may NOT automatically open the captive portal page because modern Android/iPhone browsers sometimes block or ignore captive portal detection.

If the webpage does not open automatically:

## Step 1
Connect to WiFi:

```txt
Free_Public_WiFi
```

---

## Step 2
Open any browser manually.

Examples:
- Chrome
- Firefox
- Edge
- Safari

---

## Step 3
Type this IP address manually:

```txt
http://192.168.4.1
```

---

# If Still Not Opening

Try these fixes:

- Turn OFF mobile data
- Reconnect to WiFi
- Open browser manually
- Refresh the page
- Try another browser

---

# Audio Not Working?

Modern browsers block autoplay audio for security reasons.

Solution:
- Tap anywhere on the screen once
- Sound effects will start automatically after interaction

---

# Common Issues

| Problem | Solution |
|---|---|
| WiFi not visible | Restart ESP32 |
| Portal not opening | Open `192.168.4.1` manually |
| No sound | Tap on screen |
| Upload failed | Hold BOOT button while uploading |
| Page loading issue | Disable mobile data |

---

# Serial Monitor Output

Expected output:

```txt
WiFi Started
IP Address: 192.168.4.1
Captive Portal Started
```

---

# Project Structure

```txt
ESP32-Captive-Portal/
│
├── ESP32_Captive_Portal.ino
├── README.md
└── .gitignore
```

---

# Future Improvements

- OLED animations
- Local MP3 using LittleFS
- RGB LED sync
- WebSocket live effects
- OTA updates
- OLED hacker face
- LCD status panel
- Real-time animations

---

# Warning

This project is intended ONLY for:
- fun
- learning
- educational demonstrations

Do NOT use it for:
- phishing
- impersonation
- illegal activity
- causing panic

---

# License

MIT License

---

# Author

Made with ESP32 + chaos 😏
@aucxtix