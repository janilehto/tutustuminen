#define LED1 12
#define S1 5
#define S2 4

#define BUTTONPRESSED LOW
#define LEDON LOW
#define LEDOFF HIGH

//Luodaan globaali muuttuja ylläpitämään tietoa ledin tilasta
int led1State=LEDOFF;
//Luodaan globaali muuttuja painikkeen "vanhaa" tilaa varten
int S1OldState, S2OldState;

void setup() {
  //Määritetään ledin liitos
  pinMode(LED1, OUTPUT);
  //Ohjataan ledi tilamuuttujan mukaiseen tilaan
  digitalWrite(LED1, led1State);
  //Määritetään painikkeen liitos
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);  
  //Luetaan painikkeen tila "vanhaksi" tiedoksi
  S1OldState = digitalRead(S1);
  S2OldState = digitalRead(S2);
  //Alustetaan sarjaportti
  Serial.begin(9600);
}
//Muuttuja suodatukselle
#define FILTER 20
void handleS1() {
  //Luetaan painikkeen tila
  int butNewState = digitalRead(S1);
  //Jos uusi tila on erilainen kuin vanha on painikkeen tila muuttunut
  if(butNewState != S1OldState){
    //Jos uusi tila edustaa painettu painiketta on aika reagoida
    if(butNewState == BUTTONPRESSED){
      //Vaihdetaan ledin tilatiedon tila
      if(led1State==LEDOFF){
        led1State=LEDON;
      }else{
        led1State=LEDOFF;
      }
      //Ohjataan ledi tilamuuttujan mukaiseen tilaan
      digitalWrite(LED1, led1State);
    }
    //Suodatetaan värähtelyt sisääntulosta
    delay(FILTER);
  }
  //Päivitetään tilamuuttujan arvo seuraavaa kierrosta varten
  S1OldState=butNewState;
}

void handleS2() {
  //Luetaan painikkeen tila
  int butNewState = digitalRead(S2);
  //Jos uusi tila on erilainen kuin vanha on painikkeen tila muuttunut
  if(butNewState != S2OldState){
    //Jos uusi tila edustaa painettu painiketta on aika reagoida
    if(butNewState == BUTTONPRESSED){
      Serial.println("Morjens");
    }
    //Suodatetaan värähtelyt sisääntulosta
    delay(FILTER);
  }
  //Päivitetään tilamuuttujan arvo seuraavaa kierrosta varten
  S2OldState=butNewState;
}



void loop(){
  handleS1();
  handleS2();
}
