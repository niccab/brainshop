import processing.serial.*;  // import serial library
Serial myPort;  // Create object from Serial class

PImage webImg;




void setup() {
  size(670, 346);
  printArray(Serial.list());
  // remember to set your serial port...
  String portName = Serial.list()[3];
  myPort = new Serial(this, Serial.list()[3], 9600);

  String url = "https://static.makeuseof.com/wp-content/uploads/2017/09/iphone_x_landscape-670x346.jpg";
  // Load image from a web server
  webImg = loadImage(url, "png");
}

void draw() {
  background(0);
  delay(200);
  image(webImg, 0, 0);

  while (myPort.available() > 2) {
    int inByte0=myPort.read();
    int inByte1=myPort.read(); 
    int inByte2=myPort.read();

    float color1 = map(inByte0, 0, 100, 0, 255);
    float color2 = map(inByte1, 0, 100, 0, 255);
    float color3 = map(inByte2, 0, 100, 0, 255);

    textSize(18); 
    String happiness = "Happiness: " + inByte0 + "%";
    fill(0, 255, 0);
    text(happiness, 90, 140);
    fill(0, color1, 0);
    rect(135, 170, 50, 50);

    String anger = "Anger: " + inByte1 + "%";
    fill(255, 0, 0);
    text(anger, 280, 140 );
    fill(color2, 0, 0);
    rect(310, 170, 50, 50);

    String courage = "Courage: " + inByte2 + "%";
    fill(0, 0, 255);
    text(courage, 445, 140);
    fill(0, 0, color3);
    rect(480, 170, 50, 50);
  }
}