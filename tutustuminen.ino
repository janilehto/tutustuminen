#define LED1 12

void setup() {
  //Määritetään pinni lähdöksi
  pinMode(LED1, OUTPUT);
  //Alustetaan sarjaportti
  Serial.begin(9600);
}

#define LEDON LOW
#define LEDOFF HIGH

void loop() {
  //Luetaan yksi merkki sarjaportista
  int x = Serial.read();
  //Tutkitaan oliko sarjaportissa mitään
  if(x != -1){
    //Tarkistetaan oliko sarjaporttiin saapunut 'S' kirjain
    if(x == 'S'){
      //Jos merkki on 'S' sytytetään ledi
      digitalWrite(LED1, LEDON);
    }else if(x == 'R'){
      //Ellei merkki ollut 'S' mutta on 'R' sammutetaan ledi
      digitalWrite(LED1, LEDOFF);
    }
  }
}
