/*
 * Blink esimerkkiohjelma esittää Arduino-ympäristön perusrakenteen. Ohjelma ohjaa arduino 
 * levyllä olevaa loistediodia,lediä vuoroin päälle ja pois, jääden hetkeksi pitämään lediä 
 * asetetussa tilassa. 
 */

/* 
 * Vakioilla "tuodaan" fyysinen kytkentä ohjelmaan. Eli levyllä oleva ledi on käytännössä 
 * kytkettynä mikro-ohjaimen liitäntään (pinniin) jonka numero on 13.
 */
#define LED 13

/*
 * setup() funktio ajetaan ainoastaan kun laite käynnistyy. Funktiossa on täten kätevää 
 * konfiguroida laitteen pinnit kytkennän mukaisesti. Tässä ohjelmassa pinni 13 tulee 
 * toimimaan lähtönä, eli mikro-ohjain tulee ohjaamaan pinnille sähköjä päälle ja pois. 
 */
void setup() {
  /*
   * Alla olevalla funktiokutsulla konfiguroidaan pinni 13 lähdöksi (OUTPUT)
   */
  pinMode(LED, OUTPUT);
}
/*
 * Luodaan muuttuja johon tallennetaan millisekuntimäärä jolla valitaan viiveen pituus.
 */
int viive = 1000;
/*
 * loop() funktio tahdittaa Arduinolaitteen toiminnan. Mikro-ohjain lukee joka rivin loop() 
 * funktion sisältä ja suorittaa käskyt järjestyksessä ylhäätä alas. Kun kaikki
 * käskyt on suoritettu aloittaa laite käskyjen suorittamisen loop() funktion alusta.
 */
void loop(){
  /*
   * digitalWrite() funktiokutsulla vaikutetaan tietyn pinnin jännitteeseen. Alla oleva 
   * funktiokutsu nostaa pinnin 13 jännitteen viiteen volttiin. Tämä jännite saa 
   * ledin syttymään.
   */
   digitalWrite(LED, HIGH);
   /*
    * delay() funktiokutsulla saadaan laite pysähtymään halutuksi ajaksi. Haluttu 
    * aika välitetään delay() funktiolle parametrillä, sulkujen välissä.
    */
    delay(viive);
    // Sammutetaan ledi
    digitalWrite(LED, LOW);
    // Pysäytetään laite
    delay(viive);
}
