#define m1b 2 //motor 1 forword   (N1)
#define m1f 3 //motor 1 backword  (N2)
#define m2b 4 //motor 2 forword   (N3)
#define m2f 5 //motor 2 backword  (N4)

#define m1e 9   //motor 1 enable  (ENA)
#define m2e 10  //motor 2 enable  (ENB)

int valch1=0,valch2=0;
int chanel[]={A0,A1};
String range1,range2;

void setup() {
  Serial.begin(115200);
  for(int i=0;i<11;i++){
    pinMode(i,OUTPUT);
  }
}


void loop() {
  
  int valch1=pulseIn(chanel[0],HIGH);
  
  if(valch1<900){
    valch1=0;
    range1="";
  }
  else{
    if(valch1<1455){
      valch1=map(valch1,990,1450,255,1);
      range1="low";
    }
    else if(1545<valch1<2005){
      valch1=map(valch1,1550,2000,1,255);
      range1="hi";
    }
  }
  if(valch1<1){
    valch1=0;
    range1="";
  }
/////////////////////////////////
  int valch2=pulseIn(chanel[1],HIGH);
  
  if(valch2<900){
    valch2=0;
    range2="";
  }
  else{
    if(valch2<1455){
      valch2=map(valch2,990,1450,255,1);
      range2="low";
    }
    else if(1545<valch2<2005){
      valch2=map(valch2,1550,2000,1,255);
      range2="hi";
    }
  }
  if(valch2<1){
    valch2=0;
    range2="";
  }

  
  if(range1=="hi"){
    digitalWrite(m1f,LOW);
    digitalWrite(m2f,HIGH);
    digitalWrite(m1b,HIGH);
    digitalWrite(m2b,LOW);
    analogWrite(m1e,valch1);
    analogWrite(m2e,valch1);
  }
  else if(range1=="low"){
    digitalWrite(m1f,HIGH);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,HIGH);
    analogWrite(m1e,valch1);
    analogWrite(m2e,valch1);
  }
  
  if(range2=="hi"){
    digitalWrite(m1f,HIGH);
    digitalWrite(m2f,HIGH);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,LOW);
    analogWrite(m1e,valch2);
    analogWrite(m2e,valch2);
    
  }
  else if(range2=="low"){
    digitalWrite(m1f,LOW);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,HIGH);
    digitalWrite(m2b,HIGH);
    analogWrite(m1e,valch2);
    analogWrite(m2e,valch2);
  }
   if(range1=="" && range2==""){
    carStop();
   }
  
  Serial.print(valch1);
  Serial.print("  ");
  Serial.print(range1);
  Serial.print("  ");
  Serial.print(valch2);
  Serial.print("  ");
  Serial.print(range2);
  Serial.println("  ");
}
void carStop(){
  digitalWrite(m1f,LOW);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,LOW);
    analogWrite(m1e,0);
    analogWrite(m2e,0);
}

