#include "HX711.h"

#define DOUT A1
#define CLK A0

HX711 balanza(DOUT, CLK);

void setup() {
  Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  balanza.set_scale(-153491); // Establecemos la escala
  balanza.tare(20);  //El peso actual es considerado Tara.
  
  Serial.println("Listo para pesar"); 
}

void loop() {
  if(Serial.available()>0){
    
    char dato = Serial.read();
    
    if(dato == 'p'){
      Serial.println(balanza.get_units(20),3);
    }
    
  }
}
