#include "capteur.h"
#include "controleActionneur.h"
#include "horodatageConsomation.h"
#include "gestionMaison.h"
#include <avr/io.h>
#include <avr/interrupt.h>

Maison maison;

void initTimer2 (void);

unsigned short interruptePinCompteur = 3; //Variable Compteur

unsigned short flagCompteurEnergie=1;

unsigned short flagCompteurTimer=0;

volatile unsigned int cpt=0;

unsigned short interruptBouton=2;

//bool boutonEtteint=true;

//bool boutonAllumer=false; 

void setup(){
  
  initSerial();
  initTimer2();
  initActionneur();
  initHorodatageConsomation();
  initCapteur();
  
  //Setup Compteur d'energie interruption
  pinMode(interruptePinCompteur, INPUT_PULLUP);                             
  attachInterrupt(digitalPinToInterrupt(interruptePinCompteur), interruptionCompteur, LOW);
  
  //setup bouton alarme interruption
  pinMode(interruptBouton, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptBouton), interruptionBouton, RISING); 
}

void loop(){

/*******************Le drapeau 1 du Timer1 se "lève" toute les 5 sec**************************/
    if (flagCompteurTimer==1){
        maison.temperature=capteurTemperature(); //récupération de la température dans un attribue
        maison.humidite=capteurHumidite();
        maison.etatRadiateur=etatThermostat();        
        maison.emissionTrame(); //emission de la trame pour le serveur WEB et la tablette              
        flagCompteurTimer=0;  //rermise du drapeau 1 a 0 "on baisse le drapeau".      
    }

/*******************Le drapeau 2 du Timer1 se "lève" toute les 10 sec**************************/    
    if (flagCompteurTimer==2){
        envoieSMS(maison.incendie, maison.mouvement); //émission du sms d'alerte si alerte
        maison.qualiteAir=capteurQualiteAir();
        maison.temperature=capteurTemperature();
        maison.humidite=capteurHumidite();
        maison.etatRadiateur=etatThermostat();
        maison.luminosite=capteurLuminosite();
        maison.incendie = false; //on remet les valeurs des attribue d'alerte a l'état passif
        maison.mouvement = false;        
        maison.emissionTrame();//emission de la trame pour le serveur WEB et la tablette         
        flagCompteurTimer=0;  //rermise du drapeau 2 a 0 "on baisse le drapeau".  
    }

    
  maison.lectureTablette(); //on récupère les valeurs valeurs envoyer par la tablette 

/**************************Partie sécurité************************************************/

  if (maison.incendie == false){
      maison.incendie=capteurIncendie();
  }

  if (maison.alarme==true){
      if (maison.mouvement == false){
      maison.mouvement=capteurMouvement();
      }
  }
  
 /******************Controle des actionneur en fonction des commande de l'utilisateur******************/ 
 
  controleThermostat(maison.radiateurMode, maison.temperature, maison.temperatureUtilisateur, maison.radiateur);  
  maison.volet1=controleVolet1(maison.volet1Etat, maison.voletMode);
  maison.volet2=controleVolet2(maison.volet2Etat, maison.voletMode);
  maison.lumiere=controleLumiere(maison.lumiereEtat);  

/*******************Le drapeau 1 de l'interruption compteur**************************/

  if (flagCompteurEnergie==1){
        maison.consomation=consomation();
        maison.annee=annee();
        maison.mois=mois();
        maison.jour=jour();
        maison.heure=heure();
        maison.minutes=minutes();
        maison.seconde=seconde();
        horodatage(maison.consomation);             
        flagCompteurEnergie=0;
  }
}
/*******************************************/
void interruptionBouton(){
  /*if (boutonEtteint==true){
    boutonEtteint=false;
    boutonAllumer=true;
    maison.alarme=true;
    Serial.println("allumer");
  }
  else{
    boutonEtteint=true;
    boutonAllumer=false;
    maison.alarme=false;
    Serial.println("etteint");
  }*/
   if (maison.alarme==true){
    maison.alarme=false;
    Serial.println("eteint");
  }
  else{
    maison.alarme=true;
    Serial.println("allume");
  }

}

void interruptionCompteur(){

  delay(50);
  if (digitalRead(interruptePinCompteur)==0){
    flagCompteurEnergie=1;
    while(digitalRead(interruptePinCompteur)!=1);  
  }
}

void initTimer2 (){
  //config timer2
  TCCR2A=0x00;
  TCCR2B|=(1<<CS22)|(1<<CS21)|(1<<CS20);
  TIMSK2|=(1<<TOIE2);
  sei();
}

ISR(TIMER2_OVF_vect){
   cpt++;
   if (cpt==305){
      flagCompteurTimer=1;
   }
   if (cpt==610){
      flagCompteurTimer=2;
      cpt=0;
   }
}

