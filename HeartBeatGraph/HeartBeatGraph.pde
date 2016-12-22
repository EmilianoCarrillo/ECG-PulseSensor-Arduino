import processing.serial.*;

Serial myPort;        // Serial port
int xPos = 0;         // Posición horizontal de la gráfica
float inByte = 0;

void setup () {
  // Tamaño de la ventana:
  size(400, 300);
  surface.setResizable(true);
  //fullScreen();

  // Enlista los posibles puertos al inicio
  println(Serial.list());

  // En qué puerto está conectado el Arduino ? [1]
  myPort = new Serial(this, Serial.list()[2], 115200);

  // No generar un serialEvent() (Inicio del programa)
  //    Hasta no obtener un salto de carro
  myPort.bufferUntil('\n');

  // Fondo inicial:
  background(#FFFFFF);
  
 }

void draw () {
  // Dibujar la línea (Estilo y posición)
  stroke(255, 0, 0);
  line(xPos, height , xPos, height - inByte); //(x1,y1,x2,y2)

  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    background(#FFFFFF);
  } else {
    // increment the horizontal position:
    xPos++;
  }
}


void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    inByte = float(inString);
    println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);
  }
}