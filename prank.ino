#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const char* ssid = "Free_Public_WiFi";

DNSServer dnsServer;
WebServer server(80);

const byte DNS_PORT = 53;

// ===================== HTML =====================

String webpage = R"rawliteral(

<!DOCTYPE html>
<html>

<head>

<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>System Security Alert</title>

<style>

body{
    margin:0;
    padding:0;
    overflow:hidden;
    background:black;
    color:#00ff00;
    font-family:Consolas, monospace;
}

#matrix{
    position:fixed;
    top:0;
    left:0;
    width:100%;
    height:100%;
    z-index:-1;
}

.container{
    text-align:center;
    margin-top:70px;
}

h1{
    font-size:45px;
    color:red;
    text-shadow:0 0 20px red;
    animation: blink 0.8s infinite;
}

@keyframes blink{
    50%{
        opacity:0.3;
    }
}

.warning{
    margin-top:20px;
    font-size:22px;
    color:white;
}

.box{

    margin:auto;
    margin-top:40px;

    width:85%;
    max-width:600px;

    border:2px solid red;

    padding:20px;

    background:rgba(0,0,0,0.8);

    box-shadow:0 0 25px red;
}

.status{
    margin-top:15px;
    font-size:20px;
    color:lime;
}

.touch{
    margin-top:25px;
    font-size:18px;
    color:orange;
    animation:pulse 1s infinite;
}

@keyframes pulse{
    50%{
        transform:scale(1.08);
    }
}

.firework{
    position:absolute;
    width:6px;
    height:6px;
    border-radius:50%;
    animation: explode 1.5s linear forwards;
}

@keyframes explode{

    from{
        transform:scale(1);
        opacity:1;
    }

    to{
        transform:scale(35);
        opacity:0;
    }
}

.flash{
    position:fixed;
    top:0;
    left:0;
    width:100%;
    height:100%;
    background:red;
    opacity:0;
    pointer-events:none;
}

.log{

    text-align:left;

    margin-top:20px;

    background:black;

    padding:10px;

    height:150px;

    overflow:hidden;

    border:1px solid lime;
}

</style>

</head>

<body>

<canvas id="matrix"></canvas>

<div class="container">

<h1>⚠ SECURITY ALERT ⚠</h1>

<div class="warning">
Unknown Activity Detected On This Device
</div>

<div class="box">

<div class="status" id="status">
Scanning Device...
</div>

<div class="touch">
Touch Anywhere To Continue
</div>

<div class="log" id="log">
> Initializing Scan...<br>
</div>

</div>

</div>

<script>

// ================= MATRIX EFFECT =================

const canvas = document.getElementById("matrix");

const ctx = canvas.getContext("2d");

canvas.height = window.innerHeight;
canvas.width = window.innerWidth;

const letters =
"01ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const fontSize = 14;

const columns = canvas.width/fontSize;

const drops = [];

for(let x=0;x<columns;x++){
    drops[x]=1;
}

function drawMatrix(){

    ctx.fillStyle="rgba(0,0,0,0.05)";
    ctx.fillRect(0,0,canvas.width,canvas.height);

    ctx.fillStyle="#00ff00";
    ctx.font=fontSize+"px monospace";

    for(let i=0;i<drops.length;i++){

        const text =
        letters.charAt(
            Math.floor(Math.random()*letters.length)
        );

        ctx.fillText(text,i*fontSize,drops[i]*fontSize);

        if(
            drops[i]*fontSize>canvas.height &&
            Math.random()>0.975
        ){
            drops[i]=0;
        }

        drops[i]++;
    }
}

setInterval(drawMatrix,35);

// ================= BEEP =================

function longBeep(){

    let ctx =
    new(window.AudioContext ||
    window.webkitAudioContext)();

    function tone(freq,duration,delay){

        setTimeout(()=>{

            let osc = ctx.createOscillator();

            let gain = ctx.createGain();

            osc.type="sawtooth";

            osc.frequency.value=freq;

            osc.connect(gain);

            gain.connect(ctx.destination);

            gain.gain.setValueAtTime(
                0.4,
                ctx.currentTime
            );

            osc.start();

            osc.stop(ctx.currentTime+duration);

        },delay);
    }

    // LONG ALERT SOUND 😈

    tone(400,0.6,0);
    tone(700,0.6,600);
    tone(1000,0.7,1200);
    tone(500,0.5,1900);
    tone(1300,1.2,2400);
    tone(900,0.7,3600);
    tone(1500,1.4,4300);
}

// ================= FLASH =================

function flash(){

    const f=document.createElement("div");

    f.className="flash";

    f.style.opacity="0.8";

    document.body.appendChild(f);

    setTimeout(()=>{
        f.remove();
    },200);
}

// ================= FIREWORK =================

function createFirework(){

    const fw=document.createElement("div");

    fw.className="firework";

    fw.style.left=
    Math.random()*window.innerWidth+"px";

    fw.style.top=
    Math.random()*window.innerHeight+"px";

    fw.style.background=
    "hsl("+Math.random()*360+",100%,50%)";

    document.body.appendChild(fw);

    setTimeout(()=>{
        fw.remove();
    },1500);
}

// ================= FAKE LOGS =================

const logs=[

"> Accessing Device...",
"> Encrypting Connection...",
"> Unknown Network Activity...",
"> Firewall Bypass Failed...",
"> Diwali Mode Activated 😏",
"> Loading Fireworks...",
"> Unlimited Sweets Detected...",
"> Device Connected Successfully..."

];

function addLog(){

    let randomLog=
    logs[Math.floor(Math.random()*logs.length)];

    document.getElementById("log").innerHTML +=
    randomLog + "<br>";
}

// ================= MAIN =================

function triggerPrank(){

    longBeep();

    flash();

    createFirework();

    navigator.vibrate([
        300,100,300,100,700
    ]);

    document.getElementById("status").innerHTML =
    "⚠ SYSTEM OVERRIDE DETECTED ⚠";

    addLog();
}

// EVERY TOUCH 😈

document.body.addEventListener(
    "click",
    triggerPrank
);

document.body.addEventListener(
    "touchstart",
    triggerPrank
);

// AUTO EFFECTS

setInterval(createFirework,300);

setInterval(addLog,2000);

</script>

</body>
</html>

)rawliteral";

// ================= HANDLER =================

void handleRoot() {

    server.send(200, "text/html", webpage);
}

// ================= SETUP =================

void setup() {

    Serial.begin(115200);

    WiFi.softAP(ssid);

    IPAddress IP = WiFi.softAPIP();

    Serial.println();
    Serial.println("WiFi Started");
    Serial.print("IP Address: ");
    Serial.println(IP);

    dnsServer.start(DNS_PORT, "*", IP);

    server.on("/", handleRoot);

    // Captive portal routes
    server.on("/generate_204", handleRoot);
    server.on("/fwlink", handleRoot);
    server.on("/hotspot-detect.html", handleRoot);

    server.onNotFound(handleRoot);

    server.begin();

    Serial.println("Captive Portal Started");
}

// ================= LOOP =================

void loop() {

    dnsServer.processNextRequest();

    server.handleClient();
}