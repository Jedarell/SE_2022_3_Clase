int num1, num2;

void setup() {
  // put your setup code here, to run once:    
  Serial.begin(9600);
  Serial.setTimeout(10); //ms  por defecto = 1000
}

int estado = 0;
int v;
void loop() { //16Mhz
  if(Serial.available()>0){//si hay informacion que leer
    v = Serial.readString().toInt();

    if(estado==0){
      num1 = v;
      estado = 1;
      }else if(estado==1){
        num2 = v;
        estado = 2;
        }
  }
  //////
  if(estado==2){
    Serial.println(num1+num2);
    estado= 0;
    }

  ////
}
