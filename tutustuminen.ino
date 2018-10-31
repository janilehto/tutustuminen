#define LED1 12
#define PAINIKE 5

#define BUTTONPRESSED LOW
#define LEDON LOW
#define LEDOFF HIGH

//Luodaan globaali muuttuja ylläpitämään tietoa ledin tilasta
int led1State=LEDOFF;
//Luodaan globaali muuttuja painikkeen "vanhaa" tilaa varten
int butOldState;

void setup() {
  //Määritetään ledin liitos
  pinMode(LED1, OUTPUT);
  //Ohjataan ledi tilamuuttujan mukaiseen tilaan
  digitalWrite(LED1, led1State);
  //Määritetään painikkeen liitos
  pinMode(PAINIKE, INPUT_PULLUP);
  //Luetaan painikkeen tila "vanhaksi" tiedoksi
  butOldState = digitalRead(PAINIKE);
  //Alustetaan sarjaportti
  Serial.begin(9600);
}
//Muuttuja suodatukselle
#define FILTER 20
void loop() {
  //Luetaan painikkeen tila
  int butNewState = digitalRead(PAINIKE);
  //Jos uusi tila on erilainen kuin vanha on painikkeen tila muuttunut
  if(butNewState != butOldState){
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
  butOldState=butNewState;
}
